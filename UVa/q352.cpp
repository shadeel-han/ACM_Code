#include <cstdio>
#include <queue>

using namespace std;

struct COOR{
	int x, y;
	COOR(int x, int y):x(x),y(y) {};
	COOR operator+(const COOR& a){
		return COOR(x+a.x, y+a.y);
	}
};

char img[27][27]={0};

void input(int n){
	for(int i=1; i<=n; ++i)
	    scanf("%s", img[i]+1);
}

int bfs(int n){
    int dx[8]={-1,-1,-1,0,0,1,1,1}, dy[8]={-1,0,1,-1,1,-1,0,1}, ans=0;
    ;queue<COOR> que;
    // scan & bfs
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
	if( img[i][j]=='1' ){
		que.push(COOR(i,j));
		img[i][j] = 0;	++ans;
    	while( !que.empty() ){
			COOR now = que.front();	que.pop();
			for(int i=0; i<8; ++i){
				COOR tmp = now + COOR(dx[i],dy[i]);
				if( img[tmp.x][tmp.y]=='1' ){
                	img[tmp.x][tmp.y] = 0;
                	que.push(tmp);
				}
			}
    	}
	}
    
    return ans;
}

int main(void){

    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int c=0, n;
	while( scanf("%d", &n)!=EOF ){
		input(n);
		printf("Image number %d contains %d war eagles.\n", ++c, bfs(n));
	}

	return 0;
}
