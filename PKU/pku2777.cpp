#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    char work;
    int fro;
    int end;
    int col;
}NODE;
NODE node[100001];

typedef struct{
    int start;
    int end;
    int num;
}TREE;
TREE tree[300001];
int total;
bool exist[31];

void initial( int pos, int start, int end ){
    
    if( start==end ){
        tree[pos].start = start;
        tree[pos].end = end;
        tree[pos].num = 0;
        return;
    }
    
    tree[pos].start = start;
    tree[pos].end = end;
    tree[pos].num = 0;
    int mid = (start+end)>>1;
    initial(pos*2,start,mid);
    initial(pos*2+1,mid+1,end);
}

void setting( int pos, int left, int right, int num ){
    
    if( left>tree[pos].end || right<tree[pos].start )   return;
    if( tree[pos].num==num )    return;
    
    if( left<=tree[pos].start && right>=tree[pos].end ){
        tree[pos].num = num;
        return;
    }
    
    int dou = pos<<1;
    if( tree[pos].num ){
        tree[dou].num = tree[pos].num;
        tree[dou+1].num = tree[pos].num;
        tree[pos].num = 0;
    }
    
    setting( dou,left,right,num );
    setting( dou+1,left,right,num );

}

void traverse( int pos, int left, int right ){
    
    if( left>tree[pos].end || right<tree[pos].start )   return;
    
    if( tree[pos].num ){
        if( exist[tree[pos].num] ){
            ++total;
            exist[tree[pos].num] = false;
        }
        return;
    }
    
    traverse(2*pos,left,right);
    traverse(2*pos+1,left,right);
    
}

int main(){
    
    int i, j, opnum, len, colornum, tmp, index, mem; 
    
    
    while( scanf("%d %d %d", &len, &colornum, &opnum)!=EOF ){

        for( i=0; i<opnum; ++i ){
            getchar();
            node[i].work = getchar();
            if( node[i].work=='C' ) scanf("%d %d %d", &node[i].fro, &node[i].end, &node[i].col);
            else                    scanf("%d %d", &node[i].fro, &node[i].end);
            if( node[i].fro > node[i].end ){
                tmp = node[i].end;
                node[i].end = node[i].fro;
                node[i].fro = tmp;
            }
        }
        
        initial(1,1,len);
        tree[1].num = 1;
        
        for( i=0; i<opnum; ++i ){
            if( node[i].work=='C' ){
                setting(1,node[i].fro,node[i].end,node[i].col);
            }
            else{
                for( j=1,total=0; j<=colornum; ++j )
                    exist[j] = true;
                traverse(1,node[i].fro,node[i].end);
                printf("%d\n", total);
            }
        }
        
    }
    return 0;
}
