#include <stdio.h>

int gcd(int a, int b){
	while( a && b ){
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int x, step, mod;
	
	while( scanf("%d %d", &step, &mod)!=EOF ){
		x = gcd(step, mod);
		printf("%10d%10d    ", step, mod);
		if( x==1 )	puts("Good Choice\n");
		else		puts("Bad Choice\n");
	}
	
	return 0;
}

