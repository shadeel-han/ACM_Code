/*
ID: j9010311
PROG: concom
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool ans[101][101];
int own[101][101];

int main(){
    
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    
    int i, j, num, from, to, tmp;
    int p[101];
    queue<int> que;
    
    while( scanf("%d", &num)!=EOF ){
        
        memset(own,0,sizeof(own));
        memset(ans,0,sizeof(ans));
        for( i=0; i<num; ++i ){
            scanf("%d %d %d", &from, &to, &tmp);
            own[from][to] = tmp;
        }
        
        for( i=1; i<101; ++i ){
            que.push(i);
            ans[i][i] = true;
            memset(p,0,sizeof(p));
            while( !que.empty() ){
                from = que.front();
                que.pop();
                for( j=1; j<101; ++j ){
                    if( own[from][j] )
                        p[j] += own[from][j];
                    if( p[j]>50 && !ans[i][j] ){
                        ans[i][j] = true;
                        que.push(j);
                    }
                }
            }
            ans[i][i] = false;
        }
        
        for( i=1; i<101; ++i )
        for( j=1; j<101; ++j )
            if( ans[i][j] )
                printf("%d %d\n", i, j);
    }
    
    return 0;
}
