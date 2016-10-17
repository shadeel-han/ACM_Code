#include <stdio.h>
#include <string.h>

int main(){
    char prime[2000000];
    int pri[215000], i, j;
    memset(prime,1,sizeof(prime));
    prime[1]--;
    for( i=4; i<2000000; i+=2 )
         prime[i]--;
    for( i=3; i<2000000; i+=2 )
         for( j=i<<1; j<2000000; j+=i )
              if( prime[j] )
                  prime[j]--;
    pri[0] = 1;
    pri[1] = 2;
    j = 2;
    for( i=3; i<2000000; i+=2 )
         if( prime[i] )
             pri[j++] = i;
    
    
    
    return 0;
}
