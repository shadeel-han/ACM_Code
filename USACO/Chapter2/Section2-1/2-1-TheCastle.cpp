/*
ID: j9010311
PROG: castle
LANG: C++
*/

#include <cstdio>
#include <queue>

using namespace std;

typedef struct{
    int num;
    bool north;
    bool south;
    bool east;
    bool west;
}MOD;
MOD maze[52][52]={0};

typedef struct{
    int x;
    int y;
}COOR;

int num, large;
int room[2501];

int main(){
    
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    
    int i, j, in, count, row, col;
    COOR tmp, now;
    
    while( scanf("%d %d", &col, &row)!=EOF ){
        
        /* read input and build maze */
        for( i=1; i<=row; ++i )
            for( j=1; j<=col; ++j ){
                maze[i][j].num = 0;
                scanf("%d", &in);
                if( in>=8 ){
                    maze[i][j].south = false;
                    in -= 8;
                }
                else    maze[i][j].south = true;
                if( in>=4 ){
                    maze[i][j].east = false;
                    in -= 4;
                }
                else    maze[i][j].east = true;
                if( in>=2 ){
                    maze[i][j].north = false;
                    in -= 2;
                }
                else    maze[i][j].north = true;
                if( in>=1 ){
                    maze[i][j].west = false;
                    in -= 1;
                }
                else    maze[i][j].west = true;
            }
        
        num = 0;
        large = 0;
        
        /* use bfs to decide the room number and area */
        for( i=1; i<=row; ++i )
            for( j=1; j<=col; ++j ){
                
                if( maze[i][j].num )    continue;
                else{
                    maze[i][j].num = ++num;
                    count = 1;
                    queue<COOR> que;
                    tmp.x = i;  tmp.y = j;
                    que.push(tmp);
                    while( !que.empty() ){
                        now = que.front();
                        que.pop();
                        
                        tmp.y = now.y;
                        tmp.x = now.x+1;
                        if( !maze[tmp.x][tmp.y].num && maze[now.x][now.y].south ){
                            maze[tmp.x][tmp.y].num = num;
                            que.push(tmp);
                            ++count;
                        }
                        tmp.x = now.x-1;
                        if( !maze[tmp.x][tmp.y].num && maze[now.x][now.y].north ){
                            maze[tmp.x][tmp.y].num = num;
                            que.push(tmp);
                            ++count;
                        }
                        tmp.x = now.x;
                        tmp.y = now.y+1;
                        if( !maze[tmp.x][tmp.y].num && maze[now.x][now.y].east ){
                            maze[tmp.x][tmp.y].num = num;
                            que.push(tmp);
                            ++count;
                        }
                        tmp.y = now.y-1;
                        if( !maze[tmp.x][tmp.y].num && maze[now.x][now.y].west ){
                            maze[tmp.x][tmp.y].num = num;
                            que.push(tmp);
                            ++count;
                        }
                    }
                    room[num] = count;
                    if( count > large )
                        large = count;
                }
            }
        
        printf("%d\n%d\n", num, large);
        
        /* try to remove the east and north wall in every module */
        for( j=1,large=0; j<=col; ++j )
            for( i=row; i>0; --i ){
                
                /* try to remove north eall */
                if( maze[i-1][j].num && maze[i-1][j].num!=maze[i][j].num  ){
                    in = room[maze[i-1][j].num] + room[maze[i][j].num];
                    if( in > large ){
                        large = in;
                        tmp.x = i;
                        tmp.y = j;
                        count = 1;
                    }
                }
                /* try to remove east eall */
                if( maze[i][j+1].num && maze[i][j+1].num!=maze[i][j].num  ){
                    in = room[maze[i][j+1].num] + room[maze[i][j].num];
                    if( in > large ){
                        large = in;
                        tmp.x = i;
                        tmp.y = j;
                        count = 2;
                    }
                }
            }
        
        printf("%d\n%d %d ", large, tmp.x, tmp.y);
        if( count==1 )  puts("N");
        else            puts("E");
    }
    
    return 0;
}
