#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 101
int dp[MAXN][MAXN]={{0}}, block[MAXN][MAXN];

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, n, h, w, i, j;
	char in[1000], *p;
	scanf("%d", &n);    dp[0][1] = 1;
	while( n-- ){
		if( c++ )   putchar('\n');
		scanf("%d %d\n", &w, &h);
		memset(block, 0, sizeof(block));
		for(i=1; i<=w; i++){
			gets(in);
			p = strtok(in, " ");
			j = atoi(p);
			p = strtok(NULL, " ");
			while( p!=NULL ){
				block[j][atoi(p)]++;
                p = strtok(NULL, " ");
			}
		}
		for(i=1; i<=w; i++)for(j=1; j<=h; j++)
		if( block[i][j] )   dp[i][j] = 0;
		else                dp[i][j] = dp[i-1][j] + dp[i][j-1];
		
		printf("%d\n", dp[w][h]);
	}
	return 0;
}
