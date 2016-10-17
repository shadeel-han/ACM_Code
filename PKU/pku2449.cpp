// Kth NonSimple Path

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define INF 1000000000

typedef struct{
    int to;
    int weight;
}ROAD;
vector<ROAD> road[1001], rev[1001];

int dis[1001];
struct NODE //For the A* search.
{
	int to, cost;
	bool operator < (const NODE &k) const
	{
		return (cost+dis[to]) > (k.cost+dis[k.to]);
	}	// priority min-que
};

int Astar( int source, int sink, int kth ){
    
    if( dis[sink]==INF ) return -1;
    if( source==sink )  ++kth;  // a tricky special case, because source(sink) will be put in the queue at the begining
    
    priority_queue<NODE> que;
    
    NODE now, next;
	int passtime[1001], i, tmp;
	memset(passtime, 0, sizeof(passtime));

	now.to = source;
    now.cost = 0;
    que.push(now);
	while( !que.empty() )
	{
		now = que.top();
		que.pop();

		++passtime[now.to];
		if( passtime[sink]==kth ) return now.cost;  // passing the target kth time means the kth path was found
		if( passtime[now.to] > kth ) continue;      // Owing to using the priority queue, always examine the cost from the cheapest one
		
		tmp = road[now.to].size();
		for(i=0; i<tmp; i++){
			next.to = road[now.to][i].to;
			next.cost = road[now.to][i].weight + now.cost;
			que.push(next);
		}
	}
	return -1;
    
}

void SPFA( int start ){  //find the shortest path from taregt to every other station
    
    queue<int> que;
    bool inqueue[1001];
    int i, now, num, to;
    
    memset(inqueue,false,sizeof(inqueue));
        
    dis[start] = 0;
    que.push(start);
    inqueue[start] = true;
    while( !que.empty() ){
        
        now = que.front();
        que.pop();
        inqueue[now] = false;
        num = rev[now].size();
        for( i=0; i<num; ++i ){
            
            to = rev[now][i].to;
            if( dis[to] > rev[now][i].weight + dis[now] ){
                
                dis[to] = rev[now][i].weight + dis[now];
                if( !inqueue[to] ){
                    que.push(to);
                    inqueue[to] = true;
                }
                
            }   
        }
    }
    
}

int main(){
    
    int i, j, num, ver, st, end, cost, source, sink, kth;
    ROAD tmp;
    
    while( scanf("%d %d", &ver, &num)!=EOF ){
        
        for( i=1; i<=ver; ++i ){
            road[i].clear();
            rev[i].clear();
            dis[i] = INF;
        }
        
        for( i=0; i<num; ++i ){
            scanf("%d %d %d", &st, &end, &cost);
            tmp.weight = cost;
            tmp.to = end;
            road[st].push_back(tmp);
            tmp.to = st;
            rev[end].push_back(tmp);
        }
        
        scanf("%d %d %d", &source, &sink, &kth);
        SPFA( sink );
        
        printf("%d\n",Astar( source, sink, kth ));
        
    }
    
    return 0;
}
