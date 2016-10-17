#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define MAXN 1001
int wei[MAXN], iq[MAXN], pi[MAXN];
char edge[MAXN][MAXN]={0};

void PrintAns(int n){
	if( n ){
        PrintAns(pi[n]);
        printf("%d\n", n);
	}
}

int Solve(int n){
	int i, j;
	//memset(edge, 0, sizeof(edge));
	for(i=1; i<=n; i++) edge[0][i] = 1;

	for(i=1; i<=n; i++)for(j=1; j<=n; j++)	/* check if rect(i) can order behind rect(j) */
	if( (wei[i]<wei[j]) && (iq[i]>iq[j]) )
		edge[i][j] = 1;

	/* bfs to find the highest stack */
	int hei[MAXN]={0}, inque[MAXN]={0};
	queue<int> que;	que.push(0);
	while( !que.empty() ){
		int now = que.front();  que.pop();  inque[now] = 0;
		for(i=1; i<=n; i++)if( edge[now][i] ){
			if( hei[i] < hei[now] + 1 ){
                hei[i] = hei[now] + 1;  pi[i] = now;
                if( !inque[i] ){
					inque[i] = 1;   que.push(i);
    }	}	}	}

	/* get answer */
	int ans = 0;
	for(i=1; i<=n; i++)if( hei[i]>ans )
		ans = hei[i], j = i;
	printf("%d\n", ans);
	PrintAns(j);
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n=1;
	wei[0] = 0;	iq[0] = 10001;
	while( scanf("%d %d", &wei[n], &iq[n])!=EOF && ++n );
	Solve(n);
	return 0;
}
