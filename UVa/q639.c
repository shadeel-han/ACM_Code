#include <stdio.h>

char board[20], used[20]={0}, ans;

void BoardInput(int n){
	int i, j;	char b[10];
    for(i=0; i<n; ++i){
		scanf("%s", b);
		for(j=0; j<n; ++j)  board[i*n+j] = b[j];
	}
}

void backtrace(int index, int end, int n, int num){
	if( index==end ){
		if( ans < num ) ans = num;
		return;
	}
	
	/* not put a rook */
	backtrace(index+1, end, n, num);
	/* put a rook */
	if( board[index]=='X' || used[index] ) return;
	int i, j;
	for(i=index+1,j=(index/n+1)*n; i<j; i++)
	if( board[i]=='X' ) break;
	else                used[i]++;
	for(i=index+n; i<end; i+=n)
	if( board[i]=='X' ) break;
	else                used[i]++;
	backtrace(index+1, end, n, num+1);
	for(i=index+1,j=(index/n+1)*n; i<j; i++)
	if( board[i]=='X' ) break;
	else                used[i]--;
	for(i=index+n; i<end; i+=n)
	if( board[i]=='X' ) break;
	else                used[i]--;
	
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, i;
	
	while( scanf("%d", &n) && n ){
  		BoardInput(n);
  		ans = 0;
  		backtrace(0,n*n,n,0);
  		printf("%d\n", ans);
	}

	return 0;
}
