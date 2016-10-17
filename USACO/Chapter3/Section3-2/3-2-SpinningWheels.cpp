/*
ID: j9010311
PROG: spin
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

char dp[360][360];

int main(){
    
    freopen("spin.in","r",stdin);
    freopen("spin.out","w",stdout);
    
    int i, j, m, n, t;
    int speed[5], num[5], pos[5][5], ex[5][5];
    
    while( scanf("%d %d", &speed[0], &num[0])!=EOF ){
        
        for( i=0; i<num[0]; ++i )
            scanf("%d %d", &pos[0][i], &ex[0][i]);
        
        for( i=1; i<5; ++i ){
            scanf("%d %d", &speed[i], &num[i]);
            for( j=0; j<num[i]; ++j )
                scanf("%d %d", &pos[i][j], &ex[i][j]);
        }

        memset(dp,0,sizeof(dp));
        t = 0;
        while( t<360 ){
            for( i=0; i<5; ++i )
            for( m=0; m<num[i]; ++m ){
                for( n=0; n<=ex[i][m]; ++n )
                    ++dp[t][ (pos[i][m]+n)%360 ];
                pos[i][m] = (pos[i][m] + speed[i]) % 360;
            }
            for( j=0; j<360; ++j )
                if( dp[t][j]==5 )
                    break;
            if( j<360 ) break;
            ++t;
        };
        
        if( t==360 )    puts("none");
        else            printf("%d\n", t);
    }
    
    return 0;
}
