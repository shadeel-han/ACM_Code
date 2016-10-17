#include <stdio.h>
#include <string.h>

int fli_num[11][11], flight[11][11][31], dp[1001][11];

void Input(int n){
	int i, j, k;
	for(i=1; i<=n; i++)for(j=1; j<=n; j++){
		if( i==j )  continue;
		scanf("%d", &fli_num[i][j]);
		for(k=0; k<fli_num[i][j]; k++)
		    scanf("%d", &flight[i][j][k]);
	}
}

int SolveDP(int n, int k){
	int i, j, a, b;
	memset(dp, -1, sizeof(dp)); dp[0][1] = 0;
    for(i=0; i<k; i++)for(j=1; j<=n; j++){
		if( dp[i][j]==-1 )    continue;
		for(a=1; a<=n; a++){
			if( a==j || !flight[j][a][i%fli_num[j][a]] )  continue;
			b = dp[i][j] + flight[j][a][i%fli_num[j][a]];
			if( dp[i+1][a]==-1 || dp[i+1][a]>b )    dp[i+1][a] = b;
		}
    }
    return dp[k][n];
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, k, c=0;
	while( scanf("%d %d", &n, &k) && n ){
		Input(n);
		k = SolveDP(n, k);
		if( k==-1 ) printf("Scenario #%d\nNo flight possible.\n\n", ++c);
		else        printf("Scenario #%d\nThe best flight costs %d.\n\n", ++c, k);
	}
	return 0;
}
