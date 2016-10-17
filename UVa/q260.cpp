#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct COOR{
	int r, c;
	COOR(int r, int c):r(r),c(c) {};
	COOR operator+(const COOR& a){
		return COOR(r+a.r, c+a.c);
	}
};

char board[202][202];

void input(int n){
	memset(board, 0, sizeof(board));
	for(int i=1; i<=n; ++i)	scanf("%s", board[i]+1);
}

int bfs_check(int n){
    int dx[6]={-1,-1,0,0,1,1}, dy[6]={-1,0,-1,1,0,1};
    queue<COOR> que;
    // check for white
    for(int i=1; i<=n; ++i)
	if(board[i][1]=='w'){
		que.push(COOR(i,1));
		board[i][1] = 0;
	}
    while( !que.empty() ){
		COOR now = que.front();	que.pop();
		for(int i=0; i<6; ++i){
			COOR tmp = now + COOR(dx[i],dy[i]);
			if( board[tmp.r][tmp.c]=='w' ){
				if( tmp.c == n )    return 1;
                board[tmp.r][tmp.c] = 0;
                que.push(tmp);
			}
		}
    }
    // otherwise black must win
    return 0;
}

int main(void){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int c = 0, n;
	while( scanf("%d", &n) && n!=0 ){
		input(n);
		int win = bfs_check(n);
		printf("%d %c\n", ++c, (win==1)?('W'):('B'));
	}

	return 0;
}
