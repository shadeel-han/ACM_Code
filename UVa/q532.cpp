#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct COOR{
	int x, y, z;
	COOR(int x, int y, int z):x(x),y(y),z(z) {};
	COOR operator+(const COOR& a){
		return COOR(x+a.x, y+a.y, z+a.z);
	}
};

char maze[32][32][32];

void SearchSE(int x, int y, int z, COOR &s, COOR &e){
    for(int i=1; i<=x; ++i) for(int j=1; j<=y; ++j) for(int k=1; k<=z; ++k){
		if( maze[i][j][k]=='S' )    s = COOR(i,j,k);
		if( maze[i][j][k]=='E' )    e = COOR(i,j,k);
    }
}

int traverse(COOR from, COOR to){
	int board[32][32][32];	queue<COOR> que;
	int dx[6]={-1,1,0,0,0,0}, dy[6]={0,0,-1,1,0,0}, dz[6]={0,0,0,0,1,-1};

	if( !from.x || !to.x )  return -1;
	memset(board,-1,sizeof(board));
	que.push(from); board[from.x][from.y][from.z] = 0;
    while( !que.empty() ){
		COOR now = que.front();  que.pop();
		for(int i=0; i<6; ++i){
			COOR tmp = now + COOR(dx[i],dy[i],dz[i]);
			if( board[tmp.x][tmp.y][tmp.z]==-1 && maze[tmp.x][tmp.y][tmp.z]!='#' ){
                board[tmp.x][tmp.y][tmp.z] = board[now.x][now.y][now.z]+1;
                que.push(tmp);
			}
		}
    }
    return board[to.x][to.y][to.z];
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int x, y, z;
	while( scanf("%d %d %d", &x, &y, &z) && !(!x && !y && !z) ){
		memset(maze,'#',sizeof(maze));
		for(int i=1; i<=x; ++i) for(int j=1; j<=y; ++j)
		    scanf("%s", maze[i][j]+1);
        COOR s(0,0,0), e(0,0,0);
		SearchSE(x,y,z,s,e);
		int ans = traverse(s,e);
		if( ans>0 )	printf("Escaped in %d minute(s).\n", ans);
		else        puts("Trapped!");
	}

	return 0;
}
