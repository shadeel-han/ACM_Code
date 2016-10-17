#include <stdio.h>
#include <string.h>

#define MAXN 602
#define MAXK 301

int dis[MAXN]={0}, dp[MAXK][MAXN];

int RecursiveDP(int k, int start, int n){
	if( dp[k][start] )  return dp[k][start];
	if( !k )    return dp[k][start] = dis[n]-dis[start];
	
	int i, a, b, maxx, ans=2100000000;
	for(i=start+1; i<=(n-k); i++){
		a = dis[i] - dis[start];
		if( a > ans )   break;			/* stop recursive when today's distance exceeds overall maximum */
		b = RecursiveDP(k-1, i, n);
		maxx = (a>b)?(a):(b);
		ans = (ans>maxx)?(maxx):(ans);
	}
	return dp[k][start] = ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, n, k;
	while( scanf("%d %d", &n, &k)!=EOF ){
		for(i=1; i<=(n+1); i++){
            scanf("%d", &dis[i]);   dis[i] += dis[i-1];
		}
		memset(dp, 0, sizeof(dp));
		printf("%d\n", RecursiveDP(k,0,n+1));
	}
	return 0;
}
