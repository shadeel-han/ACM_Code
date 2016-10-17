#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

struct NODE{
	int n, t;
	NODE(int n, int t):n(n),t(t) {};
};

int NodeNum;
map<int,int> hash;
vector<int> node[30];

void input(int n){
	hash.clear();
	NodeNum = 0;
	for(int i=0; i<30; ++i) node[i].clear();
	for(int i=0; i<n; ++i){
		int from, to;
		scanf("%d %d", &from, &to);
		if( hash.find(from)==hash.end() )	hash[from] = NodeNum++;
		if( hash.find(to)==hash.end() )		hash[to] = NodeNum++;
		node[hash[from]].push_back(hash[to]);
		node[hash[to]].push_back(hash[from]);
	}
}

int traverse(int start, int ttl){
	bool walk[30]={0};	int ans=NodeNum;
	queue<NODE> que;
    
    if( hash.find(start)!=hash.end() ){
        que.push(NODE(hash[start],ttl));
    	walk[hash[start]] = true;
    	--ans;
    }
    
    if( ttl<=0 )    return ans;
    
    while( !que.empty() ){
		NODE now = que.front();  que.pop();
		for(int i=0,j=node[now.n].size(); i<j; ++i){
			if( !walk[node[now.n][i]] ){
                walk[node[now.n][i]] = true;    --ans;
                if( now.t > 1 ) que.push(NODE(node[now.n][i], now.t-1));
			}
		}
    }
    return ans;
}

int main(void){

    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int c=0, n;
	while( scanf("%d", &n) && n!=0 ){
		input(n);
		int start, ttl;
		while( scanf("%d %d", &start, &ttl) && !(start==0 && ttl==0) ){
            int ans = traverse(start, ttl);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++c, ans, start, ttl);
		}
	}

	return 0;
}
