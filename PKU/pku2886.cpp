#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
    int start;
    int end;
    int cap; /*it's the number of available numbers in the interval*/
}TREE;
TREE tree[1500001];

typedef struct{
    char name[12];
    int num;
} DATA;
DATA input[500001];

/* for prime and F(p), F(p) is stored in data[p] */
int data[500001]={0}, most[500001];
bool isprime[500001];
int prime[130], node[100], card, child;

int create( int pos, int start, int end ){
    
    if( start==end ){
        tree[pos].cap = 1;
        tree[pos].start = start;
        tree[pos].end = end;
        return tree[pos].cap;
    }
    else{
        int mid = (start+end)>>1;
        tree[pos].start = start;
        tree[pos].end = end;
        tree[pos].cap = create(2*pos,start,mid) + create(2*pos+1,mid+1,end);
        return tree[pos].cap;   
    }
}

void jump( int pos, int index ){
    
    // decrease the availibility
    --tree[pos].cap;
    
    if( tree[pos].start==tree[pos].end ){
        child = tree[pos].start;
        card = input[tree[pos].start].num;
        return;
    }
    
    int next=pos<<1;
    if( tree[next].cap >= index )   jump(next,index);
    else                            jump(next+1,index-tree[next].cap);
    
    /* the reason for using '>=' : it has to guarantee that
       there is still enough children from 1~index-1 to jump */
    
}


int main(){
    
    int num, i, j, primenum=1, nodenum, tmp, start, limit;
    
    ////////////////////////////////////////////////////////
    memset(isprime,true,sizeof(isprime));
    for( i=4; i<500001; i+=2 )
         isprime[i] = false;
    prime[0] = 2;
    for( i=3; i<500001; i+=2 )
         if( isprime[i] )
             for( j=i<<1; j<500001; j+=i )
                  isprime[j] = false;
    for( i=3; i<710; i+=2 )
        if( isprime[i] )
            prime[primenum++] = i;
            
    for( i=2,data[1]=1; i<500001; ++i ){
        if( isprime[i] ){
            data[i] = 2;
            continue;
        }
        for( j=0,nodenum=-1,tmp=i; prime[j]<tmp; ++j ){
            if( isprime[tmp] )  break;
            if( tmp%prime[j] )  continue;
            else{
                ++nodenum;
                node[nodenum] = 1;
            }
            while( tmp%prime[j]==0 ){
                tmp /= prime[j];
                ++node[nodenum];
            }
        }
        if( tmp != 1 )   node[++nodenum] = 2;
        for( j=0,tmp=1; j<=nodenum; ++j )   tmp *= node[j];
        data[i] = tmp;
    }
    //////////////////////////////////////////////////////////
    
    for( i=1,tmp=0; i<500001; ++i ){
        if( data[i] > data[tmp] )
            tmp = i;
        most[i] = tmp;
    }
    
    while( scanf("%d %d", &num, &start)!=EOF ){
        
        limit = most[num];
        for( i=1; i<=num; ++i )
            scanf("%s %d", &input[i].name, &input[i].num);
        
        create(1,1,num);
        
        for( i=1,j=num; i<=limit; ++i,--j ){
            jump(1,start);
            if( j!=1 ){
                //printf("%d\n", card);
                tmp = card;
                card %= (j-1);
                if( card>=0 && tmp>0 )   --card;
                start = (start + card)%(j-1);
                if( start <= 0 )    start += (j-1);
            }
        }
        
        printf("%s %d\n", input[child].name, data[limit]);
        
    }
    
    return 0;
}
