#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    int maxx;
    int minn;
}TREE;

TREE tree[150001];
int data[50001];
int mi, ma, right, left;

TREE create( int pos, int start, int end ){
    
    if( start==end ){
        tree[pos].maxx = data[start];
        tree[pos].minn = data[start];
        return tree[pos];
    }
    
    int mid = (start+end)>>1;
    TREE tmp1, tmp2;
    tmp1 = create(pos*2,start,mid);
    tmp2 = create(pos*2+1,mid+1,end);
    
    if( tmp1.maxx > tmp2.maxx ) tree[pos].maxx = tmp1.maxx;
    else                        tree[pos].maxx = tmp2.maxx;
    if( tmp1.minn < tmp2.minn ) tree[pos].minn = tmp1.minn;
    else                        tree[pos].minn = tmp2.minn;
    return tree[pos];
}

void traverse( int pos, int start, int end ){
    
    if( left>end || right<start )   return;
    
    if( left<=start && right>=end ){
        if( tree[pos].maxx > ma ) ma = tree[pos].maxx;
        if( tree[pos].minn < mi ) mi = tree[pos].minn;
        return ;
    }
    
    int mid = (start+end)>>1;
    traverse( pos*2, start, mid );
    traverse( pos*2+1, mid+1, end );
    
}

int main(){
    
    int num, que, i;
    
    while( scanf("%d %d", &num, &que)!=EOF ){
        
        for( i=1; i<=num; ++i )
            scanf("%d", &data[i]);
        
        create(1,1,num);
        
        for( i=0; i<que; ++i ){
            scanf("%d %d", &left, &right);
            ma = 0;
            mi = 1000000000;
            traverse(1,1,num);
            printf("%d\n", ma-mi);
        }
    }
    return 0;
}

