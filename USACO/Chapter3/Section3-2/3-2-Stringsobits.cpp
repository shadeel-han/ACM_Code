/*
ID: j9010311
PROG: kimbits
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    
    unsigned int k;
    int i, j, need, dp[32][32], len, bit, m;
    char out[32];
    
    while( scanf("%d %d %u", &len, &bit, &k)!=EOF ){
        
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for( i=1; i<len; ++i ){
            dp[i][0] = 1;
            for( j=1; j<=bit; ++j )
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
        
        for( i=0,j=len,--k; i<len; ++i,--j ){
            
            for( m=0,need=0; m<=bit; ++m )
                need += dp[j-1][m];
            
            if( k < need )
                out[i] = '0';
            else{
                out[i] = '1';
                k -= need;
                --bit;
            }
        }
        
        out[len] = 0;
        puts(out);
    }
    
    return 0;
}
