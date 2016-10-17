#include <stdio.h>

int main(){
    long long int in;
    while( scanf("%lld", &in) ){
           if( in<0 )
               break;
           if( in==1 )
               puts("0%");
           else
               printf("%lld%%\n", in*25);
    }
    return 0;
}
