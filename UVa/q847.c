#include <stdio.h>
#include <math.h>

int main(){
    double in;
    while( scanf("%lf", &in)!=EOF ){
           while( in>18 )
                  in = ceil(in/18);
           if(in>9)
               puts("Ollie wins.");
           else
               puts("Stan wins.");
    }
    return 0;
}
