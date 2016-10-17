#include <stdio.h>

int main(){
    int a, b, c, d;
    while( scanf("%d %d %d %d", &a, &b, &c, &d) && ( a || b || c || d ) ){
           if( a < c )
              printf("%d\n", (c-a)*60+d-b);
           else if( a > c )
              printf("%d\n", (24+c-a)*60+d-b);
           else{
                if( b < d )
                   printf("%d\n", d-b);
                else if( b > d )
                   printf("%d\n", 1440-b+d);
                else
                   printf("0\n");
           }
    }
    return 0;
}
