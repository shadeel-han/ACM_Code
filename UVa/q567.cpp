#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[21];

int input(void){
	int c = 0, n;
	for(int i=1; i<=20; ++i)    edge[i].clear();
	while( ++c < 20 && scanf("%d", &n)!=EOF )
		for(int i=0; i<n; ++i){
			int des;
			scanf("%d", &des);
			edge[c].push_back(des);
			edge[des].push_back(c);
		}

	return ((c==20)?(1):(0));
}

int traverse(int from, int to){
	int dis[21];	queue<int> que;

	memset(dis,-1,sizeof(dis));
	que.push(from); dis[from] = 0;
    while( !que.empty() ){
		int now = que.front();  que.pop();
		for(int i=0,j=edge[now].size(); i<j; ++i){
			if( dis[edge[now][i]]==-1 ){
                dis[edge[now][i]] = dis[now]+1;
                que.push(edge[now][i]);
			}
		}
    }
    return dis[to];
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int c = 0;
	while( input() ){
		int n, from, to;
		scanf("%d", &n);
		printf("Test Set #%d\n", ++c);
		for(int i=0; i<n; ++i){
			scanf("%d %d", &from, &to);
			printf("%2d to %2d:%2d\n", from, to, traverse(from,to));
		}
		putchar('\n');
	}
	return 0;
}
