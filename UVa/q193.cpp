#include <cstdio>
#include <vector>

using namespace std;

#define NUM 101
vector<int> edge[NUM];
int neigh[NUM]={0}, ans[NUM], maxn, stop;
char output[500];

void EdgeInput(int n, int k){
    for(int i=1; i<=n; ++i) edge[i].clear();
	for(int i=0; i<k; ++i){
		int from, to;
		scanf("%d %d", &from, &to);
		if( from < to )	edge[from].push_back(to);
		else			edge[to].push_back(from);
	}
	maxn = 0;	stop = n+1;
}

void backtrack(int node, int num){
	if( node==stop ){
		if( maxn < num ){
            maxn = num;
            sprintf(output, "%d", ans[0]);
            for(int i=1; i<num; ++i)
            sprintf(output, "%s %d", output, ans[i]);
		}
		return;
	}
	
	// color white
	backtrack(node+1, num);
	// color black, only if no neighbor is black
	if( !neigh[node] ){
		for(int i=0,j=edge[node].size(); i<j; ++i)	++neigh[edge[node][i]];
		ans[num] = node;
		backtrack(node+1, num+1);
		for(int i=0,j=edge[node].size(); i<j; ++i)	--neigh[edge[node][i]];
	}
}

int main(){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int m, n, k;
	scanf("%d", &m);
	while( m-- ){
		scanf("%d %d", &n, &k);
		EdgeInput(n,k);
		backtrack(1,0);
		printf("%d\n%s\n", maxn, output);
	}
	
	return 0;
}
