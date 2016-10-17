#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stick[20], used[20];

char backtrace(int edge, int index, int end, int sum, int len, int first){
	if( sum>len )	return 0;
	else if( sum==len ){
		if( edge<2 )    return backtrace(edge+1, first+1, end, 0, len, -1);
		else            return 1;
	}
	
	int i;
	for(i=index; i<end; i++)if( !used[i] ){
		used[i] = 1;
		if( first==-1 ){    /* because every stick must be used, we must take the first stick for every edge
								to avoid repeated compuatation on different edge order  */
			if( backtrace(edge, i+1, end, stick[i], len, i) )	return 1;
			used[i] = 0;	return 0;
		} else {
            if( backtrace(edge, i+1, end, sum+stick[i], len, first) )	return 1;
		}
		used[i] = 0;
	}
	return 0;
}

int compare( const void* a, const void* b ){
	return -( *(int*)a - *(int*)b );
	/* sorting from big to small, so -1 */
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, n, i, tol;
	
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);	tol = 0;
		for(i=0; i<n; ++i){
			scanf("%d", &stick[i]);
			tol += stick[i];
		}
		qsort(stick, n, sizeof(int), compare);
		memset(used, 0, sizeof(used));
		if( n<4 || (tol&3) || !backtrace(0, 0, n, 0, tol>>2, -1) )	puts("no");
		else                                                		puts("yes");
	}
	return 0;
}
