#include <cstdio>

using namespace std;

typedef struct{
    int num;
    bool have;
}APPLE;
APPLE apple[100001];
int point[100001];

void change( int index, int flag ){
    
    if( flag==1 )
    while( index ){
        ++apple[index].num;
        index = point[index];
    }
    else
    while( index ){
        --apple[index].num;
        index = point[index];
    }
}

int main(){
    
    int i, j, num, from, to;
    char w;
    
    point[1] = 0;
    while( scanf("%d", &num)!=EOF ){
        
        for( i=1; i<=num; ++i ){
            apple[i].num = 0;
            apple[i].have = true;
        }
        apple[1].num = 1;
        
        for( i=1; i<num; ++i ){
            scanf("%d %d", &to, &from);
            point[from] = to;
        }
        
        for( i=num; i>1; --i ){
            change(i,1);
        }
        
        scanf("%d", &num);
        for( i=0; i<num; ++i ){
            getchar();
            w = getchar();
            if( w=='C' ){
                scanf("%d", &j);
                if( apple[j].have ){
                    change(j,2);
                    apple[j].have = false;
                }
                else{
                    change(j,1);
                    apple[j].have = true;
                }
            }
            else{
                scanf("%d", &j);
                printf("%d\n", apple[j].num);
            }
        }
    }
    
    return 0;
}
