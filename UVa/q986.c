#include <stdio.h>
#define MAXN 41

int dp[MAXN][MAXN][MAXN][MAXN][2] = {{{{{0}}}}};  /* 0:downwards, 1:upwards */

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, p, q, n=20, r, k;
	for(i=1; i<20; i++) dp[0][0][0][i][0] = 1;
	for(i=0; i<(n*2); i++)for(j=0; j<=i && j<=(n*2-i); j++){
		/* become upwrads */
		for(p=0; p<20; p++)for(q=0; q<20; q++){
            dp[i+1][j+1][p][q][1] += dp[i][j][p][q][0];
            dp[i+1][j+1][p][q][1] += dp[i][j][p][q][1];
		}
		/* become downwards */
		if( j ){
			for(p=0; p<20; p++)for(q=0; q<20; q++){
			    dp[i+1][j-1][p][q][0] += dp[i][j][p][q][0];
			    if( q!=j )  dp[i+1][j-1][p][q][0] += dp[i][j][p][q][1];
			    else        dp[i+1][j-1][p+1][j][0] += dp[i][j][p][j][1];
			}
		}
	}
	while( scanf("%d %d %d", &n, &r, &k)!=EOF )
		printf("%d\n", dp[n*2][0][r][k][0]);
	return 0;
}
