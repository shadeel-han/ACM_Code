#include <stdio.h>
#include <string.h>
#define MAXN 51

int len[MAXN], dp[MAXN][MAXN];

int RecursiveDP(int f, int e){
	if( dp[f][e]>(-1) )	return dp[f][e];
	if( (e-f)<=1 )      return dp[f][e] = 0;
	int i, j, gain=2100000000;
	for(i=f+1; i<e; i++){
		j = RecursiveDP(f,i);
		if( j >= gain )  break;
		j += RecursiveDP(i,e);
		if( gain > j )	gain = j;
	}
	return  dp[f][e] = gain+(len[e]-len[f]);
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, n;
	len[0] = 0;
	while( scanf("%d", &j) && j ){
		scanf("%d", &n);    len[n+1] = j;
		for(i=1; i<=n; i++) scanf("%d", &len[i]);
		memset(dp, -1, sizeof(dp));
		printf("The minimum cutting is %d.\n", RecursiveDP(0,n+1));
	}
	return 0;
}
