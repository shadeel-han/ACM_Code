#include <stdio.h>

int main(){
    long long int i;
    while( scanf( "%lld", &i )!=EOF ){
           /*sum = (6+6*((i+1)>>1))*(((i+1)>>1)-1)-3;*/
           printf("%lld\n", (6+6*((i+1)>>1))*(((i+1)>>1)-1)-3);           
    }
    return 0;
}
