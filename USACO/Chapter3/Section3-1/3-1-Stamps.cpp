/*
ID: j9010311
PROG: stamps
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

int need[3000000];
int sta[200];

int main(){
    
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    
    int i, j, can, num, tmp;
    
    while( scanf("%d %d", &can, &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%d", &sta[i]);
        
        memset(need,-1,sizeof(need));
        need[0] = 0;
        for( i=0; i<3000000; ++i ){
            
            if( need[i]==-1 || need[i]>can )   break;
            
            for( j=0; j<num; ++j ){
                tmp = i + sta[j];
                if( need[tmp]==-1 )                 need[tmp] = need[i] + 1;
                else if( need[tmp] > need[i]+1 )    need[tmp] = need[i] + 1;
            }
        }
        
        printf("%d\n", i-1);
    }
    
    return 0;
}
