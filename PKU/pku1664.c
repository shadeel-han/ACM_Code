#include <stdio.h>

int f(int m, int n) 
{ 
	if(m<0) return 0; 
	if(m==0||n==1) return 1; 
	return f(m-n,n)+f(m,n-1); 
}

int main(){
    int tol, apple, bucket;
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d %d", &apple, &bucket);
           printf("%d\n", f(apple,bucket));
    }
    return 0;
}
