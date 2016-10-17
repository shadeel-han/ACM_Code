/*
ID: j9010311
PROG: cowtour
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAXX 151

int cnt[MAXX][MAXX], x[MAXX], y[MAXX];
double dis[MAXX][MAXX], lon[MAXX], ans;

int main(){
    
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    
    char in[152];
    int i, j, k, m, num;
    int set[MAXX];
    double setlon[MAXX], tmp;
    queue<int> que;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%d %d", &x[i], &y[i]);
        
        for( i=0; i<num; ++i ){
            setlon[i] = 0.0;
            lon[i] = 0.0;
            scanf("%s", in);
            for( j=0; j<num; ++j ){
                if( in[j]=='1' )    cnt[i][j] = 1;
                else                cnt[i][j] = 0;
                
                if( cnt[i][j] )
                    dis[i][j] = sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) );
                else
                    dis[i][j] = 1000000000.0;
            }
        }
        
        
        memset(set,0,sizeof(set));
        for( i=0,m=0; i<num; ++i )
            if( !set[i] ){
                set[i] = ++m;
                que.push(i);
                while( !que.empty() ){
                    k = que.front();
                    que.pop();
                    for( j=0; j<num; ++j ){
                        if( !cnt[k][j] )    continue;
                        if( set[j] )   continue;
                        else{
                            set[j] = m;
                            que.push(j);
                        }
                    }
                }
            }
        
        for( k=0; k<num; ++k )
        for( i=0; i<num; ++i )
        for( j=0; j<num; ++j )
            if( i!=j && k!=j ){
                if( dis[i][j] > dis[i][k] + dis[k][j] )
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        
        // lon[i] is the longest dinstance from i to the node in the same set
        // setlon[i] is the longset distance of lon in the same set i
        for( i=0; i<num; ++i )
        for( j=0; j<num; ++j )
            if( (i!=j) && (set[i]==set[j]) && (lon[i] < dis[i][j]) ){
                lon[i] = dis[i][j];
                if( setlon[set[i]] < lon[i] )
                    setlon[set[i]] = lon[i];
            }
        
        for( i=0; i<num; ++i )
        for( j=0; j<num; ++j )
            if( set[i]!=set[j] )
            dis[i][j] = sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) );
        
        ans = 1000000000.0;
        for( i=0; i<num; ++i )
        for( j=0; j<num; ++j )
            if( (set[i]!=set[j])  ){
                tmp = lon[i] + lon[j] + dis[i][j];
                ans = min(ans,max(tmp,max(setlon[set[i]],setlon[set[j]])));
            }
        
        printf("%lf\n", ans);
    }
    
    return 0;
}
