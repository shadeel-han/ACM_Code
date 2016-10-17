#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005

int dp[MAXN][MAXN]={0}, pi[MAXN][MAXN];
char a[MAXN], b[MAXN];

int compare( const void* a, const void* b ){
	return ( *(char*)a - *(char*)b );
    /* return value <0  => exchange
	return value >=0 => not exchange */
}

void PrintAns(int m, int n){
	if( m && n ){
		if( pi[m][n]==0 )   	PrintAns(m-1,n);
		else if( pi[m][n]==1 )  PrintAns(m,n-1);
		else{
            PrintAns(m-1,n-1);
            printf("%c", a[m]);
		}
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, c=0, lena, lenb;
	a[0] = b[0] = 1;
	while( gets(a+1)!=NULL ){
        gets(b+1);    lena = strlen(a)-1;	lenb = strlen(b)-1;
        qsort(a+1, lena, sizeof(char), compare);
        qsort(b+1, lenb, sizeof(char), compare);
		/*memset(dp, 0, sizeof(dp));*/
		for(i=1; i<=lena; i++)for(j=1; j<=lenb; j++){
			if( a[i]==b[j] )					dp[i][j] = dp[i-1][j-1] + 1, pi[i][j] = 2;
			else if( dp[i-1][j] > dp[i][j-1] )	dp[i][j] = dp[i-1][j], pi[i][j] = 0;
			else                                dp[i][j] = dp[i][j-1], pi[i][j] = 1;
		}
		PrintAns(lena, lenb);   putchar('\n');
	}

	return 0;
}
