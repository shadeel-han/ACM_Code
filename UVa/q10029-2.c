/*
	Optimization not yet finished
	Use trie and enumerate all possible transformation
*/


#include <stdio.h>
#include <string.h>
#define MAXN 25001
char w[MAXN][20];
int len[MAXN], dp[MAXN];

char step(int a, int b){
	int i, j;
	if( len[a]==len[b] ){           /* test changing */
	    for(i=0,j=0; i<len[a]; i++)
	    if( w[a][i]!=w[b][i] )  j++;
	    if( j==1 )  return 1;
	}else if( len[b]-len[a]==1 ){   /* test adding */
	    for(i=0,j=0; i<len[b]; i++)if( w[a][i-j]!=w[b][i] ){
			if( j ) break;
			else	j++;
	    }
	    if( i==len[b] )	return 1;
	}else if( len[a]-len[b]==1 ){   /* test deleting */
	    for(i=0,j=0; i<len[a]; i++)if( w[a][i]!=w[b][i-j] ){
			if( j ) break;
			else	j++;
	    }
	    if( i==len[a] )	return 1;
	}
	return 0;
}

int RecursiveDP(int f, int e){
	if( dp[f]>(-1) ) return dp[f];
	int i, j, gain=0;
	for(i=f+1; i<=e; i++)if( step(f,i) ){
        j = RecursiveDP(i,e);
        if( gain < j )  gain = j;
	}
	return dp[f] = 1+gain;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, n=0, ans=0;
	while( scanf("%s", w[n])!=EOF )
		len[n] = strlen(w[n]), n++;
	memset(dp, -1, sizeof(dp));
	for(i=0; i<n; i++){
		j = RecursiveDP(i,n-1);
		if( ans < j )   ans = j;
	}
	printf("%d\n", ans);
	return 0;
}
