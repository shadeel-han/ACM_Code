#include <stdio.h>
#include <string.h>

int main(){
    char prime[1000000];
    int i, j, start, num, which;
    memset(prime,1,sizeof(prime));
    prime[1]--;
    for( i=4; i<1000000; i+=2 )
         prime[i]--;
    for( i=3; i<1000000; i+=2 )
         for( j=i<<1; j<1000000; j+=i )
              if( prime[j] )
                  prime[j]--;
    while( scanf("%d %d %d", &start, &num, &which) ){
           if( !num )
               break;
           for( start; which; start+=num )
                if( prime[start] )
                    which--;
           printf("%d\n", start-num);
    }
    return 0;
}
