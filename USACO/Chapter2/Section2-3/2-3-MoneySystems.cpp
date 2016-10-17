/*
ID: j9010311
PROG: money
LANG: C++
*/

#include <cstdio>

using namespace std;

long long int dp[10001];

int main(){
    
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    
    int coin[25], i, j, num, total;
    
    while( scanf("%d %d", &num, &total)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%d", &coin[i]);
        
        for( i=0; i<=total; i++ )
        if( i%coin[0]==0 )
            dp[i] = 1;
        for( i=1; i<num; i++ )
            for( j=coin[i]; j<=total; j++ )
                dp[j] += dp[j-coin[i]];
        printf("%lld\n", dp[total]);
    }
    
    return 0;
}
