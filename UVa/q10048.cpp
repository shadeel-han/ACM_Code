#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define MAXC 101
struct ROAD{
	int from, to, wei;
	ROAD(){};
	ROAD(int a, int b, int c):from(a), to(b), wei(c){};
	bool operator<(const ROAD &a) const{    // minimum heap for PQ
		return (wei>a.wei);
	}
};

vector<ROAD> cross[MAXC], tree[MAXC];
int cost[MAXC][MAXC], sta[MAXC];
bool staw[MAXC];

void Input(int c, int s){
    ROAD tmp;
    for(int i=1; i<=c; i++){
		cross[i].clear();   tree[i].clear();
    }
	for(int i=0; i<s; i++){
		scanf("%d %d %d", &tmp.from, &tmp.to, &tmp.wei);
		cross[tmp.from].push_back(tmp);
		cross[tmp.to].push_back(ROAD(tmp.to, tmp.from, tmp.wei));
	}
	memset(cost, -1, sizeof(cost));
}

void Solve_MST(int c){
	priority_queue<ROAD> pq;	bool walk[MAXC] = {0};
	for(int j=1; j<=c; j++)if( !walk[j] ){  // if the graph has several SCC
		pq.push(ROAD(j,j,-1));
		while( !pq.empty() ){    // MST_Prim
			ROAD now = pq.top();    	pq.pop();		int t = now.to;
			if( walk[t] )  continue;	walk[t] = true;
            tree[now.from].push_back(now);
			tree[t].push_back(ROAD(now.to, now.from, now.wei));
			for(int i=0,j=cross[t].size(); i<j; i++)
			if( !walk[cross[t][i].to] )  pq.push(cross[t][i]);
	}	}
}

void dfs(int start, int max_dis, int num){
	cost[sta[0]][sta[num-1]] = cost[sta[num-1]][sta[0]] = max_dis;
	for(int i=0,j=tree[start].size(); i<j; i++)
	if( !staw[tree[start][i].to] ){
        staw[tree[start][i].to] = true;
		sta[num] = tree[start][i].to;
        dfs(tree[start][i].to, max(max_dis, tree[start][i].wei), num+1);
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int C, S, Q, cc=0;
	while( scanf("%d %d %d", &C, &S, &Q) && C ){
		if( cc )    putchar('\n');
        Input(C, S);
		Solve_MST(C);
		printf("Case #%d\n", ++cc);
		bool used[MAXC]={0};
		for(int i=0; i<Q; i++){ // record the asked and searched queries
			scanf("%d %d", &C, &S);
			if( cost[C][S]!=-1 )    printf("%d\n", cost[C][S]);
			else if( used[C] )		puts("no path");
			else {
				memset(staw, 0, sizeof(staw));  staw[C] = true;
				sta[0] = C;	dfs(C,0,1);	used[C] = true;
				if( cost[C][S]!=-1 )    printf("%d\n", cost[C][S]);
				else                    puts("no path");
			}
		}
	}
	return 0;
}
