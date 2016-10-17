#include <cstdio>

using namespace std;

typedef struct{
    int start;
    int end;
    int cap; /*it's the capability of storing numbers in the interval*/
}TREE;
TREE tree[600001];

typedef struct{
    int index;
    int num;
} DATA;
DATA data[200001];
int ans[200001];

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

void putdata( int pos, int index, int num ){
    
    // decrease the capability
    --tree[pos].cap;
    
    if( tree[pos].start==tree[pos].end ){
        ans[tree[pos].start] = num;
        return;
    }
    
    int next=pos<<1;
    if( tree[next].cap > index )    putdata(next,index,num);
    else                            putdata(next+1,index-tree[next].cap,num);
    
    /* the reason for using '>' : it has to guarantee that
       there is still enough space for putting 0~index-1 numbers */
    
}


int main(){
    
    int num, i;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=1; i<=num; ++i )
            scanf("%d %d", &data[i].index, &data[i].num);
        
        create(1,1,num);
        
        for( i=num; i>0; --i )
            putdata(1,data[i].index,data[i].num);
        
        for( i=1; i<num; ++i )
            printf("%d ", ans[i]);
        printf("%d\n", ans[num]);
        
    }
    
    return 0;
}
