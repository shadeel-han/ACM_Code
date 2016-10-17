#include <stdio.h>
#include <string.h>

int dp[10000];

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int Z, I, M, L, c=0, cnt;
	
	while( scanf("%d %d %d %d", &Z, &I, &M, &L) ){
		if( !Z && !I && !M && !L )	break;
		memset(dp, 0, sizeof(dp));	cnt = 1;
		while( !dp[L] ){
			dp[L] = cnt++;
			L = (Z*L+I)%M;
		}
		printf("Case %d: %d\n", ++c, cnt-dp[L]);
	}
	
	return 0;
}

