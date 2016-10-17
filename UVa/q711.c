#include <stdio.h>
#include <string.h>
#define MAXN 60001
int dp[MAXN]={0};

int SolveDP(int val[], int n){
	if( n < 0 ) return 0;
	if( dp[n]==-1 ){
		int i;
		for(i=1; i<=6; i++)if( val[i] ){
			val[i]--;
			if( SolveDP(val, n-i) )	break;
			val[i]++;
		}
		dp[n] = (i<=6)?(1):(0);
	}
	return dp[n];
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, val[7], i, tol;
	while(1){
		for(i=1,tol=0; i<=6; i++){
			scanf("%d", &val[i]);   tol += (val[i]*i);
		}
		if( !tol )	break;
		else        printf("Collection #%d:\n", ++c);
		if( tol & 1 ){
			puts("Can't be divided.\n");	continue;
		} else tol >>= 1;
		
		memset(dp, -1, sizeof(dp));	dp[0] = 1;
		if( SolveDP(val, tol) )
				puts("Can be divided.\n");
		else	puts("Can't be divided.\n");
	}
	return 0;
}
