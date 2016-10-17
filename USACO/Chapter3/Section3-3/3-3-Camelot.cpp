/*
ID: j9010311
PROG: camelot
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

struct COOR{
    int t;
    char x;
    char y;
    int index;
};

COOR kn[780];
int dp[27][31][781][2];
queue<COOR> que;

int main(){
    
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    
    int i, j, k, row, col, kingx, kingy, num, tmp, tmp2, ans;
    int movex[8]={1,2,2,1,-1,-2,-2,-1}, movey[8]={2,1,-1,-2,-2,-1,1,2};
    char in;
    COOR now, next;
    
    while( scanf("%d %d\n", &row, &col)!=EOF ){
        
        scanf("%c %d\n", &in, &kingy);
        kingx = in-'A'+1;
        num = 0;
        while( scanf("%c %d\n", &in, &kn[num].y)!=EOF ){
            kn[num].x = in-'A'+1;
            kn[num].t = 0;
            kn[num].index = num;
            ++num;
        }
        
        memset(dp,-1,sizeof(dp));
        for( i=1; i<=col; ++i )
            for( j=1; j<=row; ++j ){
                tmp = abs(i-kingx);
                tmp2 = abs(j-kingy);
                dp[i][j][num][0] = (tmp>tmp2)?(tmp):(tmp2);
            }
        
        for( i=0; i<num; ++i ){
            dp[kn[i].x][kn[i].y][i][0] = 0;
            que.push(kn[i]);
            dp[kn[i].x][kn[i].y][i][1] = dp[kn[i].x][kn[i].y][num][0];
        }
        while( !que.empty() ){
            
            now = que.front();
            que.pop();
            for( i=0; i<8; ++i ){
                
                next.x = now.x + movex[i];
                next.y = now.y + movey[i];
                
                if( next.x<1 || next.x>col || next.y<1 || next.y>row )
                    continue;
                
                next.index = now.index;
                next.t = now.t + 1;
                if( dp[next.x][next.y][next.index][0]==-1 ){
                    dp[next.x][next.y][next.index][0] = next.t;
                    que.push(next);
                }
                if( dp[next.x][next.y][next.index][1]==-1 ){
                    if( dp[now.x][now.y][now.index][1]+1 < next.t+dp[next.x][next.y][num][0] )
                        dp[next.x][next.y][next.index][1] = dp[now.x][now.y][now.index][1]+1;
                    else
                        dp[next.x][next.y][next.index][1] = next.t+dp[next.x][next.y][num][0];
                }
                else if( dp[next.x][next.y][next.index][1] > next.t+dp[next.x][next.y][num][0] ){
                    dp[next.x][next.y][next.index][1] = next.t+dp[next.x][next.y][num][0];
                    que.push(next);
                }
                else if( dp[next.x][next.y][next.index][1] > dp[now.x][now.y][now.index][1]+1 ){
                    dp[next.x][next.y][next.index][1] = dp[now.x][now.y][now.index][1]+1;
                    que.push(next);
                }
            }
        }
        
        for( i=1,ans=1000000000; i<=col; ++i )
            for( j=1; j<=row; ++j ){
                for( k=0,tmp=0; k<num; ++k ){
                    if( dp[i][j][k][0]==-1 )    break;
                    tmp += dp[i][j][k][0];
                }
                if( k<num ) continue;
                if( ans > tmp + dp[i][j][num][0] )
                    ans = tmp + dp[i][j][num][0];
                for( k=0; k<num; ++k ){
                    if( dp[i][j][k][1]==-1 )    continue;
                    if( ans > tmp-dp[i][j][k][0]+dp[i][j][k][1] )
                        ans = tmp-dp[i][j][k][0]+dp[i][j][k][1];
                }
            }
        
        printf("%d\n", ans);
        
    }
    
    return 0;
}
