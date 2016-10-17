#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> edge[25];
char connect[25][25];
int ans;

void RoadInput(int n, int m){
	for(int i=0; i<n; ++i)  edge[i].clear();
	memset(connect, 0, sizeof(connect));
	for(int i=0; i<m; ++i){
		int from, to;
		scanf("%d %d", &from, &to);
		edge[from].push_back(to);
		edge[to].push_back(from);
		connect[from][to]++;
		connect[to][from]++;
	}
}

void backtrace(int here, int len){
	if( ans < len ) ans = len;
	for(int i=0,j=edge[here].size(); i<j; ++i){
		int to = edge[here][i];
		if( !connect[here][to] )    continue;
		connect[here][to]--;
		connect[to][here]--;
		backtrace(to, len+1);
		connect[here][to]++;
		connect[to][here]++;
	}
}

int main(){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;

	while( scanf("%d %d", &n, &m) && n ){
		RoadInput(n, m);
		ans = 0;
		for(int i=0; i<n; ++i)	backtrace(i,0);
		printf("%d\n", ans);
	}
	
	return 0;
}
