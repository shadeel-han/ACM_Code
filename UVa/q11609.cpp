#include <stdio.h>
#include <math.h>

int main(){
    int i, num;
    long long int in;

    scanf("%d", &num);
    for( i=1; i<=num; i++ ){
        scanf("%lld", &in);
        printf("Case #%d: %lld\n", i, ((in%1000000007)*(((int)pow(2,in-1))%1000000007))%1000000007);
    }
    return 0;
}
