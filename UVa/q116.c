#include <stdio.h>
#define MAXX 2147483647
int mat[101][11], cost[101][11], path[101][11];

void Solve(int row, int col){
	int i, n, j, k, dx[3]={0,1,-1};
	for(i=col,n=i-1; i>1; i--,n--){
		for(j=1; j<=row; j++)for(k=0; k<3; k++){
			int next = j + dx[k];
			if( !next )			next = row;
			else if( next>row )	next = 1;
			if( cost[n][next] > cost[i][j] + mat[n][next] ){
                cost[n][next] = cost[i][j] + mat[n][next];
                path[n][next] = j;
			}
		}
	}
	/*for(i=1; i<=row; i++){
		for(j=1; j<=col; j++)   printf("%3d", cost[j][i]);
		putchar('\n');
	}
	for(i=1; i<=row; i++){
		for(j=1; j<=col; j++)   printf("%3d", path[j][i]);
		putchar('\n');
	}*/
	/*print answer*/
	j = MAXX;
	for(i=1; i<=row; i++)
	if( j > cost[1][i] )    j = cost[1][i], k = i;
	printf("%d", k);
	for(i=1; i<col; k=path[i][k],i++)	printf(" %d", path[i][k]);
	printf("\n%d\n", j);
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int row, col, i, j;
	while( scanf("%d %d", &row, &col)!=EOF ){
		for(i=1; i<=row; i++)for(j=1; j<=col; j++){
			scanf("%d", &mat[j][i]);
			cost[j][i] = MAXX;
		}
		for(i=1; i<=row; i++)	cost[col][i] = mat[col][i];
		Solve(row,col);
	}
	return 0;
}
