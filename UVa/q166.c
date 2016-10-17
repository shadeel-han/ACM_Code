#include <stdio.h>
#include <string.h>
#define MAXN 501
int dp[MAXN]={0}, own[MAXN];

void CoinChange(void){
	int i, j, d[6]={5,10,20,50,100,200};
	for(i=0,j=0; i<MAXN; i+=5,j++)	dp[i] = j;
	for(i=1; i<6; i++)for(j=MAXN-1; j>=0 ; j-=5){
        int newd = j + d[i], newn = dp[j] + 1;
		for( ; newd<MAXN; newd+=d[i], newn++)
		if( dp[newd] > newn )	dp[newd] = newn;
	}
}

void OwnChange(int coin[]){
	int i, j, k, d[6]={5,10,20,50,100,200}, last=0;
	memset(own, 127, sizeof(own));  own[0] = 0;
	for(i=0; i<6; i++){
		for(j=last; j>=0 ; j-=5){
            int newd = j + d[i], newn = own[j] + 1;
			for(k=1; k<=coin[i] && newd<MAXN; newd+=d[i], newn++, k++)
			if( own[newd] > newn )  own[newd] = newn;
		}
		last += coin[i]*d[i];
		if( last>=MAXN )	last = MAXN-1;
	}
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int coin[6], i, j, a, b, ans;
	CoinChange();
	while(1){
		for(i=0,j=0; i<6; i++){
			scanf("%d", &coin[i]);	j += coin[i];
		}
		if( !j )    break;
		scanf("%d.%d", &a, &b);
		OwnChange(coin);
		for(i=500,j=a*100+b,ans=MAXN; i>=j; i-=5)
		if( ans > own[i]+dp[i-j] )	ans = own[i]+dp[i-j];
		printf("%3d\n", ans);
	}
	return 0;
}
