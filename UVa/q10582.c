#include <stdio.h>
#include <string.h>

char board[65][65], used[65][65];
int ans;

void Input(int m, int n){
	int i, j, k;  char in[330];
	memset(used, 0, sizeof(used));
	gets(in);
	for(i=1; i<=m; i++){
        gets(in);	gets(in);
        for(j=1,k=0; j<=n; j++,k+=4){
			if( in[k+1]=='*' )
                board[i][j] = (in[k+3]=='*')?(1):(2);
			else{
				board[i][j] = 0;    used[i][j] = 1;
			}
        }
        gets(in);	gets(in);
	}
}

void backtrace(int x, int y, int m, int n, int dir){    /* for direction, 1:¡õ, 2:¡ô, 3:¡÷, 4:¡ö */
	if( (!x) || (!y) || (x>m) || (y>n) || used[x][y] )  return;

	if( x==m && y==n && board[x][y] ){
		ans++;  return;
	}

	used[x][y] = 1;
	if( dir==1 ){
		if( board[x][y]==1 )    backtrace(x+1,y,m,n,1);
		else{
			backtrace(x,y+1,m,n,3);
			backtrace(x,y-1,m,n,4);
		}
	}else if( dir==2 ){
        if( board[x][y]==1 )    backtrace(x-1,y,m,n,2);
		else{
			backtrace(x,y+1,m,n,3);
			backtrace(x,y-1,m,n,4);
		}
	}else if( dir==3 ){
        if( board[x][y]==1 )    backtrace(x,y+1,m,n,3);
		else{
			backtrace(x-1,y,m,n,2);
			backtrace(x+1,y,m,n,1);
		}
	}else{
        if( board[x][y]==1 )    backtrace(x,y-1,m,n,4);
		else{
			backtrace(x-1,y,m,n,2);
			backtrace(x+1,y,m,n,1);
		}
	}
	used[x][y] = 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, m, n, i, j;
	scanf("%d", &c);
	while(c--){
		scanf("%d %d\n", &m, &n);
		Input(m, n);
		ans = 0;
		backtrace(1, 1, m, n, 1);
		backtrace(1, 1, m, n, 3);
		printf("Number of solutions: %d\n", ans);
	}
	return 0;
}
