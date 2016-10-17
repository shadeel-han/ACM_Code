#include <stdio.h>
#include <math.h>

int main(){
    int num, i;
    long long int get;
    scanf("%d", &num);
    while( (num--)>0 ){
           scanf("%lld", &get);
           printf("%d\n", (int)ceil(sqrt((get<<1)+2.25)-0.5)-1 );
    }
    return 0;
}
