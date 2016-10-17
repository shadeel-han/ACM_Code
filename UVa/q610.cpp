/*
	find cut vertex (articulation point)
	vertex index: 1~n
	edge direction: bidirection (as input)
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct ANS{
	int x, y;
	ANS(int x, int y):x(x),y(y) {};
	bool operator<(const ANS& a) const{
		if( x < a.x )	return true;
		else if( (x==a.x) && (y<a.y) )	return true;
		else							return false;
	}
};

class CutVertex{
	public:
		#define MAXN 1001
		#define MAXE 4001
		vector<ANS> graph[MAXN], ans;
		int dfn[MAXN], low[MAXN], edg[MAXE], cnt, Vnum, Enum;
		
	public:
		void dfnlow(int u, int v){	// v is parent of u
			dfn[u] = low[u] = cnt++;
			for(int i=0,j=graph[u].size(); i<j; i++){
				int w = graph[u][i].x;
				if( !edg[graph[u][i].y] ){
					ans.push_back(ANS(u,w)); edg[graph[u][i].y]++;
				}
				if( dfn[w]<0 ){		// w isn't visited, so w is child of u
					dfnlow(w,u);
					low[u] = (low[u]<low[w])?(low[u]):(low[w]);
					if( low[w]>dfn[u] )	ans.push_back(ANS(w,u));
				}else if( w!=v )
					low[u] = (low[u]<low[w])?(low[u]):(low[w]);
			}
		}
		
		void Initial(void){
			for(int i=1; i<=Vnum; i++)	graph[i].clear();
			memset(dfn, -1, sizeof(dfn));
			memset(low, -1, sizeof(low));
			memset(edg, 0, sizeof(edg));
			ans.clear();	cnt = 0;
		}
		
		void FindCutVertex(void){
			for(int i=1; i<=Vnum; i++)
			if( dfn[i]==-1 )	dfnlow(i,-1);
		}
};

CutVertex my;

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int f, t, c=0;
	
	while( scanf("%d %d", &my.Vnum, &my.Enum) ){
		if( !my.Vnum && !my.Enum )	break;
		my.Initial();
		for(int i=0; i<my.Enum; i++){
			scanf("%d %d", &f, &t);
			my.graph[f].push_back(ANS(t,i));
			my.graph[t].push_back(ANS(f,i));
		}
		
		my.FindCutVertex();
		sort(my.ans.begin(), my.ans.end());
		
		printf("%d\n\n", ++c);
		for(int i=0,j=my.ans.size(); i<j; i++)	printf("%d %d\n", my.ans[i].x, my.ans[i].y);
		puts("#");
	}
	
	return 0;
}

