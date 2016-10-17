#include <stdio.h>

#define MAXN 11
#define MAXK 101
int dp[MAXN][MAXK][MAXK]={{{0}}};

int RecursiveDP(int n, int low, int high){
	if( dp[n][low][high] )  return dp[n][low][high];
	if( n==1 )  	return dp[n][low][high] = ((low+high)*(high-low+1))>>1;
	if( low==high ) return dp[n][low][high] = low;
	if( low>high )  return 0;
	
	int i, a, b, get, ans=5050;
	for(i=low; i<=high; i++){
        a = RecursiveDP(n-1, low, i-1);	/* explode */
		b = RecursiveDP(n, i+1, high);	/* not explode */
		get = ((a>b)?(a):(b)) + i;      /* always go to worst conditions */
		ans = (ans>get)?(get):(ans);    /* but we try to minimize the worst result */
	}
	return dp[n][low][high] = ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, n, k;
	scanf("%d", &c);
	while( c-- ){
		scanf("%d %d", &n, &k);
		printf("%d\n", RecursiveDP(n,1,k));
	}
	return 0;
}
