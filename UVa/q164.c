#include <stdio.h>
#include <string.h>
#define MAXN 25
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN], path[MAXN][MAXN];
/*  0:skip, 1:change a[i] to b[j], 2:delete a[i], 3:insert b[j] to a[i] */

void SolveDP(int lena, int lenb){
	int i, j, dx[4]={0,-1,-1,0}, dy[4]={0,-1,0,-1};
    for(i=1; i<=lena; i++)for(j=1; j<=lenb; j++){
		if( a[i]==b[j] )	dp[i][j] = dp[i-1][j-1], path[i][j] = 0;
		else{
			int small=MAXN, get, k;
			for(k=1; k<4; k++)if( small > dp[i+dx[k]][j+dy[k]] ){
				small = dp[i+dx[k]][j+dy[k]];	get = k;
			}
			dp[i][j] = small + 1;	path[i][j] = get;
		}
    }
}

int PrintAns(int lena, int lenb){   /* return number of deletion */
	if( lena || lenb ){
		int del;
		if( path[lena][lenb]==1 ){
			del = PrintAns(lena-1, lenb-1);
			printf("C%c%02d", b[lenb], lena-del);
		}
		else if( path[lena][lenb]==2 ){
			del = PrintAns(lena-1, lenb);
			printf("D%c%02d", a[lena], lena-del); del++;
		}
		else if( path[lena][lenb]==3 ){
			del = PrintAns(lena, lenb-1);
			del--;	printf("I%c%02d", b[lenb], lena-del);
		}
		else del = PrintAns(lena-1, lenb-1);
		return del;
	}
	else return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, lena, lenb;
	dp[0][0] = 0;
	for(i=1; i<MAXN; i++){
		dp[i][0] = dp[0][i] = i;
		path[i][0] = 2; path[0][i] = 3;
	}
	while( scanf("%s", a+1) && a[1]!='#' ){
        scanf("%s", b+1);
        lena = strlen(a+1);   lenb = strlen(b+1);
        SolveDP(lena, lenb);
        PrintAns(lena, lenb);   puts("E");
        /*for(i=0; i<=lena; i++){
			for(j=0; j<=lenb; j++)  printf("%3d", dp[i][j]);
			putchar('\n');
		}*/
	}
	
	return 0;
}
