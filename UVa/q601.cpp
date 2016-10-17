#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define INF 10000

char board[82][82];
int white[82][82], black[82][82];	// the least additional moves to reach

struct COOR{
	int a, b;   char c;
	COOR() {};
	COOR(int a, int b, char c):a(a),b(b),c(c) {};
	COOR operator+(const COOR& x){
		return COOR(a+x.a, b+x.b, x.c);
	}
};

void traverse(int n){
	queue<COOR> que;
	int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};

	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j){
		white[i][j] = INF;
		black[i][j] = INF;
	}
	for(int i=1; i<=n; ++i){
		// home edge of white
		if( board[i][1]!='B' ){
			que.push(COOR(i,1,'W'));
			white[i][1] = (board[i][1]=='W')?(0):(1);
		}
		// home edge of black
		if( board[1][i]!='W' ){
			que.push(COOR(1,i,'B'));
			black[1][i] = (board[1][i]=='B')?(0):(1);
		}
	}
	
	while( !que.empty() ){
		COOR now = que.front(); que.pop();
		for(int i=0; i<4; ++i){
			COOR tmp = now + COOR(dx[i],dy[i],now.c);
			if( now.c=='W' && (board[tmp.a][tmp.b]=='W' || board[tmp.a][tmp.b]=='U') ){
				int t = (board[tmp.a][tmp.b]=='W')?(white[now.a][now.b]):(white[now.a][now.b]+1);
				if( white[tmp.a][tmp.b] > t ){
                    white[tmp.a][tmp.b] = t;
                    que.push(tmp);
				}
			}else if( now.c == 'B' && (board[tmp.a][tmp.b]=='B' || board[tmp.a][tmp.b]=='U') ){
                int t = (board[tmp.a][tmp.b]=='B')?(black[now.a][now.b]):(black[now.a][now.b]+1);
				if( black[tmp.a][tmp.b] > t ){
                    black[tmp.a][tmp.b] = t;
                    que.push(tmp);
				}
			}
		}
	}
}

// if White tends to block Black in next move
bool TestBlack(int n){
	queue<COOR> que;    bool walk[82][82], ans=true;
	int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
	if( black[i][j]==1 && board[i][j]=='U' ){
        black[i][j] = INF;  // if (i,j) is blocked by white
        memset(walk,0,sizeof(walk));
		for(int k=1; k<=n; ++k) if( board[1][k]!='W' && black[1][k]<=1 ){
            que.push(COOR(1,k,'B'));
            walk[1][k] = true;
		}
        while( !que.empty() ){
            COOR now = que.front(); que.pop();
			for(int k=0; k<4; ++k){
				COOR tmp = now + COOR(dx[k],dy[k],now.c);
				if( black[tmp.a][tmp.b]<=1 && !walk[tmp.a][tmp.b] && (board[tmp.a][tmp.b]=='B' || board[tmp.a][tmp.b]=='U') ){
					walk[tmp.a][tmp.b] = true;
					que.push(tmp);
				}
			}
        }
        int k;
        for(k=1; k<=n; ++k)
		if( board[n][k]!='W' && walk[n][k] )    break;
		if( k>n )   ans = false;
        
        black[i][j] = 1;
	}
	return ans;
}

void PrintAns(int n){
	for(int i=1; i<=n; ++i)
	if( board[i][n]=='W' && !white[i][n] ){
		puts("White has a winning path.");
		return ;
	}
	for(int i=1; i<=n; ++i)
	if( board[n][i]=='B' && !black[n][i] ){
		puts("Black has a winning path.");
		return ;
	}
	for(int i=1; i<=n; ++i)
	if( board[i][n]!='B' && white[i][n]==1 ){
        puts("White can win in one move.");
		return ;
	}
	for(int i=1; i<=n; ++i)
	if( board[n][i]!='W' && black[n][i]==1 /*&& TestBlack(n)*/ ){
		puts("Black can win in one move.");
		return ;
	}
	puts("There is no winning path.");
	return ;
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while(scanf("%d", &n) && n!=0){
		memset(board,0,sizeof(board));
		for(int i=1; i<=n; ++i) scanf("%s", board[i]+1);
		traverse(n);
		PrintAns(n);
	}
	return 0;
}
