#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int box[31][10];
char edge[31][31];

int compare( const void* a, const void* b ){
	return ( *(int*)a - *(int*)b );
    // return value <0  => exchange
	// return value >=0 => not exchange
}

void Input(int n, int d){
	for(int i=1; i<=n; i++){
		for(int j=0; j<d; j++)  scanf("%d", &box[i][j]);
		qsort(box[i], d, sizeof(int), compare);
	}
}

void Solve(int n, int d){
	int i, j, k;
	memset(edge, 0, sizeof(edge));
	for(i=1; i<=n; i++) edge[0][i] = 1;
	
	for(i=1; i<=n; i++)for(j=1; j<=n; j++)	/* check if box(i) can put into box(j) */
	if( i!=j ){
		for(k=0; k<d; k++)  if( box[i][k] >= box[j][k] ) break;
		if( k==d )	edge[i][j] = 1;
	}
	
	/* bfs to find the longest nesting box */
	int dis[31]={0}, dir[31], inque[31]={0};
	queue<int> que;	que.push(0);
	while( !que.empty() ){
		int now = que.front();  que.pop();  inque[now] = 0;
		for(i=1; i<=n; i++)if( edge[now][i] ){
			if( dis[i] < dis[now] + 1 ){
                dis[i] = dis[now] + 1;	dir[i] = now;
                if( !inque[i] ){
					inque[i] = 1;   que.push(i);
    }	}	}	}
	
	/* get answer */
	int ans = 0;    char tmp[100]={0}, output[100]={0};
	for(i=1; i<=n; i++)if( dis[i]>ans ){
		ans = dis[i];   k = i;
	}
	while( k ){
		sprintf(tmp, "%d %s", k, output);
		sprintf(output, "%s", tmp);
		k = dir[k];
	}
	printf("%d\n%s\n", ans, output);
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, d;
	while( scanf("%d %d", &n, &d)!=EOF ){
		Input(n, d);
		Solve(n, d);
	}
	return 0;
}
