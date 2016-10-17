#include <stdio.h>

int main(){
    int count, a, b, dif;
    scanf("%d", &count);
    while( (count--)>0 ){
           scanf("%d %d", &a, &b);
           dif = a - b;
           if( (dif>=0) && (dif%2==0) )
              printf("%d %d\n", (a+b)>>1, dif>>1);
           else
              printf("impossible\n");
    }
    return 0;
}
