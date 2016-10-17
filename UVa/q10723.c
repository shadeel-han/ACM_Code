#include <stdio.h>
#include <string.h>
#define MAXN 35

int LCS[MAXN][MAXN]={{0}}, pi[MAXN][MAXN];
unsigned int dp[MAXN][MAXN];
char a[MAXN], b[MAXN];

void SolveLCS(int la, int lb){
	int i, j;
	for(i=1; i<=la; i++)for(j=1; j<=lb; j++){
		if( a[i]==b[j] )    				LCS[i][j] = LCS[i-1][j-1] + 1, pi[i][j] = 0;
		else if( LCS[i-1][j]==LCS[i][j-1] )	LCS[i][j] = LCS[i][j-1], pi[i][j] = 2;
		else if( LCS[i-1][j]<LCS[i][j-1] )	LCS[i][j] = LCS[i][j-1], pi[i][j] = 1;
		else                                LCS[i][j] = LCS[i-1][j], pi[i][j] = 3;
	}
}

void SolveDP(int la, int lb){
	int i, j;
	unsigned int ans;
	memset(dp, 0, sizeof(dp));  dp[la][lb] = 1;
	for(i=la; i; i--)for(j=lb; j; j--){
		if( !pi[i][j] )			dp[i-1][j-1] += dp[i][j];
		else{
			if( pi[i][j]<=2 )   dp[i][j-1] += dp[i][j];
			if( pi[i][j]>=2 )   dp[i-1][j] += dp[i][j];
		}
	}
	ans = dp[0][0];
	for(i=1; i<=la; i++)    ans += dp[i][0];
	for(i=1; i<=lb; i++)    ans += dp[0][i];
	printf("%d %u\n", la+lb-LCS[la][lb], ans);
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, la, lb;
	scanf("%d\n", &cas);
	while( cas-- ){
		gets(a+1);  gets(b+1);
		la = strlen(a+1); lb = strlen(b+1);
		SolveLCS(la,lb);
		printf("Case #%d: ", ++c);
		SolveDP(la,lb);
	}
	return 0;
}
