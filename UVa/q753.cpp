/*
	Maximum Flow ( Ford_Fulkerson and Edmonds-Karp )
	vertex index: 1~n, source is 1 and sink is n ( may change according to diffrent usage )
	edge direction: bidirection for residual network (as input)
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;
#define INF (int)1e9

class MaximumFlow{
	public:
		#define MAXV 405
		#define MAXE 40000
		#define MIN(a,b) (((a)<(b))?(a):(b))
		struct NODE{
			int to, index;
			NODE(){};
			NODE(int a, int b):to(a),index(b) {};
		};
		
		vector<NODE> node[MAXV];
		map<int,int> hash_edge;
		int Vnum, Enum, cap[MAXE], flow[MAXE],  max_flow, tol_edge;
		
	public:
		void Ford_Fulkerson(int source, int sink){
			int now, next, visit[MAXV]={0}, round = 1;
			queue<int> que;	NODE path[MAXV];
			while(1){
				while( !que.empty() )	que.pop();
				que.push(source);	visit[source] = round;
				while( !que.empty() && visit[sink]!=round ){	// revised by Edmonds_Karp
					now = que.front();	que.pop();
					for(int i=0,j=node[now].size(); i<j; i++){
						next = node[now][i].to;
						if( visit[next]==round )	continue;
						int edge_num=node[now][i].index, edge_rev=(edge_num&1)?(edge_num-1):(edge_num+1);
						if( cap[edge_num]-flow[edge_num] > 0 ){	// positive flow
							path[next] = NODE(now, edge_num);	visit[next] = round;	que.push(next);
						}else if( flow[edge_rev] > 0 ){			// opposite flow
							path[next] = NODE(-now, edge_rev);	visit[next] = round;	que.push(next);
						}
					}
				}
				if( visit[sink]!=round )	break;		// stop if not find augmenting path
				else 						round++;	// otherwise, there will be next round
				
				int minf = INF;
				for(int i=sink; i!=source; ){	// update the flow
					if( path[i].to>=0 )	minf = MIN(minf,cap[path[i].index]-flow[path[i].index]), i=path[i].to;
					else				minf = MIN(minf,flow[path[i].index]), i=-path[i].to;
				}
				for(int i=sink; i!=source; ){
					if( path[i].to>=0 )	flow[path[i].index] += minf, i=path[i].to;
					else				flow[path[i].index] -= minf, i=-path[i].to;
				}
				max_flow += minf;
			}
		}
		
		void Initial(void){
			for(int i=0; i<=Vnum; i++)	node[i].clear();
			hash_edge.clear();	max_flow = tol_edge = 0;
			memset(cap, 0, sizeof(cap));
			memset(flow, 0, sizeof(flow));
		}
		
		void Build_Edge(int a, int b, int c){	// a and b are index number of nodes, c is capacity
			int hash_num = a*MAXV + b, hash_rev = b*MAXV + a;
			if( hash_edge.find(hash_num)==hash_edge.end() ){	// deal with multiple edges
				node[a].push_back(NODE(b,tol_edge));	hash_edge[hash_num] = tol_edge++;
				node[b].push_back(NODE(a,tol_edge));	hash_edge[hash_rev] = tol_edge++;
			}
			cap[hash_edge[hash_num]] += c;
		}
		
};

MaximumFlow my;
map<string,int> dict;

struct STORE{
	STORE(){};
	STORE(int x, int y):a(x),index(y) {};
	int a, index;
};
STORE rec[100], dev[100], ada[200];

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, n, m, k, node_num, dict_num;
	char name[30];
	scanf("%d", &cas);
	
	while( cas-- ){
		if( c++ )	putchar('\n');
		dict.clear();	node_num = dict_num = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%s", name);	string str(name);
			if( dict.find(str)==dict.end() )
				dict[str] = ++dict_num;
			rec[i] = STORE(dict[str], ++node_num);
		}
		scanf("%d", &m);
		for(int i=0; i<m; i++){
			scanf("%s", name);	scanf("%s", name);	string str(name);
			if( dict.find(str)==dict.end() )
				dict[str] = ++dict_num;
			dev[i] = STORE(dict[str], ++node_num);
		}
		scanf("%d", &k);
		for(int i=0; i<k; i++){
			scanf("%s", name);	string str(name);
			if( dict.find(str)==dict.end() )
				dict[str] = ++dict_num;
			ada[i] = STORE(dict[str], ++node_num);
			scanf("%s", name);	str = string(name);
			if( dict.find(str)==dict.end() )
				dict[str] = ++dict_num;
			ada[i+k] = STORE(dict[str], ++node_num);
		}
		
		my.Vnum = ++node_num;	my.Initial();
		for(int i=0; i<m; i++){
			my.Build_Edge(0, dev[i].index, 1);
			for(int j=0; j<n; j++)
			if( dev[i].a==rec[j].a )	my.Build_Edge(dev[i].index, rec[j].index, 1);
			for(int j=0; j<k; j++)
			if( dev[i].a==ada[j].a )	my.Build_Edge(dev[i].index, ada[j].index, 1);
		}
		for(int i=0; i<n; i++){
			my.Build_Edge(rec[i].index, my.Vnum, 1);
			for(int j=0; j<k; j++)
			if( rec[i].a==ada[j+k].a )	my.Build_Edge(ada[j+k].index, rec[i].index, 1);
		}
		for(int i=0; i<k; i++)for(int j=0; j<k; j++){
			if( i==j )						my.Build_Edge(ada[i].index, ada[j+k].index, INF);
			else if( ada[i].a==ada[j+k].a )	my.Build_Edge(ada[j+k].index, ada[i].index, INF);
		}
		my.Ford_Fulkerson(0, my.Vnum);
		printf("%d\n", m-my.max_flow);
	}
	
	return 0;
}

