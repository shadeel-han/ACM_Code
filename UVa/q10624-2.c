#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int digit[4];

char backtrace(int d, int m, int n){
	if( d>=n ){
		if( !(d&1) && (digit[0]&1) )		return 0;
		else if( !(d%5) && (digit[0]%5) )	return 0;
		
		int i=(d-1)/8, j;   unsigned int dg=digit[i], rem;
		for( ; i>0; i--){
			rem = dg % d;
			dg = rem*100000000 + digit[i-1];
		}
		if( dg % d )	return 0;
	}
	if( d==m ){
		if( d>24 )		printf("%u%08u%08u%08u\n", digit[3], digit[2], digit[1], digit[0]);
		else if( d>16 )	printf("%u%08u%08u\n", digit[2], digit[1], digit[0]);
		else if( d>8 )	printf("%u%08u\n", digit[1], digit[0]);
		else			printf("%u\n", digit[0]);
		return 1;
	}

	unsigned int tmp[4];	memcpy(tmp, digit, sizeof(digit));
	if( d>=24 ){
        digit[3] = digit[3]*10 + digit[2]/10000000;
        digit[2] = (digit[2]%10000000)*10 + tmp[1]/10000000;
        digit[1] = (digit[1]%10000000)*10 + tmp[0]/10000000;
        digit[0] = (digit[0]%10000000)*10;
	} else if( d>=16 ){
		digit[2] = digit[2]*10 + tmp[1]/10000000;
        digit[1] = (digit[1]%10000000)*10 + tmp[0]/10000000;
        digit[0] = (digit[0]%10000000)*10;
	} else if( d>=8 ){
		digit[1] = digit[1]*10 + tmp[0]/10000000;
        digit[0] = (digit[0]%10000000)*10;
	} else  digit[0] *= 10;

	int i=(d)?(0):(1);
	for( ; i<10; i++){
		digit[0] += i;
		if( backtrace(d+1, m, n) )  return 1;
		digit[0] -= i;
	}
	memcpy(digit, tmp, sizeof(digit));
	return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, cc=0, n, m;

	scanf("%d", &c);
	while( c-- ){
		scanf("%d %d", &n, &m);
		memset(digit, 0, sizeof(digit));
		printf("Case %d: ", ++cc);
		if( !backtrace(0,m,n) )  puts("-1");
    }

	return 0;
}
