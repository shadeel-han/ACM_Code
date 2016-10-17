#include <stdio.h>
#include <string.h>

int main(){
    char prime[1000000];
    int i, j, in, half, tmp;
    memset(prime,1,sizeof(prime));
    prime[1]--;
    for( i=4; i<1000000; i+=2 )
         prime[i]--;
    for( i=3; i<1000000; i+=2 )
         for( j=i<<1; j<1000000; j+=i )
              if( prime[j] )
                  prime[j]--;
    while( scanf("%d", &in) ){
           if( !in )
               break;
           half = in>>1;
           for( i=3; i<=half; i+=2 )
                if( prime[i] ){
                    tmp = in-i;
                    if( prime[tmp] )
                        break;
                }
           if( i<=half )
               printf("%d = %d + %d\n", in, i, tmp);
           else
               printf("Goldbach's conjecture is wrong.\n" );
    }
    return 0;
}
