/*
ID: j9010311
PROG: fence
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXX 501

vector<int> road[MAXX];
int deg[MAXX], ans[1025], ansindex;


// chech whether the graph is connected
/*bool bfs( int start ){
    
    bool pass[MAXX]={0};
    queue<int> que;
    int now, next, i, j;
    
    que.push(start);
    pass[start] = true;
    
    while( !que.empty() ){
        now = que.front();
        que.pop();
        for( i=0,j=road[now].size(); i<j; ++i )
            if( !pass[road[now][i]] ){
                pass[road[now][i]] = true;
                que.push(road[now][i]);
            }
    }
    
    for( i=0; i<MAXX; ++i )
        if( !pass[i] )
            return false;
    else    return true;
}*/

void traverse( int in ){
    
    while( road[in].size() ){
        int next = road[in][0], i, j;
        road[in].erase(road[in].begin());
        for( i=0,j=road[next].size(); i<j; ++i )
            if( road[next][i]==in ) break;
        road[next].erase(road[next].begin()+i);
        traverse(next);
    }
    ans[ansindex++] = in;
}

int main(){
    
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    
    int i, j, num, from, to;
    
    while( scanf("%d", &num)!=EOF ){
        
        memset(deg,0,sizeof(deg));
        for( i=1; i<MAXX; ++i )
            road[i].clear();
        for( i=0; i<num; ++i ){
            scanf("%d %d", &from, &to);
            road[from].push_back(to);
            road[to].push_back(from);
            ++deg[from];
            ++deg[to];
        }
        // for smallest dictionary ordering answer
        for( i=1; i<MAXX; ++i )
            sort(road[i].begin(),road[i].end());
        
        /* Eulerian path detection: two nodes hav odd degree */
        /*for( i=0,j=0; i<MAXX; ++i )
            if( deg[i]&1 )  ++j;
        if( j!=2 ){
            puts("no Eulerian path");
            continue;
        }*/
        
        /* Eulerian cycle detection: all nodes have even degree */
        /*for( i=0; i<MAXX; ++i )
            if( deg[i]&1 )  break;
        if( i<MAXX ){
            puts("no Eulerian cycle");
            continue;
        }*/
        
        /* BFS to check whether the graph is connected */
        /*if( !bfs(0) ){
            puts("the graph is not connected");
            continue;
        }*/
        
        // find path: start from a node with odd degree 
        // find cycle: start from a node according to the problem 
        for( i=1,j=0; i<MAXX; ++i )
            if( deg[i]&1 ){
                ++j;
                break;
            }
        // if the graph has nodes with odd gedree
        if( j ){
            for( i=1; i<MAXX; ++i )
                if( deg[i]&1 )  break;
        }
        // if the graph has no node with odd degree
        else{
            for( i=1; i<MAXX; ++i )
                if( deg[i] )    break;
        }
        ansindex = 0;
        traverse(i);
        
        for( i=ansindex-1; i>=0; --i )
            printf("%d\n", ans[i]);
        
    }
    
    return 0;
}
