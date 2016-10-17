#include <stdio.h>

int main(){
    int a, b;
    double d;
    while( scanf( "%d:%d", &a, &b ) && a  ){
           d = 30*a - 5.5*b;
           if( d < 0 )
              d *= (-1);
           if( d > 180 )
              d = 360 - d;
           printf("%.3f\n", d);
    }
    return 0;
}
