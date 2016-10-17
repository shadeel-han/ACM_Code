#include <stdio.h>
#include <string.h>
#define MAXN 31

int route[MAXN][MAXN];
char reach[MAXN][MAXN];

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int c=0, n, i, j, k;
	while( scanf("%d", &n)!=EOF ){
		memset(route, 0, sizeof(route));
		memset(reach, 0, sizeof(reach));
		int maxx = 0;
		for(i=0; i<n; i++){
			scanf("%d %d", &j, &k);
			route[j][k]++;
			reach[j][k] = 1;
			if( maxx < j )	maxx = j;
			if( maxx < k )	maxx = k;
		}
		
		for(k=0; k<=maxx; k++)for(i=0; i<=maxx; i++)for(j=0; j<=maxx; j++)
		reach[i][j] |= (reach[i][k]&reach[k][j]);
		
		for(i=0; i<=maxx; i++)if( reach[i][i] ){	// if there's cycle
			for(j=0; j<=maxx; j++){
				if( route[i][j] )	route[i][j] = -1;
				if( route[j][i] )	route[j][i] = -1;
			}
		}
		
		for(k=0; k<=maxx; k++)for(i=0; i<=maxx; i++)for(j=0; j<=maxx; j++)
		if( route[i][j]!=-1 && route[i][k]*route[k][j] ){
			if( route[i][k]!=-1 && route[k][j]!=-1 )
				route[i][j] += route[i][k]*route[k][j];
			else
				route[i][j] = -1;
		}
		
		printf("matrix for city %d\n", c++);
		for(i=0; i<=maxx; i++){
			printf("%d", route[i][0]);
			for(j=1; j<=maxx; j++)	printf(" %d", route[i][j]);
			putchar('\n');
		}
		
	}
	
	
	return 0;
}

