/*
ID: j9010311
PROG: butter
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define INF 1000000000
#define MAXX 801

struct NODE{
    int to;
    int cost;
};

vector<NODE> road[MAXX];
int stay[501], dis[MAXX];

void SPFA( int start ){
    
    queue<int> que;
    bool inqueue[MAXX];
    int now, next, i, j;
    
    memset(inqueue,0,sizeof(inqueue));
    que.push(start);
    inqueue[start] = true;
    dis[start] = 0;
    
    while( !que.empty() ){
        
        now = que.front();
        que.pop();
        inqueue[now] = false;
        
        for( i=0,j=road[now].size(); i<j; ++i ){
            next = road[now][i].to;
            if( dis[next] > dis[now] + road[now][i].cost ){
                dis[next] = dis[now] + road[now][i].cost;
                if( !inqueue[next] ){
                    inqueue[next] = true;
                    que.push(next);
                }
            }
        }
    }
}

int main(){
    
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    
    int i, j, cow, pas, path, ans, from, to;
    NODE tmp;
    
    while( scanf("%d %d %d", &cow, &pas, &path)!=EOF ){
        
        for( i=1; i<=pas; ++i )
            road[i].clear();
        for( i=0; i<cow; ++i )
            scanf("%d", &stay[i]);
        
        for( i=0; i<path; ++i ){
            scanf("%d %d %d", &from, &to, &tmp.cost);
            tmp.to = to;
            road[from].push_back(tmp);
            tmp.to = from;
            road[to].push_back(tmp);
        }
        
        for( i=1,ans=INF; i<=pas; ++i ){
            for( j=1; j<=pas; ++j )
                dis[j] = INF;
            SPFA(i);
            for( j=0,from=0; j<cow; ++j )
                from += dis[stay[j]];
            if( ans > from )
                ans = from;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
