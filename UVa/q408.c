#include <stdio.h>
#include <string.h>

int dp[100001];

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int x, step, mod, cnt;
	
	while( scanf("%d %d", &step, &mod)!=EOF ){
		memset(dp, 0, sizeof(dp));
		x = 0;	cnt = 1;
		while( !dp[x] ){
			dp[x] = cnt++;
			x = (x+step)%mod;
		}
		printf("%10d%10d    ", step, mod);
		if( cnt-dp[x]==mod )	puts("Good Choice\n");
		else					puts("Bad Choice\n");
	}
	
	return 0;
}

