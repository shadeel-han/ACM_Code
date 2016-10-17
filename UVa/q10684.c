#include <stdio.h>

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, in, tmp, ans;
	while( scanf("%d", &n) && n ){
		tmp = 0;    ans = 0;
		while( n-- ){
			scanf("%d", &in);
			tmp += in;
			if( tmp < 0 )			tmp = 0;
			else if( tmp > ans )    ans = tmp;
		}
		if( !ans )  puts("Losing streak.");
		else        printf("The maximum winning streak is %d.\n", ans);
	}
	return 0;
}
