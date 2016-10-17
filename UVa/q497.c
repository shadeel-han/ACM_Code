#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000001

int seq[MAXN], input[MAXN], path[MAXN], dp[MAXN];

int BinarySearch(int start, int end, int val){
	int low=start, up=end, mid;
	while( low!=up ){
        mid = (low+up)>>1;
		if( input[seq[mid]] >= val )	up = mid;
		else                    		low = mid + 1;
	}
	return low;
}

void PrintAns(int n){
	if( n ){
        PrintAns(path[n]);
        printf("%d\n", input[n]);
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, n, num, tol, pos;
	char in[50];
	input[0] = -2147483647; seq[0] = 0; dp[0] = 1;
	scanf("%d\n", &cas);    gets(in);
	while( cas-- ){
		if( c++ )   putchar('\n');
		num = 1;    tol = 1;
		while( gets(in) && strlen(in) ){
			n = atoi(in);
			pos = BinarySearch(0, num, n);
        	if( pos==num )  seq[num++] = tol;
        	else            seq[pos] = tol;
        	dp[tol] = dp[seq[pos-1]] + 1;
        	path[tol] = seq[pos-1];
        	input[tol++] = n;
		}
        printf("Max hits: %d\n", num-1);
		for(n=tol-1,pos=0; n>pos; n--)
		if( pos < dp[n] )   pos = dp[n], num = n;
		PrintAns(num);
	}

	return 0;
}
