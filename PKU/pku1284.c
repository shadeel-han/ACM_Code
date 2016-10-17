#include <stdio.h>
#include <string.h>

int main(){
    
    int i, j, k, in, prim[10000], num=0;
    char prime[65536];
    
    memset(prime,1,sizeof(prime));
    prime[1]--;
    for( i=4; i<65536; i+=2 )
         prime[i]--;
    for( i=3; i<65536; i+=2 )
         for( j=i<<1; j<65536; j+=i )
              if( prime[j] )
                  prime[j]--;
    for( i=2; i<65536; i++ )
         if( prime[i] )
             prim[num++] = i;
    
    while( scanf("%d", &in)!=EOF ){
           memset(prime,1,in*sizeof(char));
           in--;
           k = (in>>1);
           for( i=0; prim[i]<=k; i++ )
                if( !(in%prim[i]) ){
                    for( j=prim[i]; j<in; j+=prim[i] )
                         if( prime[j] )
                             prime[j]--;
                }
           j = 0;
           for( i=1; i<in; i++ )
                if( prime[i] )
                    j++;
           printf("%d\n", j);
    }
    
    return 0;
}
