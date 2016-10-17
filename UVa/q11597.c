#include <stdio.h>

int main(void){
	int n, c=0;
	while( scanf("%d", &n) && n!=0 ){
		printf("Case %d: %d\n", ++c, n>>1);
	}
	return 0;
}
