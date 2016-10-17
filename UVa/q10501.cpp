#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 25

struct NODE{
	int r, c, dir;  /*0:up, 1:right, 2:down, 3:left*/
	NODE(){};
	NODE(int r, int c, int d):r(r), c(c), dir(d){};
};

char board[SIZE][SIZE];
vector<NODE> pr_from, pr_to;

char backtrace(int n, int tol, int r, int c){
	if( n==tol )	return 1;
	
	int node[SIZE][SIZE][4], dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
	queue<NODE> que;    bool inque[SIZE][SIZE][4]={0};
	for(int i=1; i<r; i++)for(int j=1; j<c; j++)
	if( board[i][j] > -1 ){
		/* count the time of turns */
		memset(node, 127, sizeof(node));
		for(int k=0; k<4; k++){
			que.push(NODE(i,j,k));  node[i][j][k] = 0;
			inque[i][j][k] = true;
		}
		while( !que.empty() ){
			NODE now = que.front(); que.pop();  inque[now.r][now.c][now.dir] = false;
			for(int k=0; k<4; k++){
				NODE tmp = NODE(now.r+dx[k],now.c+dy[k],k);
				if( tmp.r>=0 && tmp.r<=r && tmp.c>=0 && tmp.c<=c && (board[tmp.r][tmp.c]==-1 || board[tmp.r][tmp.c]==board[i][j]) ){
					int t = (now.dir==tmp.dir)?(node[now.r][now.c][now.dir]):(node[now.r][now.c][now.dir]+1);
					if( node[tmp.r][tmp.c][tmp.dir] > t && t<=2 ){
						node[tmp.r][tmp.c][tmp.dir] = t;
						if( !inque[tmp.r][tmp.c][tmp.dir] && board[tmp.r][tmp.c]==-1 ){
							que.push(tmp);  inque[tmp.r][tmp.c][tmp.dir] = true;
		}	}	}	}	}
		/* make pair */
		for(int a=i; a<r; a++)for(int b=(a==i)?(j+1):(1); b<c; b++)
		if( board[a][b]==board[i][j] ){
			int k;	for(k=0; k<4; k++)  if(node[a][b][k]<=2)	break;
			if( k==4 )  continue;
			char from=board[i][j], to=board[a][b];
			board[i][j] = board[a][b] = -1;
			pr_from.push_back(NODE(i,j,0));   pr_to.push_back(NODE(a,b,0));
			if( backtrace(n+2, tol, r, c) ) return 1;
			pr_from.pop_back(); pr_to.pop_back();
			board[i][j] = from;	board[a][b] = to;
		}
	}
	return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, r;
	char tmp[SIZE];
	
	while( scanf("%d %d", &c, &r)!=EOF ){
		getchar();  /* flush \n */
		memset(board, -1, sizeof(board));
		for(int i=1; i<=r; i++){
			for(int j=1; j<=c; j++){
				board[i][j] = getchar();
			}
			getchar();
		}
		pr_from.clear();    pr_to.clear();
		if( ((r*c)&1) || !backtrace(0, r*c, r+1, c+1) )	puts("No solution");
		else{
			for(int i=0,j=pr_from.size(); i<j; i++)
			printf("(%d,%d),(%d,%d)\n", pr_from[i].c, pr_from[i].r, pr_to[i].c, pr_to[i].r);
		}
	}
	return 0;
}
