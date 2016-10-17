#include <stdio.h>
#include <string.h>

#define MAXN 21

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, i, j, ord[MAXN], stu[MAXN], dp[MAXN][MAXN]={0};
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &j);    ord[j] = i;
	}
	while( scanf("%d", &j)!=EOF ){
        stu[j] = 1;
        for(i=2; i<=n; i++){
			scanf("%d", &j);    stu[j] = i;
        }
		/*memset(dp, 0, sizeof(dp));*/
		for(i=1; i<=n; i++)for(j=1; j<=n; j++){
			if( ord[i]==stu[j] )				dp[i][j] = dp[i-1][j-1] + 1;
			else if( dp[i-1][j] > dp[i][j-1] )	dp[i][j] = dp[i-1][j];
			else                                dp[i][j] = dp[i][j-1];
		}
		printf("%d\n", dp[n][n]);
	}

	return 0;
}
