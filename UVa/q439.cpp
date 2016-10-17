#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct COOR{
	int x, y;
	COOR(int x, int y):x(x),y(y) {};
	COOR operator+(const COOR& a){
		return COOR(x+a.x, y+a.y);
	}
};

int traverse(COOR from, COOR to){
	char board[8][8];	queue<COOR> que;
	int dx[8]={-1,-2,-2,-1,1,2,2,1}, dy[8]={2,1,-1,-2,-2,-1,1,2};

	memset(board,-1,sizeof(board));
	que.push(from); board[from.x][from.y] = 0;
    while( !que.empty() ){
		COOR now = que.front();  que.pop();
		for(int i=0; i<8; ++i){
			COOR tmp = now + COOR(dx[i],dy[i]);
			if( board[tmp.x][tmp.y]==-1 && tmp.x>=0 && tmp.x<8 && tmp.y>=0 && tmp.y<8 ){
                board[tmp.x][tmp.y] = board[now.x][now.y]+1;
                que.push(tmp);
			}
		}
    }
    return (int)board[to.x][to.y];
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char from[5], to[5];
	
	while( scanf("%s %s", from, to)!=EOF ){
		COOR f(from[0]-'a',from[1]-'1'), t(to[0]-'a',to[1]-'1');
		printf("To get from %s to %s takes %d knight moves.\n", from, to, traverse(f,t));
	}
	
	return 0;
}
