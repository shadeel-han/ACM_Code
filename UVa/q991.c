/*
 Try to pick any of n pairs as new-added one putting into a group of n-1 pairs
 and the answer will clearly be the sum of any decomposition of the n-1 pairs
  for example: 2 pairs => 0+1, 1+0
			   3 pairs => 0+2, 1+1, 2+0
			   4 pairs => 0+3, 1+2, 2+1, 3+0
*/

#include <stdio.h>
#define MAXN 11

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, dp[MAXN]={1,1};
	for(i=2; i<MAXN; i++)for(j=0; j<i; j++)
	    dp[i] += dp[j]*dp[i-j-1];
	j = 0;
	while( scanf("%d", &i)!=EOF ){
		if( j++ )   putchar('\n');
	    printf("%d\n", dp[i]);
	}
	return 0;
}
