#include <stdio.h>
#include <string.h>
#define MAXN 31

long long int dp[MAXN][MAXN]={{0}};
char block[MAXN][MAXN][2];

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, n, i, j, k, sx, sy, ex, ey;
	char d;
	scanf("%d", &c);
	while( c-- ){
		scanf("%d", &n);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);
		scanf("%d", &n);
		memset(block, 0, sizeof(block));
		for(i=0; i<n; i++){
            scanf("%d %d %c", &j, &k, &d);
            if( d=='E' || d=='W' ){
				if( d=='E' )    j++;
				block[j][k][0] = 1;
            }else{
                if( d=='N' )    k++;
				block[j][k][1] = 1;
            }
		}
		memset(dp, 0, sizeof(dp));  dp[sx][sy] = 1;
		for(i=sx; i<=ex; i++)for(j=sy; j<=ey; j++){
			if( !block[i][j][0] )   dp[i][j] += dp[i-1][j];
			if( !block[i][j][1] )   dp[i][j] += dp[i][j-1];
		}
		printf("%lld\n", dp[ex][ey]);
	}
	return 0;
}
