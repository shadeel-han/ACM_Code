#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAXN 101

using namespace std;

int tax[MAXN], dp[MAXN][MAXN];

int MinDis(int f, int t, int n){
	queue<int> que;
	int dis[MAXN], path[MAXN], inque[MAXN]={0};
	memset(dis, -1, sizeof(dis));
	
	que.push(f);	dis[f] = 0;
	while( !que.empty() ){
		int now = que.front();	que.pop();	inque[now] = 0;
		for(int i=1; i<=n; i++)if(i!=now && dp[now][i]!=-1){
			if( dis[i]==-1 || dis[i] > dis[now]+dp[now][i]+((now!=f)?(tax[now]):(0)) ){
				dis[i] = dis[now]+dp[now][i]+((now!=f)?(tax[now]):(0));
				path[i] = now;
				if( !inque[i] ){
					inque[i] = 1;	que.push(i);
				}
			}
		}
	}
	
	int a = t, b = -1, c;
	while( b!=f ){
		c = path[a];
		path[a] = b;
		b = a;
		a = c;
	}
	
	printf("Path: ");
	a = f;
	while( a!=t ){
		printf("%d-->",a);
		a = path[a];
	}
	printf("%d\n", t);
	return dis[t];
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int cas, i, j, k, n;
	char in[5000], *p;
	scanf("%d\n", &cas);
	while( cas-- ){
		gets(in);	n = 0;
		p = strtok(in, " ");
		do{
			dp[1][++n] = atoi(p);
			p = strtok(NULL, " ");
		}while( p!=NULL );
			
		for(i=2; i<=n; i++)for(j=1; j<=n; j++)	scanf("%d", &dp[i][j]);
		for(i=1; i<=n; i++)	scanf("%d", &tax[i]);	getchar();
		
		k = 0;
		while( gets(in)!=NULL && strlen(in) ){
			if( k++ )	putchar('\n');
			sscanf(in, "%d %d", &i, &j);
			printf("From %d to %d :\n", i, j);
			if( i==j )	printf("Path: %d\nTotal cost : 0\n", i);
			else		printf("Total cost : %d\n", MinDis(i,j,n));
		}
		if( cas )	putchar('\n');
	}
	return 0;
}

