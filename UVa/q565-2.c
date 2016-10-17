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

char backtrace(int n, int top_n){
	int i, j, k, end=1<<top_n;
	for(i=end-1; i>=0; --i){    /* backtrace on the binary form of i */
		for(j=0; j<n; ++j){
			if( i&cons[j][0] )					continue;
			if( (i&cons[j][1])==cons[j][1] )	break;
		}
		if(j==n)    break;
	}
	if( i==-1 )    return 0;
	printf("Toppings: ");
	for(j=1,k=0; k<top_n; j<<=1,++k)
	if( i&j )	putchar('A'+k);
	putchar('\n');
	return 1;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n;
	while( (n=ConstaintInput()) && n ){
		if( !backtrace(n,topp_num+1) )
		puts("No pizza can satisfy these requests.");
	}

	return 0;
}
