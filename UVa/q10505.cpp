/*
This question can be tranformed to 2-coloring problem in which the edge is indirectionl.
The testcase may be odd because two reasons.
1. There may be cycles in the graph.
2. There may be nodes with numbers higher than the number of expected/invited people.
*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> edge[201], get;
int color[201];

void EdgeInput(int n){
    for(int i=1; i<=n; ++i)  edge[i].clear();
	for(int i=1; i<=n; ++i){
		int m;  scanf("%d", &m);
		for(int j=0; j<m; ++j){
			int to; scanf("%d", &to);
			if( to > 0 && to <= n ){	// for reason 2
                edge[i].push_back(to);
				edge[to].push_back(i);
			}
		}
	}
}

bool DFSTraverse(int n, int c){  // number of that person, color
	bool OddCycle = false;
	for(int i=0,j=edge[n].size(); i<j; ++i)
	if( !color[edge[n][i]] ){
        color[edge[n][i]] = c + 1;
        get.push_back(edge[n][i]);
        OddCycle |= DFSTraverse(edge[n][i],c+1);
	}else if( (color[edge[n][i]]&1) == (c&1) )
		OddCycle = true;	// for reason 1, cycles with odd length are unacceptable
	return OddCycle;
}

int Count(void){
	int cnt[2]={0};
	for(int i=0,j=get.size(); i<j; ++i)
		++cnt[(color[get[i]]&1)];
	return (cnt[0]>cnt[1])?(cnt[0]):(cnt[1]);
}

int Solve(int n){
	int ans=0;
    memset(color, 0, sizeof(color));
    for(int i=1; i<=n; ++i)
    if( !color[i] ){
		get.clear();
		color[i] = 1;   get.push_back(i);
		bool OddCycle = DFSTraverse(i,1);
		if(!OddCycle)	ans += Count();
    }
    return ans;
}

int main(void){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int c;	scanf("%d", &c);
	while( c-- ){
		int n;	scanf("%d", &n);
		EdgeInput(n);
		printf("%d\n", Solve(n));
	}
	return 0;
}
