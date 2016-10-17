#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cons[12][2], topp_num;

int ConstaintInput(void){
	int cnt=0;
	char input[40];
	memset(cons, 0, sizeof(cons));  topp_num = 0;
	while( gets(input)!=NULL ){
		int len = strlen(input), i, j;
		if( len==1 )    break;
		for(i=1; i<len; i+=2){
			int num = input[i]-'A';
			if( input[i-1]=='+' )   cons[cnt][0] |= (1<<num);
			else                    cons[cnt][1] |= (1<<num);
		    if( topp_num < num )	topp_num = num;
		}
		cnt++;
	}
	return cnt;
}

char backtrace(int index, int end, int n, int top_n, int bit, int topp){
	if( index==end ){
		int i, j, k;
		for(i=0; i<n; ++i){
			if( topp&cons[i][0] )				continue;
			if( (topp&cons[i][1])==cons[i][1] )   return 0;
		}
		
		printf("Toppings: ");
		for(i=0,j=1; i<=top_n; ++i,j<<=1)
		if( topp&j )	putchar('A'+i);
		putchar('\n');
		return 1;
	}
	/* prune condition
	...
	*/
	if( backtrace(index+1, end, n, top_n, bit<<=1, topp|bit) )	return 1;
	if( backtrace(index+1, end, n, top_n, bit<<=1, topp) )   	return 1;
	return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n;
	while( (n=ConstaintInput()) && n ){
		if( !backtrace(0,16,n,topp_num,1,0) )
		puts("No pizza can satisfy these requests.");
	}

	return 0;
}
