#include <cstdio>
#include <algorithm>

using namespace std;


int tree[300001];
int data[100001], lindex[100001], rindex[100001];
int right, left, fre;

int create( int pos, int start, int end ){
    
    if( start==end ){
        tree[pos] = 1;
        return tree[pos];
    }
    
    int mid = (start+end)>>1;
    int tmp1, tmp2, tmp3;
    tmp1 = create(pos*2,start,mid);
    tmp2 = create(pos*2+1,mid+1,end);
    
    tmp3 = min(end,rindex[mid]) - max(start,lindex[mid]) + 1;
    if( tmp3 > tmp1 )   tmp1 = tmp3;
    if( tmp1 > tmp2 )   tree[pos] = tmp1;
    else                tree[pos] = tmp2;

    return tree[pos];
}

void traverse( int pos, int start, int end ){
    
    if( left>end || right<start )   return;
    
    if( left<=start && right>=end ){
        if( tree[pos] > fre )
            fre = tree[pos];
        return ;
    }
    
    int mid = (start+end)>>1, midnum;
    traverse( pos*2, start, mid );
    traverse( pos*2+1, mid+1, end );
    
    /* for the condintion that the most number is neither in the two intervals above */
    midnum = min(right,rindex[mid]) - max(left,lindex[mid]) + 1;
    if( midnum > fre )  fre = midnum;
    
}

int main(){
    
    int num, que, i, j, mem;
    
    while( scanf("%d", &num)!=EOF ){
        
        if( !num ) break;
        scanf("%d", &que);
        
        for( i=1; i<=num; ++i )
            scanf("%d", &data[i]);
        
        for( i=2,j=1,mem=data[1],lindex[1]=1; i<=num; ++i ){
            if( data[i]!=mem ){
                mem = data[i];
                j = i;
            }
            lindex[i] = j;
        }
        
        for( i=num-1,j=num,mem=data[num],rindex[num]=num; i>=0; --i ){
            if( data[i]!=mem ){
                mem = data[i];
                j = i;
            }
            rindex[i] = j;
        }
        
        /*for( i=1; i<=num; ++i )
        printf("%d ", lindex[i]);
        putchar('\n');
        for( i=1; i<=num; ++i )
        printf("%d ", rindex[i]);
        putchar('\n');*/
        
        create(1,1,num);
        
        for( i=0; i<que; ++i ){
            scanf("%d %d", &left, &right);
            fre = 0;
            traverse(1,1,num);
            printf("%d\n", fre);
        }
    }
    return 0;
}

