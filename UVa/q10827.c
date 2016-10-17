#include <stdio.h>
#define MAXN 150
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
int rect[MAXN][MAXN];

int Solve1D(int n, int s[MAXN]){
	int i, max_tmp = 0, min_tmp = 0, maxx = -101, minn = 101, sum = 0;
	for(i=0; i<n; i++){
		if( max_tmp < 0 )	max_tmp = s[i];
		else				max_tmp += s[i];
		maxx = MAX(maxx,max_tmp);
		if( min_tmp > 0 )	min_tmp = s[i];
		else				min_tmp += s[i];
		minn = MIN(minn,min_tmp);
		sum += s[i];
	}
	/* max happens at (maximum subarray) or (sum-minimum subarray) */
	if( sum > minn )    minn = sum-minn;
	return MAX(maxx, minn);
}

int Solve2D(int n){
	int nn, i, j, k, ans = -101, tmp;
	for(i=0,nn=i+n; i<n; i++,nn++){
		int s[MAXN]={0};
		for(j=i; j<nn; j++){
			for(k=0; k<n; k++)	s[k] += rect[j][k];
			tmp = Solve1D(n, s);
			ans = MAX(ans,tmp);
		}
	}
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, n, i, j;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d", &n);
		for(i=0; i<n; i++)for(j=0; j<n; j++){
			scanf("%d", &rect[i][j]);
			rect[i+n][j] = rect[i][j];
		}
		printf("%d\n", Solve2D(n));
	}
	return 0;
}
