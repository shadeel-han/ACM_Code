#include <stdio.h>
#include <string.h>

#define MAXT 1001
#define MAXN 32

int dep[MAXN], val[MAXN], dp[MAXN][MAXT], path[MAXN][MAXT], t, w, n;

int RecursiveDP(int now, int use_time){
	if( dp[now][use_time]>(-1) )	return dp[now][use_time];
	
	int i, j, gain=0;
	for(i=now+1; i<=n; i++)if( use_time+3*w*dep[i] <= t ){
		j = val[i] + RecursiveDP(i, use_time+3*w*dep[i]);
		if( j > gain ){
			gain = j;
			path[now][use_time] = i;
		}
	}
	return dp[now][use_time] = gain;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, c=0, cnt;
	char output[MAXT];
	while( scanf("%d %d", &t, &w)!=EOF ){
		if( c++ )   putchar('\n');
		scanf("%d", &n);
		for(i=1; i<=n; i++)	scanf("%d %d", &dep[i], &val[i]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", RecursiveDP(0,0));
		output[0] = 0;  i = 0;  j = 0;  cnt = 0;
		while( dp[i][j] ){
			sprintf(output, "%s%d %d\n", output, dep[path[i][j]], val[path[i][j]]);
			cnt++;  i = path[i][j]; j += 3*w*dep[i];
		}
		printf("%d\n%s", cnt, output);
	}
	return 0;
}
