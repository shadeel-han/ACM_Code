#include <stdio.h>
#define MAXN 7490

int dp[MAXN]={0};

void CoinChange(void){
	int i, j, coin[5]={1,5,10,25,50};
	dp[0] = 1;
	for(i=0; i<5; i++)for(j=coin[i]; j<MAXN; j++)
	    dp[j] += dp[j-coin[i]];
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n;
	CoinChange();
	while( scanf("%d", &n)!=EOF )
	    printf("%d\n", dp[n]);
	return 0;
}
