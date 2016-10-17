/*
ID: j9010311
PROG: gift1
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    
    char name[11][16], to[16];
    int get[11], initial[11];
    int i, j, k, num, peo, give;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=1; i<=num; ++i )
            scanf("%s", &name[i]);
        
        memset(get,0,sizeof(get));
        for( i=1; i<=num; ++i ){
            scanf("%s", &to );
            for( peo=1; peo<num; ++peo ){
                if( !strcmp(to,name[peo]) )
                    break;
            }
            
            scanf("%d %d", &initial[peo], &k);
            if( k ){
                give = initial[peo] / k;
                get[peo] += initial[peo] % k;
                for( j=0; j<k; ++j ){
                    scanf("%s", &to );
                    for( peo=1; peo<num; ++peo ){
                        if( !strcmp(to,name[peo]) )
                            break;
                    }
                    get[peo] += give;
                }
            }
        }
        
        for( i=1; i<=num; ++i )
            printf("%s %d\n", name[i], get[i]-initial[i]);
        
    }
    
    return 0;
}
