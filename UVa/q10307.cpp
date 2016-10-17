#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define BSIZE 55
#define MAXN 102
struct POINT{
	int x, y;
	POINT(){};
	POINT(int a, int b):x(a), y(b){};
	bool operator<(const POINT &a) const{	// minimum heap for PQ
		return (y>a.y);
	}
	POINT operator+(const POINT &a){
		return POINT(x+a.x, y+a.y);
	}
};

POINT point[MAXN];
char maze[BSIZE][BSIZE];

void ComputeDis(int ind, int n, int dis[MAXN]){
	int step[BSIZE][BSIZE], dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
	memset(step, -1, sizeof(step));	step[point[ind].x][point[ind].y] = 0;
	queue<POINT> que;	que.push(point[ind]);
	while( !que.empty() ){
		POINT now = que.front();    que.pop();
		for(int i=0; i<4; i++){
			POINT tmp = now + POINT(dx[i], dy[i]);
			if( maze[tmp.x][tmp.y]!='#' && step[tmp.x][tmp.y]==-1 ){
                step[tmp.x][tmp.y] = step[now.x][now.y] + 1;
                que.push(tmp);
	}	}	}
	for(int i=1; i<=n; i++) dis[i] = step[point[i].x][point[i].y];;
}

int Solve(int n){
	priority_queue<POINT> pq;	bool touch[MAXN]={0};
	int num = n, ans = 0, dis[MAXN];
	pq.push(POINT(1,0));
	while( !pq.empty() && num ){
		POINT now = pq.top();   pq.pop();
		if( touch[now.x] )  continue;
		touch[now.x] = true;	num--;	ans += now.y;
		ComputeDis(now.x, n, dis);
		for(int i=1; i<=n; i++)
		if( !touch[i] )	pq.push(POINT(i, dis[i]));
	}
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas;
	scanf("%d", &cas);
	while( cas-- ){
		int m, n, cnt=1;
		scanf("%d %d\n", &m, &n);
		for(int i=0; i<n; i++){
			gets(maze[i]);
			for(int j=0; j<m; j++)
			if( maze[i][j]=='A' || maze[i][j]=='S' ){
				point[cnt++] = POINT(i,j);
			}
		}
		if( cnt<=2 )    puts("0");
		else			printf("%d\n", Solve(cnt-1));
	}
	return 0;
}
