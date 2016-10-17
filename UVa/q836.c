#include <stdio.h>
#include <string.h>

#define MAXN 30

char board[MAXN][MAXN]={0};

int Input(void){
	int i, len;
	scanf("%s", board[0]);
	len = strlen(board[0]);
	for(i=1; i<len; i++)   scanf("%s", board[i]);
	return len;
}

int OneDMax(int n, int s[MAXN], int start){
	int i, w=s[start], sum=0, maxx=0;
	for(i=start; i<n; ++i){
		sum = (s[i]==w)?(sum+1):(0);
		if(sum > maxx)	maxx = sum;
	}
	return maxx;
}

int Solve(int n){
	int i, j, k, w, s[MAXN], ans=0, tmp, one;
	for(i=0; i<n; i++){
        memset(s, 0, sizeof(s));
		for(j=i,w=1; j<n; j++,w++){
			one = -1;
			for(k=n-1; k>=0; k--)if( board[j][k]=='1' ){
				s[k]++;
				if( s[k]==w )   one = k;
			}
			if( one==-1 )   break;
			tmp = OneDMax(n, s, one);
			if( ans < tmp*w )	ans = tmp*w;
		}
	}
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, c=0, len;
	scanf("%d", &cas);
	while( cas-- ){
		if( c++ )   putchar('\n');
		len = Input();
		printf("%d\n", Solve(len));
	}
	return 0;
}
