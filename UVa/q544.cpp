#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXX 201
#define INF 10001
struct ROAD{
	int from, to, wei;
	ROAD(){};
	ROAD(int a, int b, int c):from(a), to(b), wei(c){};
	bool operator<(const ROAD &a) const{    // maximum heap for PQ
		return (wei<a.wei);
	}
};

map<string, int> hash_table;
vector<ROAD> road[MAXX], city[MAXX];
int path[MAXX];

void Input(int n, int r){
	int num = 0;	hash_table.clear();
	for(int i=1; i<=n; i++){
		city[i].clear();    road[i].clear();
	}
	for(int i=0; i<r; i++){
		char f[35], t[35];  int ton;
		scanf("%s %s %d", f, t, &ton);
		string ff(f), tt(t);
		if( hash_table.find(ff)==hash_table.end() )	hash_table[ff] = ++num;
		if( hash_table.find(tt)==hash_table.end() )	hash_table[tt] = ++num;
		road[hash_table[ff]].push_back(ROAD(hash_table[ff], hash_table[tt], ton));
		road[hash_table[tt]].push_back(ROAD(hash_table[tt], hash_table[ff], ton));
	}
}

int dfs(int pos, int end){
	if( pos==end ){
		path[pos] = 1;
		return INF;
	}

	path[pos] = 0;
	for(int i=0,j=city[pos].size(); i<j; i++)
	if( path[city[pos][i].to]==-1 ){
		int get = dfs(city[pos][i].to, end);
		if( path[city[pos][i].to] ){
			path[pos] = 1;
			return (get<city[pos][i].wei)?(get):(city[pos][i].wei);
		}
	}
	return INF;
}

int Solve(int from, int to){
	char walk[MAXX]={0};
	priority_queue<ROAD> pq;
	// MST_Prim
	walk[from] = 1;
	for(int i=0,j=road[from].size(); i<j; i++)	pq.push(road[from][i]);
	while( !pq.empty() && !walk[to] ){
		ROAD now = pq.top();    pq.pop();   int t = now.to;
		if( walk[t] )  continue;	walk[t] = 1;
		city[now.from].push_back(now);
		city[t].push_back(ROAD(t, now.from, now.wei));
		for(int i=0,j=road[t].size(); i<j; i++)
		if( !walk[road[t][i].to] )  pq.push(road[t][i]);
	}
	// find path
	memset(path, -1, sizeof(path));
	int ans = dfs(from, to);
	return (ans==INF)?(0):(ans);
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, r, c=0;
	while( scanf("%d %d", &n, &r) && n ){
		Input(n, r);
		char f[35], t[35];
		scanf("%s %s", f, t);
		printf("Scenario #%d\n%d tons\n\n", ++c, Solve(hash_table[string(f)], hash_table[string(t)]));
	}
	return 0;
}
