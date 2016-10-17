/*
	Maximum Flow ( Ford_Fulkerson and Edmonds-Karp )
	vertex index: 1~n, source is 1 and sink is n ( may change according to diffrent usage )
	edge direction: bidirection for residual network (as input)
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

class MaximumFlow{
	public:
		#define INF (int)1e9
		#define MAXV 5005
		#define MIN(a,b) ((a)<(b))?(a):(b)
		vector<int> node[MAXV];
		int Vnum, Enum, cap[MAXV][MAXV], flow[MAXV][MAXV], max_flow;
		
	public:
		void Ford_Fulkerson(int source, int sink){
			int now, next, p[MAXV], visit[MAXV];
			queue<int> que;
			while(1){
				memset(visit, 0, sizeof(visit));
				while( !que.empty() )	que.pop();
				que.push(source);	visit[source] = 1;
				while( !que.empty() && !visit[sink] ){			// revised by Edmonds_Karp
					now = que.front();	que.pop();
					for(int i=0,j=node[now].size(); i<j; i++){
						next = node[now][i];
						if( visit[next] )	continue;
						if( cap[now][next]-flow[now][next]>0 ){	// positive flow
							p[next] = now;	visit[next] = 1;	que.push(next);
						}else if( flow[next][now]>0 ){			// opposite flow
							p[next] = -now;	visit[next] = 1;	que.push(next);
						}
					}
				}
				if( !visit[sink] )	break;		// if not find augmenting path
				
				int minf = INF;
				for(int i=sink; i!=source; ){	// update the flow
					if( p[i]>=0 )	minf = MIN(minf,cap[p[i]][i]-flow[p[i]][i]), i=p[i];
					else			minf = MIN(minf,flow[i][-p[i]]), i=-p[i];
				}
				for(int i=sink; i!=source; ){
					if( p[i]>=0 )	flow[p[i]][i] += minf, i=p[i];
					else			flow[i][-p[i]] -= minf, i=-p[i];
				}
				max_flow += minf;
			}
		}
		
		void Initial(void){
			for(int i=0; i<=Vnum; i++)	node[i].clear();
			memset(cap, 0, sizeof(cap));
			memset(flow, -1, sizeof(flow));
			max_flow = 0;
		}
		
		void Build_Edge(int a, int b, int c){	// a and b are index number of nodes, c is capacity
			if( flow[a][b]==-1 ){	// deal with multiple edges
				node[a].push_back(b);	flow[a][b] = 0;
				node[b].push_back(a);	flow[b][a] = 0;
			}
			cap[a][b] += c;
		}
};

MaximumFlow my;

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, h, w, a, b, c;
	int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
	scanf("%d", &cas);
	
	while( cas-- ){
		scanf("%d %d %d", &h, &w, &c);
		my.Vnum = h*w*2 + 1;
		my.Initial();
		
		for(int i=0; i<c; i++){
			scanf("%d %d", &a, &b);
			int n = (a-1)*w+b;
			my.Build_Edge(0, n, 1);
		}
		for(int i=1; i<=h; i++)for(int j=1; j<=w; j++){
			int n = (i-1)*w+j, nn = n+h*w;
			my.Build_Edge(n, nn, 1);
			if( i==1 || i==h || j==1 || j==w ){
				my.Build_Edge(nn, my.Vnum, 1);
			}else{
				for(int k=0; k<4; k++){
					int tmp = (i+dx[k]-1)*w+j+dy[k];
					my.Build_Edge(nn, tmp, 1);
				}
			}
		}
		
		my.Ford_Fulkerson(0, my.Vnum);
		if( my.max_flow==c )	puts("possible");
		else					puts("not possible");
	}
	
	return 0;
}

