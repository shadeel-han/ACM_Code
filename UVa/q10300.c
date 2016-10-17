#include <stdio.h>

int main(){
    int num, num2, a, b, c, i, j;
    int total;
    while(scanf("%d", &num)!=EOF){
       for( int i=0; i<num; i++ ){
            scanf("%d", &num2);
            total = 0;
            for( j=0; j<num2; j++ ){
                 scanf("%d %d %d", &a, &b, &c);
                 total += (a*c);
            }
            printf("%d\n", total);
       }
    }
    return 0;
}
