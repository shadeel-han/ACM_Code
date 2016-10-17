#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct POINT{
	int x, y, index;
	POINT(){};
	POINT(int a, int b, int c):x(a), y(b), index(c){};
	POINT operator+(const POINT& a){
		return POINT(x+a.x, y+a.y, index);
	}
};

POINT dep[10];
char b[13][13], walk[13][13];
int dep_num, ans, dmin[11],  dis2wall[13][13], dis2mine[13][13];

void Input(int n, int m){
	for(int i=0; i<n; i++)	scanf("%s", b[i]);
	dep_num = 0;    ans = 20;

	queue<POINT> que, dis_que;
	int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1}, dd[13][13];
	memset(dmin, 127, sizeof(dmin));
	memset(dis2wall, 127, sizeof(dis2wall));
	memset(dis2mine, 127, sizeof(dis2mine));
	for(int i=0; i<n; i++)for(int j=0; j<m; j++)
	if( b[i][j]=='*' ){
        b[i][j] = -dep_num; // renumber the mines
		dep[dep_num] = POINT(i, j, dep_num);
		que.push(dep[dep_num]);	dis_que.push(dep[dep_num]);
		dep_num++;	dis2mine[i][j] = 0;
	}else if( b[i][j]=='#' ){
        dis_que.push(POINT(i,j,-1));	dis2wall[i][j] = 0;
	}
	//	for every grid, calculate the dis2wall; for every ".", calculate the dis2mine
	while( !dis_que.empty() ){
		POINT now=dis_que.front();  dis_que.pop();
		for(int i=0; i<4; i++){
			POINT tmp = now + POINT(dx[i], dy[i], 0);
			if( now.index<0 && tmp.x>=0 && tmp.x<n && tmp.y>=0 && tmp.y<m
				&& b[tmp.x][tmp.y]!='#' && dis2wall[tmp.x][tmp.y]>dis2wall[now.x][now.y]+1 ){
                dis2wall[tmp.x][tmp.y] = dis2wall[now.x][now.y] + 1;
                dis_que.push(tmp);
			}else if( now.index>=0 && b[tmp.x][tmp.y]=='.'
				&& dis2mine[tmp.x][tmp.y]>dis2mine[now.x][now.y]+1 ){
                dis2mine[tmp.x][tmp.y] = dis2mine[now.x][now.y] + 1;
                dis_que.push(tmp);
			}
	}	}
	// for every "*", calculate the minimum distance to wall or other "*"
	while( !que.empty() ){
        queue<POINT> qq;
        POINT now=que.front();  que.pop();
        qq.push(now);	memset(dd, 127, sizeof(dd));
        dd[now.x][now.y] = 0;
        while( !qq.empty() ){
			now = qq.front();	qq.pop();
			for(int i=0; i<4; i++){
				POINT tmp = now + POINT(dx[i], dy[i], 0);
				int tmpd = dd[now.x][now.y] + 1;
				if( b[tmp.x][tmp.y]!='.' ){
                	if( dmin[now.index] > tmpd )
						dmin[now.index] = tmpd;
				} else if( dd[tmp.x][tmp.y]>tmpd && dmin[now.index]>tmpd ){
                    dd[tmp.x][tmp.y] = tmpd;    qq.push(tmp);
	}	}	}	}
	for(int i=0; i<dep_num; i++)    dis2mine[dep[i].x][dep[i].y] = dmin[i];
}

char backtrace(int x, int y, int step, int min_cost){
	int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
	
	int testd = (dis2wall[x][y]<dis2mine[x][y])?(dis2wall[x][y]):(dis2mine[x][y]);
	if( (step+min_cost+testd) >= ans ) return false;

	if( b[x][y]=='#' ){
		if( !min_cost ){
            ans = step;
			return ans==dmin[dep_num];
		}
		for(int i=0; i<dep_num; i++){   // find next undugged mine
            if( walk[dep[i].x][dep[i].y] )  		continue;
            walk[dep[i].x][dep[i].y] = 1;
			if( backtrace(dep[i].x, dep[i].y, step, min_cost-dmin[dep[i].index]) )  return true;
			walk[dep[i].x][dep[i].y] = 0;
		}
		return false;
	}

	for(int i=0; i<4; i++){
		int tmpx = x + dx[i], tmpy = y + dy[i];
		if( !walk[tmpx][tmpy] || b[tmpx][tmpy]=='#' ){  // '#' wall may be used many times
			walk[tmpx][tmpy] = 1;
			bool getmin;
			if( b[tmpx][tmpy]<=0 )	getmin=backtrace(tmpx, tmpy, step+1, min_cost-dmin[-b[tmpx][tmpy]]);
			else					getmin=backtrace(tmpx, tmpy, step+1, min_cost);
			if( getmin )    return true;
			walk[tmpx][tmpy] = 0;
		}
	}
	return false;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, n, m;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d %d", &n, &m);
		Input(n, m);
		memset(walk, 0, sizeof(walk));
		dmin[dep_num] = 0;
		for(int i=0; i<dep_num; i++)    dmin[dep_num] += dmin[i];
		backtrace(0, 0, 0, dmin[dep_num]);
		printf("%d\n", ans);
	}

	return 0;
}
