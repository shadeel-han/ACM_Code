#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 101
int dp[MAXN][MAXN];

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, i, j, k, n, t, m, song, tmp;
	char in[10000], *p;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d%d%d\n", &n, &t, &m);
		gets(in);
		p = strtok(in, ", ");
		memset(dp, 0, sizeof(dp));  k = m;
		while( n-- ){
			song = atoi(p);
			p = strtok(NULL, ", ");
			for(i=k; i<=m; i++)for(j=song; j<=t; j++){
					tmp = dp[i][j] + 1;
                    if( dp[i][j-song] < tmp ){
						dp[i][j-song] = tmp;
						if( dp[i-1][t] < tmp )
						    dp[i-1][t] = tmp;
					}
			}
			if( k>1 )   k--;
		}
		if( c++ )   putchar('\n');
		printf("%d\n", dp[0][t]);
	}
	return 0;
}
