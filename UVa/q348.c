#include <stdio.h>
#include <string.h>

#define MAXN 11
int row[MAXN], col[MAXN], dp[MAXN][MAXN], path[MAXN][MAXN];

int SolveDP(int start, int end){
	if( dp[start][end]==-1 ){
		int i, j, tmp, small=2147483647;
		for(i=start; i<end; i++){
			tmp = SolveDP(start, i) + SolveDP(i+1, end) + row[start]*col[i]*col[end];
			if( small > tmp )	small = tmp, j = i;
		}
		dp[start][end] = small;	path[start][end] = j;
	}
	return dp[start][end];
}

/*void PrintAns(int start, int end){
	if( end==start )
		sprintf(output, "A%d", start);
	else{
		char left[100], right[100];
        PrintAns(start, path[start][end]);
        sprintf(left, "%s", output);
        PrintAns(path[start][end]+1, end);
        sprintf(right, "%s", output);
        sprintf(output, "(%s x %s)", left, right);
	}
}*/

void PrintAns(int start, int end){
	if( end==start )
		printf("A%d", start);
	else{
		putchar('(');
        PrintAns(start, path[start][end]);
        printf(" x ");
        PrintAns(path[start][end]+1, end);
        putchar(')');
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, n, i;
	while( scanf("%d", &n) && n ){
        memset(dp, -1, sizeof(dp));
		for(i=1; i<=n; i++){
			scanf("%d%d", &row[i], &col[i]);	dp[i][i] = 0;
		}
		printf("Case %d: ", ++c);
		if( n==1 )  puts("(A1)");
		else{
            SolveDP(1,n);	PrintAns(1,n);  putchar('\n');
		}
	}
	return 0;
}
