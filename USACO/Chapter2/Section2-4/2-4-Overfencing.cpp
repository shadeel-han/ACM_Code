/*
ID: j9010311
PROG: maze1
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct COOR{
    int x;
    int y;
    int t;
};

char maze[205][80];
int arr[205][80];

int main(){
    
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    
    int i, j, w, h, m, n, ans;
    char in[80];
    queue<COOR> que;
    COOR tmp, now;
    
    while( scanf("%d %d\n", &w, &h)!=EOF ){
        
        m = w*2;
        n = h*2;
        for( i=0; i<=(w+1); ++i ){
            maze[0][i] = '*';
            maze[h+1][i] = '*';
        }
        
        for( i=0; i<=n; ++i ){
            gets(in);
            for( j=0; j<=m; ++j )
                if( in[j]==' ' )    maze[i][j] = ' ';
                else                maze[i][j] = '*';
        }
        
        memset(arr,0,sizeof(arr));
        tmp.t = 1;
        for( i=1; i<m; i+=2 ){
            if( maze[0][i]==' ' ){
                maze[0][i] = '*';
                arr[1][i] = 1;
                tmp.x = 1;
                tmp.y = i;
                que.push(tmp);
            }
            if( maze[n][i]==' ' ){
                maze[n][i] = '*';
                arr[n-1][i] = 1;
                tmp.x = n-1;
                tmp.y = i;
                que.push(tmp);
            }
        }
        for( i=1; i<n; i+=2 ){
            if( maze[i][0]==' ' ){
                maze[i][0] = '*';
                arr[i][1] = 1;
                tmp.x = i;
                tmp.y = 1;
                que.push(tmp);
            }
            if( maze[i][m]==' ' ){
                maze[i][m] = '*';
                arr[i][m-1] = 1;
                tmp.x = i;
                tmp.y = m-1;
                que.push(tmp);
            }
        }
        
        ans = 0;
        while( !que.empty() ){
            now = que.front();
            que.pop();
            tmp.t = now.t+1;
            ans = tmp.t;
            if( maze[now.x+1][now.y]==' ' && !arr[now.x+2][now.y] ){
                tmp.x = now.x + 2;
                tmp.y = now.y;
                arr[tmp.x][tmp.y] = tmp.t;
                que.push(tmp);
            }
            if( maze[now.x-1][now.y]==' ' && !arr[now.x-2][now.y] ){
                tmp.x = now.x - 2;
                tmp.y = now.y;
                arr[tmp.x][tmp.y] = tmp.t;
                que.push(tmp);
            }
            if( maze[now.x][now.y+1]==' ' && !arr[now.x][now.y+2] ){
                tmp.x = now.x;
                tmp.y = now.y + 2;
                arr[tmp.x][tmp.y] = tmp.t;
                que.push(tmp);
            }
            if( maze[now.x][now.y-1]==' ' && !arr[now.x][now.y-2] ){
                tmp.x = now.x;
                tmp.y = now.y - 2;
                arr[tmp.x][tmp.y] = tmp.t;
                que.push(tmp);
            }
        }
        
        printf("%d\n", ans-1);
    }
    
    return 0;
}
