#include <stdio.h>
#include <string.h>

int in[5], used[5], num[5];

char backtrace2( int n, int sum ){
	if( n==5 ){
		if( sum==23 )	return 1;
        else			return 0;
    }
    
    if( backtrace2(n+1, sum+num[n]) )   return 1;
    if( backtrace2(n+1, sum-num[n]) )   return 1;
    if( backtrace2(n+1, sum*num[n]) )   return 1;
    return 0;
}


char backtrace( int n ){
	if( n==5 )	return backtrace2(1, num[0]);

	int i;
    for( i=0; i<5; i++ )if( !used[i] ){
		used[i] = 1;
    	num[n] = in[i];
        if( backtrace(n+1) )    return 1;
        used[i] = 0;
    }
    return 0;
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
    int i;

    while( scanf("%d %d %d %d %d", &in[0], &in[1], &in[2], &in[3], &in[4]) && in[0] ){
		memset(used, 0, sizeof(used));
		if( backtrace(0) )  puts("Possible");
		else				puts("Impossible");
    }

    return 0;
}
