#include <stdio.h>
#define MAXN 101

int wire[MAXN][MAXN]={{0}};

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, n, i, j, k;
	
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d", &n);
		for(i=2; i<=n; i++)for(j=1; j<i; j++){
			scanf("%d", &k);
			wire[i][j] = wire[j][i] = k;
		}
		
		int stop = 1, m = (n*(n-1))>>1;
		for(k=1; k<=n && stop; k++)for(i=1; i<=n && stop; i++)for(j=1; j<=n && stop; j++)
		if( wire[i][j] && wire[i][k] && wire[k][j] ){
			if( wire[i][j] > wire[i][k] + wire[k][j] )		stop--;
			if( wire[i][j] == wire[i][k] + wire[k][j] )		wire[i][j] = wire[j][i] = 0, m--;
		}
		
		printf("Case #%d:\n", ++c);
		if( !stop )	puts("Need better measurements.");
		else{
			printf("%d\n", m);
			for(i=1; i<n; i++)for(j=i+1; j<=n; j++)
			if( wire[i][j] )	printf("%d %d %d\n", i, j, wire[i][j]);
		}
		putchar('\n');
		
	}
	return 0;
}

