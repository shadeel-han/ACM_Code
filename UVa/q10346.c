#include <stdio.h>

int main(){
    int a, b, total;
    while( scanf("%d %d", &a, &b)!=EOF ){
                total = a;
                while(a>=b){
                   total += a/b;
                   a = a/b + a%b;
                }
                printf("%d\n", total);
    }
    return 0;
}
