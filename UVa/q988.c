#include <stdio.h>
#include <string.h>

#define MAXN 101

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, k, n, c=0, dp[MAXN], ans;
	
	while( scanf("%d", &n)!=EOF ){
		if( c++ )   putchar('\n');
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;	ans = 0;
		for(i=0; i<n; i++){
			scanf("%d", &j);
			if( !j )    ans += dp[i];
			else while( j-- ){
				scanf("%d", &k);
				dp[k] += dp[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
