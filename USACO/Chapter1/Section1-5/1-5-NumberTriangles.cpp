/*
ID: j9010311
PROG: numtri
LANG: C++
*/

#include <cstdio>

using namespace std;

int dp[1001][1001], road[1001][1001];

int main(){
    
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    
    int row, i, j, ans;
    
    while(scanf("%d",&row)!=EOF){
       ans = 0;
       for( i=1; i<=row; i++ )
            for( j=1; j<=i; j++ )
                 scanf("%d", &road[i][j]);
    
       dp[1][1] = road[1][1];
       for( i=2; i<=row; i++ ){
            dp[i][1] = dp[i-1][1] + road[i][1];
            dp[i][i] = dp[i-1][i-1] + road[i][i];
       }
       for( i=3; i<=row; i++ )
            for( j=2; j<i; j++ ){
                 if( dp[i-1][j-1]>dp[i-1][j] )
                     dp[i][j] = dp[i-1][j-1]+road[i][j];
                 else
                     dp[i][j] = dp[i-1][j]+road[i][j];
            }
       for( i=1; i<=row; i++ )
            if( dp[row][i] > ans )
                ans = dp[row][i];
       printf("%d\n", ans);
    }
    return 0;
}
