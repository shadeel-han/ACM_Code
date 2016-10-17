#include <stdio.h>

#define MAXN 100001

int seq[MAXN], input[MAXN], path[MAXN];

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
	int n, num = 0, tol = 1, pos, start;
	input[0] = -2147483647; seq[0] = 0;
	while( scanf("%d", &n)!=EOF ){
        /*pos = BinarySearch(0, num, n);    if num=1
        if( pos==num )  seq[num++] = tol;
        else            seq[pos] = tol;*/
        if( n > input[seq[num]] ){
			pos = num;	seq[++num] = tol;   start = tol;
        }else{
            pos = BinarySearch(0, num, n);
            if( pos==num )  start = tol;
            seq[pos--] = tol;
        }
        path[tol] = seq[pos];
        input[tol++] = n;
	}
	printf("%d\n-\n", num);
	PrintAns(start);
	
	return 0;
}
