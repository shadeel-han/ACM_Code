#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MAXN 501
#define INF 5000000001LL
long long int dp[MAXN][MAXN];
int book[MAXN];

int SolveDP(int k, int m){
	if( dp[k][m]==-1 ){
		int i;  dp[k][m] = INF;
		long long int sum = 0, tmp;
		for(i=m; i>=k; i--){
			sum += book[i];
			if( sum >= dp[k][m] )	break;
			tmp = MAX(SolveDP(k-1, i-1), sum);
			if( dp[k][m] > tmp )	dp[k][m] = tmp;
		}
	}
	return dp[k][m];
}

void PrintAns(int k, int m, long long int maxx){
	if( k==1 ){
        printf("%d", book[m]);  int i;
		for(i=m-1; i; i--)	printf(" %d", book[i]);
	}else{
		int i, j;
		for(i=m; i>=k; i--)
		if( dp[k-1][i-1]<=maxx )    break;
		printf("%d", book[m]);
		for(j=m-1; j>=i; j--)   printf(" %d", book[j]);
		printf(" / ");
		PrintAns(k-1, i-1, maxx);
 	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, m, k, i, j;
	long long int low=0, up=0, mid, tmp;
	scanf("%d", &n);
	while( n-- ){
		scanf("%d %d", &m, &k);
		for(i=1; i<=m; i++){
			scanf("%d", &book[i]);
			up += book[i];
			if( book[i] > low ) low = book[i];
		}
		/* binary search */
		while( low != up ){
			mid = (low+up) / 2;
			for()
		}
		
		
		SolveDP(k, m);
		PrintAns(k, m, dp[k][m]); putchar('\n');
	}
	return 0;
}
