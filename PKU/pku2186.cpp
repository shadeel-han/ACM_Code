#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define MAXX 10001

vector<int> road[MAXX], tran[MAXX], ng[MAXX], twoway[MAXX];
int order[MAXX], num, ngindex[MAXX], outde[MAXX];
bool used[MAXX];

void dfs( int index ){
    
    used[index] = true;
    int i, j=road[index].size();
    for( i=0; i<j; ++i ){
        if( used[road[index][i]] )  continue;
        dfs( road[index][i] );
    }
    order[num++] = index;
}

void reverse( int index ){
    
    used[index] = false;
    int i, j=tran[index].size();
    for( i=0; i<j; ++i ){
        if( !used[tran[index][i]] )  continue;
        reverse( tran[index][i] );
    }
    ngindex[index] = num;
    ng[num].push_back(index);
}

bool test_one_component( int source, int ver ){
    
    int i, j, now;
    queue<int> que;
    memset(used,0,sizeof(used));
    
    que.push(source);
    used[source] = true;
    
    while( !que.empty() ){
        now = que.front();
        que.pop();
        for( i=0,j=twoway[now].size(); i<j; ++i )
            if( !used[twoway[now][i]] ){
                used[twoway[now][i]] = true;
                que.push(twoway[now][i]);
            }
    }
    
    for( i=1; i<=ver; ++i )
        if( !used[i] )
            break;
    if( i<=ver )    return true;
    else            return false;
}

int main(){
    
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int i, j, k, m, n, ver, edge, from, to;
    
    while( scanf("%d %d", &ver, &edge)!=EOF ){
        
        // vertice number starts from 1
        for( i=1; i<=ver; ++i ){
            road[i].clear();
            tran[i].clear();
            twoway[i].clear();
            ng[i].clear();
        }
        for( i=0; i<edge; ++i ){
            scanf("%d %d", &from, &to);
            road[from].push_back(to);
            tran[to].push_back(from);
            twoway[from].push_back(to);
            twoway[to].push_back(from);
        }
        
        if( test_one_component(1,ver) ){
            puts("0");
            continue;
        }
        
        num = 0;
        memset(used,0,sizeof(used));
        // first dfs decides the traverse ending time
        for( i=1; i<=ver; ++i )
        if( !used[i] )
            dfs(i);
        
        num = 0;
        // second dfs counts the number of strongly connected component
        for( i=ver-1; i>=0; --i )
        if( used[order[i]] ){
            ++num;
            reverse(order[i]);
        }
        
        // count the outdegree of every SCC
        memset(outde,0,sizeof(outde));
        for( i=num; i>0; --i ){
            memset(used,0,sizeof(used));
            used[i] = true;
            for( j=0,k=ng[i].size(); j<k; ++j ){
                for( m=0,n=road[ng[i][j]].size(); m<n; ++m )
                    if( !used[ngindex[road[ng[i][j]][m]]] ){
                        used[ngindex[road[ng[i][j]][m]]] = true;
                        ++outde[i];
                    }
            }
        }
        
        for( i=num,j=0; i>0; --i )
            if( !outde[i] ) ++j;
        // if there are more than one SCC with 0 outdegree
        if( j>1 )
            puts("0");
        else{
            for( i=num; i>0; --i )
                if( !outde[i] ) break;
            printf("%d\n", ng[i].size());
        }
        
    }
    
    return 0;
}
