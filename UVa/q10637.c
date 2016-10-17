#include <stdio.h>
#include <string.h>

#define MAXS 101
#define MAXT 31
int divsr[MAXS]={0}, copr[MAXT];

void Prime(int n){
	int i, j, k, pr[MAXS], pr_num=0;   /* pr_num=25, so we can use bitmask for divsr */
	char notpr[MAXS]={0};
	for(i=2,k=1; i<MAXS; i++)if( !notpr[i] ){   /* find primes */
		pr[pr_num++] = i;   divsr[i] |= k;
		for(j=i<<1; j<MAXS; j+=i){
			notpr[j]=1;	divsr[j] |= k;
		}
		k <<= 1;
	}
}

void backtrace(int s, int t, int start, int end, int mask){
	int i, j;
	
	if( !t ){
		if( s ) return;
		printf("%d", copr[end]);
		for(i=end-1; i>0; i--)  printf(" %d", copr[i]);
		putchar('\n');
		return;
	}
	
	for(i=start,j=s/t; i<=j; i++){
		if( mask&divsr[i] ) continue;
		copr[t] = i;
		backtrace(s-i, t-1, i, end, mask|divsr[i]);
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, c=0, s, t;
	Prime(MAXS);
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d %d", &s, &t);
		printf("Case %d:\n", ++c);
		backtrace(s, t, 1, t, 0);
	}
	return 0;
}
