#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct{
    int x;
    int y;
}NODE;
NODE node[50];
NODE base;

int cmp( const void* a, const void* b ){
    
    NODE* arg1 = (NODE*) a;
    NODE* arg2 = (NODE*) b;
    
    return -((arg1->x)*(arg2->y)-(arg1->y)*(arg2->x));
    
}

int main(){
    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int i, j, num=-1, x, y;
    
    base.x = 0;
    base.y = 0;
    while( scanf("%d %d", &x, &y)!=EOF ){
        if( x && y ){
            node[++num].x = x;
            node[num].y = y;
        }
    }
    
    qsort(node,num+1,sizeof(NODE),cmp);
    puts("(0,0)");
    for( i=0; i<=num; ++i )
        printf("(%d,%d)\n", node[i].x, node[i].y);
    
    return 0;
}
