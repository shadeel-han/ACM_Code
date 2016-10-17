#include <stdio.h>
#include <math.h>

int main(){
    double pi = 2*acos(0), ans, a, b;
    int tol, dis, len;
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d %d", &dis, &len);
           a = (double)len/2;
           b = (double)dis/2;
           b = sqrt(a*a-b*b);
           ans = pi*a*b;
           printf("%.3lf\n", ans);
    }
    return 0;
}
