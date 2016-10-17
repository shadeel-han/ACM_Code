#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define SIZE 250

struct COOR{
	int x, y;
	COOR() {};
	COOR(int x, int y):x(x),y(y) {};
	COOR operator+(const COOR& a){
		return COOR(x+a.x, y+a.y);
	}
};
char maze[SIZE][SIZE];

void ThreeTimesExtend(int w, int h){
	char in[80];
	memset(maze,'0',sizeof(maze));
	for(int i=0; i<h; ++i){
		scanf("%s", in);
		for(int j=0; j<w; ++j)
		if( in[j]=='\\' ){
			maze[i*3][j*3]='1';
			maze[i*3+1][j*3+1]='1';
			maze[i*3+2][j*3+2]='1';
		}
		else{
			maze[i*3][j*3+2]='1';
			maze[i*3+1][j*3+1]='1';
			maze[i*3+2][j*3]='1';
		}
	}
}

int BfsTraverse(int w, int h, int &len){
	queue<COOR> que;
	int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1}, ans=0, wlimit=w*3, hlimit=h*3, cnt;
	bool TouchBound;
	len = 0;
    // scan & bfs
    for(int i=0; i<hlimit; ++i) for(int j=0; j<wlimit; ++j)
	if( maze[i][j]=='0' ){
		que.push(COOR(i,j));	maze[i][j] = 0;
		TouchBound = false; cnt = 1;
    	while( !que.empty() ){
			COOR now = que.front();	que.pop();
			for(int k=0; k<4; ++k){
				COOR tmp = now + COOR(dx[k],dy[k]);
				if( tmp.x<0 || tmp.x>=hlimit || tmp.y<0 || tmp.y>=wlimit )
				    TouchBound = true;
				else if( maze[tmp.x][tmp.y]=='0' ){
                	maze[tmp.x][tmp.y] = 0; ++cnt;
                	que.push(tmp);
				}
			}
    	}
    	if( !TouchBound ){
			++ans;
			if( len < cnt ) len = cnt;
    	}
	}
    return ans;
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int w, h, c=0, len;
	while( scanf("%d %d", &w, &h) && w!=0 ){
		ThreeTimesExtend(w,h);
		int ans = BfsTraverse(w,h,len);
		printf("Maze #%d:\n", ++c);
		if( ans )   printf("%d Cycles; the longest has length %d.\n\n", ans, len/3);
		else        puts("There are no cycles.\n");
	}
	return 0;
}
