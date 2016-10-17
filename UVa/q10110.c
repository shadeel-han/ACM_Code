#include <stdio.h>
#include <math.h>

int main(){
    
    unsigned int in;
    int a;
    double b;
    
    while( scanf("%u", &in) ){
           if( !in )
               break;
           b = sqrt(in);
           a = b;
           if( a==b )
               puts("yes");
           else
               puts("no");
    }
    return 0;
}
