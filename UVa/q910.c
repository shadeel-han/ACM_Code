#include <stdio.h>
#include <string.h>

#define MAXN 27
#define MAXM 31
int rf[MAXN], rt[MAXN], sp[MAXN], dp[MAXM][MAXN];

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, n, m;
	char a, b, c, d;
	while( scanf("%d\n", &n)!=EOF ){
		for(i=0; i<n; i++){
			scanf("%c %c %c %c\n", &a, &b, &c, &d);
			j = a - 'A';        sp[j] = (d=='x')?(1):(0);
			rf[j] = b - 'A';    rt[j] = c - 'A';
		}
		scanf("%d", &m);
		memset(dp, 0, sizeof(dp));  dp[0][0] = 1;
		for(i=1; i<=m; i++)for(j=0; j<n; j++){
			dp[i][rf[j]] += dp[i-1][j];
			dp[i][rt[j]] += dp[i-1][j];
		}
		for(i=0, j=0; j<n; j++)
		if( sp[j] ) i += dp[m][j];
		printf("%d\n", i);
	}
	return 0;
}
