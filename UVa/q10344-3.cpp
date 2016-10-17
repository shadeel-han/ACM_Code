#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int in[5], order[5];

char backtrace( int n, int sum ){
	if( n==5 ){
		if( sum==23 )	return 1;
        else			return 0;
    }

    if( backtrace(n+1, sum+in[order[n]]) )	return 1;
    if( backtrace(n+1, sum-in[order[n]]) )  return 1;
    if( backtrace(n+1, sum*in[order[n]]) )  return 1;
    return 0;
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

    while( scanf("%d %d %d %d %d", &in[0], &in[1], &in[2], &in[3], &in[4]) && in[0] ){
		for(int i=0; i<5; ++i)	order[i] = i;
		bool ok = false;
		do{
			ok = backtrace(1,in[order[0]]);
		}while( next_permutation(order,order+5) && !ok );
		if( ok )	puts("Possible");
		else		puts("Impossible");
    }

    return 0;
}
