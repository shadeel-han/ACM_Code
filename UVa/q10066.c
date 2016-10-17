#include <stdio.h>
#include <string.h>

#define MAXN 101

int a[MAXN], b[MAXN], dp[MAXN][MAXN]={0};

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, m, i, j, c=0;

	while( scanf("%d %d", &n, &m) && n ){
        for(i=1; i<=n; i++)	scanf("%d", &a[i]);
        for(i=1; i<=m; i++)	scanf("%d", &b[i]);
		/*memset(dp, 0, sizeof(dp));*/
		for(i=1; i<=n; i++)for(j=1; j<=m; j++){
			if( a[i]==b[j] )					dp[i][j] = dp[i-1][j-1] + 1;
			else if( dp[i-1][j] > dp[i][j-1] )	dp[i][j] = dp[i-1][j];
			else                                dp[i][j] = dp[i][j-1];
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++c, dp[n][m]);
	}

	return 0;
}
