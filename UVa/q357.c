#include <stdio.h>

#define MAXN 30001
long long int dp[MAXN] = {0};

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
	    if( dp[n]==1 )  printf("There is only 1 way to produce %d cents change.\n", n);
	    else            printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
	return 0;
}
