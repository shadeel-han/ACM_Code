#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char digit[4][10];

char backtrace(int d, int m, int n){
	if( d>=n ){
        int pos=(d<8)?(d-1):(7);
		if( !(d&1) && ((digit[0][pos]-'0')&1) )			return 0;
		else if( !(d%5) && ((digit[0][pos]-'0')%5) )	return 0;
		
		int i=(d-1)/8, j;   unsigned int dg=(unsigned int)atoi(digit[i]), rem;
		for( ; i>0; i--){
			rem = dg % d;
			dg = rem*100000000 + (unsigned int)atoi(digit[i-1]);
		}
		if( dg % d )	return 0;
	}
	if( d==m ){
		if( d>24 )	printf("%s", digit[3]);
		if( d>16 )	printf("%s", digit[2]);
		if( d>8 )	printf("%s", digit[1]);
		puts(digit[0]);
		return 1;
	}
	
	char tmp[4][10]; memcpy(tmp, digit, sizeof(digit));
	if( d>=24 ){
        sprintf(digit[3], "%s%c", tmp[3], tmp[2][0]);
        sprintf(digit[2], "%s%c", tmp[2]+1, tmp[1][0]);
        sprintf(digit[1], "%s%c", tmp[1]+1, tmp[0][0]);
        sprintf(digit[0], "%s", tmp[0]+1);
	} else if( d>=16 ){
        sprintf(digit[2], "%s%c", tmp[2], tmp[1][0]);
        sprintf(digit[1], "%s%c", tmp[1]+1, tmp[0][0]);
		sprintf(digit[0], "%s", tmp[0]+1);
	} else if( d>=8 ){
		sprintf(digit[1], "%s%c", tmp[1], tmp[0][0]);
		sprintf(digit[0], "%s", tmp[0]+1);
	}
	
	int i=(d)?(0):(1), pos=(d<7)?(d):(7);
	for( ; i<10; i++){
		digit[0][pos] = '0'+i;
		if( backtrace(d+1, m, n) )  return 1;
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
