#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAXN 10001
int in[MAXN], sta[MAXN], dp[2][MAXN];

int BinarySearch(int start, int end, int val){
	int low=start, up=end, mid;
	while( low!=up ){
        mid = (low+up)>>1;
		if( in[sta[mid]] >= val )	up = mid;
		else                    	low = mid + 1;
	}
	return low;
}

int Solve(int n){
	int i, num=0, pos, ans=0;
	for(i=1; i<=n; i++){
        if( in[i] > in[sta[num]] ){
			pos = num;	sta[++num] = i;
		}else{
            pos = BinarySearch(0, num, in[i]);
            sta[pos--] = i;
        }
        dp[0][i] = dp[0][sta[pos]] + 1;
	}
	for(i=n,num=0; i>ans; i--){
        if( in[i] > in[sta[num]] ){
			pos = num;	sta[++num] = i;
		}else{
            pos = BinarySearch(0, num, in[i]);
            sta[pos--] = i;
        }
        dp[1][i] = dp[1][sta[pos]] + 1;
        pos = MIN(dp[0][i],dp[1][i]);
		if( ans < pos )	ans = pos;
	}
	/*for(i=1,num=0; i<=n; i++){
		pos = MIN(dp[0][i],dp[1][i]);
		if( num < pos ) num = pos;
	}*/
	return ans;
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, n, len;
	in[0] = -2147483647;    sta[0] = 0;
	dp[0][0] = dp[1][0] = 0;
	while( scanf("%d", &n)!=EOF ){
		for(i=1; i<=n; i++)  scanf("%d", &in[i]);
		len = Solve(n);
		printf("%d\n", (len<<1)-1);
	}
	
	return 0;
}
