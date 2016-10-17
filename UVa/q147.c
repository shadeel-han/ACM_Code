#include <stdio.h>
#define MAXN 30001
long long int dp[MAXN]={0};

void CoinChange(void){
	int i, j, d[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
	dp[0] = 1;
	for(i=0; i<11; i++)for(j=d[i]; j<MAXN; j+=5)   dp[j] += dp[j-d[i]];
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int a, b;
	CoinChange();
	while( scanf("%d.%d", &a, &b) && (a+b) ){
		printf("%3d.%02d%17lld\n", a, b, dp[a*100+b]);
	}
	return 0;
}
