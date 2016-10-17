#include <stdio.h>

int seq[1000001];

int BinarySearch(int start, int end, int val){
	int low=start, up=end, mid;
	while( low!=up ){
        mid = (low+up)>>1;
		if( val > seq[mid] )	up = mid;
		else                    low = mid + 1;
	}
	return low;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, c=0, num, pos;
	while( scanf("%d", &seq[0]) && seq[0]!=-1){
		num = 1;
		while( scanf("%d", &n) && n!=-1 ){
            pos = BinarySearch(0, num, n);
            if( pos==num )  seq[num++] = n;
            else            seq[pos] = n;
		}
		if( c++ )   putchar('\n');
		printf("Test #%d:\n  maximum possible interceptions: %d\n", c, num);
	}
	return 0;
}
