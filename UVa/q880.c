#include <stdio.h>
#include <math.h>

int main(){
    unsigned int i, j;
    while( scanf( "%u", &i )!=EOF ){
           j = (int)ceil(sqrt(0.25+(i<<1))-0.5);
           i -= (((j-1)*(j++))>>1);
           printf("%u/%u\n", j-i, i);
    }
    return 0;
}
