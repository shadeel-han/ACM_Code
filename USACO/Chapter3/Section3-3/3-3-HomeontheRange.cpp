/*
ID: j9010311
PROG: range
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

char field[250][252];
int dp[250][250];

int main(){
    
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    
    int i, j, k, m, n, num, tmp;
    int ans[250];
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%s", &field[i]);
        
        for( i=0; i<num; ++i ){
            if( field[0][i]=='1' )  dp[0][i] = 1;
            else                    dp[0][i] = 0;
            if( field[i][0]=='1' )  dp[i][0] = 1;
            else                    dp[i][0] = 0;
        }
        
        for( i=1; i<num; ++i )
            for( j=1; j<num; ++j ){
                tmp = (i>j)?(j):(i);
                tmp = (tmp>dp[i-1][j-1])?(dp[i-1][j-1]):(tmp);
                for( m=0; m<=tmp; ++m )
                    if( field[i][j-m]=='0' || field[i-m][j]=='0' )
                        break;
                dp[i][j] = m;
            }
        
        memset(ans,0,sizeof(ans));
        for( i=1; i<num; ++i )
            for( j=1; j<num; ++j )
                for( k=0; k<dp[i][j]; ++k )
                    ++ans[k];
        
        for( i=1; i<num; ++i )
            if( ans[i] )
                printf("%d %d\n", i+1, ans[i]);
        
    }
    
    return 0;
}
