#include <stdio.h>

#define MAXN 1001
int cyc[MAXN]={0}, chain[MAXN][3000];

int BigMod(int a, unsigned long long int b, int n){
	if( !b )    return 1;
    if( b&1 )	return (a*BigMod(a,b-1,n))%n;
    else{
		int t = BigMod(a,b>>1,n);
		return (t*t)%n;
    }
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, n;
	unsigned long long int a, b;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%llu", &a);  scanf("%llu", &b);  scanf("%d", &n);
		if( (!a)||(n==1) ){
			puts("0");  continue;
		}
		
		if( !cyc[n] ){
			int i=1;    chain[n][0] = 0;    chain[n][1] = 1;
			while(++i){
				chain[n][i] = (chain[n][i-1]+chain[n][i-2])%n;
				if( (!chain[n][i-1]) && (chain[n][i]==1) )	break;
			}
			cyc[n] = --i;
		}
		printf("%d\n", chain[n][BigMod(a%cyc[n],b,cyc[n])]);
	}
	return 0;
}
