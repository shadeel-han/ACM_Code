#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 91
int rect[MAXN][3];
char edge[MAXN][MAXN];

int compare( const void* a, const void* b ){
	return ( *(int*)a - *(int*)b );
    // return value <0  => exchange
	// return value >=0 => not exchange
}

void Input(int n){
	for(int i=1; i<=n; i+=3){
		scanf("%d %d %d", &rect[i][0], &rect[i][1], &rect[i][2]);
		qsort(rect[i], 3, sizeof(int), compare);
		rect[i+1][0] = rect[i][0];	rect[i+1][1] = rect[i][2];	rect[i+1][2] = rect[i][1];
		rect[i+2][0] = rect[i][1];	rect[i+2][1] = rect[i][2];	rect[i+2][2] = rect[i][0];
	}
}

int Solve(int n){
	int i, j;
	memset(edge, 0, sizeof(edge));
	for(i=1; i<=n; i++) edge[0][i] = 1;

	for(i=1; i<=n; i++)for(j=1; j<=n; j++)	/* check if rect(i) can put onto rect(j) */
	if( (rect[i][0]<rect[j][0]) && (rect[i][1]<rect[j][1]) )
		edge[i][j] = 1;

	/* bfs to find the highest stack */
	int hei[MAXN]={0}, inque[MAXN]={0};
	queue<int> que;	que.push(0);
	while( !que.empty() ){
		int now = que.front();  que.pop();  inque[now] = 0;
		for(i=1; i<=n; i++)if( edge[now][i] ){
			if( hei[i] < hei[now] + rect[i][2] ){
                hei[i] = hei[now] + rect[i][2];
                if( !inque[i] ){
					inque[i] = 1;   que.push(i);
    }	}	}	}

	/* get answer */
	int ans = 0;
	for(i=1; i<=n; i++)
	if( hei[i]>ans )	ans = hei[i];
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, c=0;
	while( scanf("%d", &n) && n){
		n *= 3;
		Input(n);
		printf("Case %d: maximum height = %d\n", ++c, Solve(n));
	}
	return 0;
}
