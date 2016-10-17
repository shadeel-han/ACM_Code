#include <stdio.h>

int GCD(int a, int b){
	int c;
	while( a%b ){
		c = a%b;
		a = b;
		b = c;
	}
	return b;
}

int main(void){

	int in, sum, i, j;
	
	while( scanf("%d", &in) && in!=0 ){
		sum = 0;
		for(i=1; i<in; i++) for(j=i+1; j<=in; j++){
			sum += GCD(i,j);
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
