#include <stdio.h>

int main(){
    unsigned int in;
    long long int in2;
    while( scanf("%u", &in)!=EOF ){
           in2 = in*(in+1)>>1;        
           printf("%lld\n", in2*in2);
    }
    return 0;
}
