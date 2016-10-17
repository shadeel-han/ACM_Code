#include <stdio.h>
#include <string.h>

#define MAXN 1005

int dp[MAXN][MAXN];
char a[MAXN], b[MAXN];

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, lena, lenb;
	a[0] = b[0] = 1;
	while( gets(a+1)!=NULL ){
        gets(b+1);    lena = strlen(a)-1;	lenb = strlen(b)-1;
		memset(dp, 0, sizeof(dp));
		for(i=1; i<=lena; i++)for(j=1; j<=lenb; j++){
			if( a[i]==b[j] )					dp[i][j] = dp[i-1][j-1] + 1;
			else if( dp[i-1][j] > dp[i][j-1] )	dp[i][j] = dp[i-1][j];
			else                                dp[i][j] = dp[i][j-1];
		}
		printf("%d\n", dp[lena][lenb]);
	}

	return 0;
}
