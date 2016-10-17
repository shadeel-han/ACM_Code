#include <stdio.h>
#include <string.h>

int main(){
    char prime[10008];
    int i, j, in, match, count, num=0, prim[1232];
    memset(prime,1,sizeof(prime));
    prime[1]--;
    for( i=4; i<10008; i+=2 )
         prime[i]--;
    for( i=3; i<10008; i+=2 )
         for( j=i<<1; j<10008; j+=i )
              if( prime[j] )
                  prime[j]--;
    for( i=2; i<10008; i++ )
         if( prime[i] )
             prim[num++] = i;
    while( scanf("%d", &in) ){
           if( !in )
               break;
           match = 0;
           count = 0;
           for( j=0; prim[j]<=in; j++ );
           for( i=j-1; i>=0 ;i-- ){
                match += prim[i];
                if( match==in ){
                    count++;
                    match -= prim[--j];
                }
                else if( match>in )
                     match -= prim[--j];
           }
           printf("%d\n", count);
    }
    return 0;
}
