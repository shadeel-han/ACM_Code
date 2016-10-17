/*
ID: j9010311
PROG: ttwo
LANG: C++
*/

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
#define INF 1000000000
#define MAXX 160000

struct OB{
    int x;
    int y;
    int dir; // 0=N, 1=E, 2=S, 3=W
};

int arr[2][11][11][4][2];  // farm/cow, coorx, coory, N/E/S/W, first/second time
char map[12][12];
bool meet[MAXX];
int walk[2][11][11][4];

int main(){
    
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    
    int i, j, k, tim, ans, start, dif;
    OB farm, cow;
    char in[12];
    queue<OB> que;
    
    for( i=0; i<12; ++i ){
        map[0][i] = '*';
        map[11][i] = '*';
        map[i][0] = '*';
        map[i][11] = '*';
    }
    
    while( gets(in)!=NULL ){

        for( i=0; i<10; ++i )
            map[1][i+1] = in[i];
        for( i=2; i<11; ++i ){
            gets(in);
            for( j=0; j<10; ++j )
            map[i][j+1] = in[j];
        }
        
        memset(walk,0,sizeof(walk));
        memset(arr,-1,sizeof(arr));
        for( i=1; i<11; ++i )
        for( j=1; j<11; ++j ){
            if( map[i][j]=='F' ){
                farm.x = i;
                farm.y = j;
                farm.dir = 0;
                arr[0][i][j][0][0] = 0;
                ++walk[0][i][j][0];
                map[i][j] = '.';
            }
            if( map[i][j]=='C' ){
                cow.x = i;
                cow.y = j;
                cow.dir = 0;
                arr[1][i][j][0][0] = 0;
                ++walk[1][i][j][0];
                map[i][j] = '.';
            }
        }
        
        tim = 0;
        que.push(farm);
        while( !que.empty() ){
            farm = que.front();
            que.pop();
            ++tim;
            if( farm.dir==0 ){
                if( map[farm.x-1][farm.y]!='*' )    --farm.x;
                else                                farm.dir = 1;
            }
            else if( farm.dir==1 ){
                if( map[farm.x][farm.y+1]!='*' )    ++farm.y;
                else                                farm.dir = 2;
            }
            else if( farm.dir==2 ){
                if( map[farm.x+1][farm.y]!='*' )    ++farm.x;
                else                                farm.dir = 3;
            }
            else{
                if( map[farm.x][farm.y-1]!='*' )    --farm.y;
                else                                farm.dir = 0;
            }
            
            if( arr[0][farm.x][farm.y][farm.dir][0]==-1 ){
                arr[0][farm.x][farm.y][farm.dir][0] = tim;
                que.push(farm);
                ++walk[0][farm.x][farm.y][farm.dir];
            }
            else if( arr[0][farm.x][farm.y][farm.dir][1]==-1 ){
                arr[0][farm.x][farm.y][farm.dir][1] = tim;
                que.push(farm);
                ++walk[0][farm.x][farm.y][farm.dir];
            }
        }
        
        tim = 0;
        que.push(cow);
        while( !que.empty() ){
            cow = que.front();
            que.pop();
            ++tim;
            if( cow.dir==0 ){
                if( map[cow.x-1][cow.y]!='*' )  --cow.x;
                else                            cow.dir = 1;
            }
            else if( cow.dir==1 ){
                if( map[cow.x][cow.y+1]!='*' )  ++cow.y;
                else                            cow.dir = 2;
            }
            else if( cow.dir==2 ){
                if( map[cow.x+1][cow.y]!='*' )  ++cow.x;
                else                            cow.dir = 3;
            }
            else{
                if( map[cow.x][cow.y-1]!='*' )  --cow.y;
                else                            cow.dir = 0;
            }
            
            if( arr[1][cow.x][cow.y][cow.dir][0]==-1 ){
                arr[1][cow.x][cow.y][cow.dir][0] = tim;
                que.push(cow);
                ++walk[1][cow.x][cow.y][cow.dir];
            }
            else if( arr[1][cow.x][cow.y][cow.dir][1]==-1 ){
                arr[1][cow.x][cow.y][cow.dir][1] = tim;
                que.push(cow);
                ++walk[1][cow.x][cow.y][cow.dir];
            }
        }
        
        ans = INF;
        for( i=1; i<11; ++i )
        for( j=1; j<11; ++j )
            if( (walk[0][i][j][0] || walk[0][i][j][1] || walk[0][i][j][2] || walk[0][i][j][3] ) && 
                (walk[1][i][j][0] || walk[1][i][j][1] || walk[1][i][j][2] || walk[1][i][j][3] ) ){
                memset(meet,0,sizeof(meet));
                for( k=0; k<4; ++k ){
                    if( !walk[0][i][j][k] )         continue;
                    else if( walk[0][i][j][k]==1 )  meet[arr[0][i][j][k][0]] = true;
                    else
                    for( start=arr[0][i][j][k][0],dif=arr[0][i][j][k][1]-arr[0][i][j][k][0]; start<MAXX && start<ans; start+=dif )
                        meet[start] = true;
                }
                for( k=0; k<4; ++k ){
                    if( !walk[1][i][j][k] )         continue;
                    else if( walk[1][i][j][k]==1 ){
                        if( meet[arr[1][i][j][k][0]] && (ans>arr[1][i][j][k][0]) )
                            ans = arr[1][i][j][k][0];
                    }
                    else
                    for( start=arr[1][i][j][k][0],dif=arr[1][i][j][k][1]-arr[1][i][j][k][0]; start<MAXX && start<ans; start+=dif )
                    if( meet[start] )   ans = start;
                }
            }
        
        if( ans==INF )  puts("0");
        else            printf("%d\n", ans);
    }
    
    return 0;
}
