#include <stdio.h>

char prime[32]={0}, used[17]={0};
int li[16];

void backtrace(int index, int end){
	int i;
	if( index==end ){
		if( prime[li[0]+li[end-1]] ){
            putchar('1');
			for(i=1; i<end; ++i)  printf(" %d", li[i]);
			putchar('\n');
		}
		return;
	}
	for(i=2; i<=end; ++i){
		if( used[i] || !prime[li[index-1]+i] )   continue;
		used[i] = 1;    li[index] = i;
		backtrace(index+1, end);
		used[i] = 0;
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, n;
	prime[2] = 1;	prime[3] = 1;	prime[5] = 1;
	prime[7] = 1;   prime[11] = 1;  prime[13] = 1;
	prime[17] = 1;  prime[19] = 1;  prime[23] = 1;
	prime[29] = 1;  prime[31] = 1;  li[0] = 1;

	while( scanf("%d", &n)!=EOF ){
		if( c )	putchar('\n');
        printf("Case %d:\n", ++c);
        backtrace(1,n);
	}

	return 0;
}
