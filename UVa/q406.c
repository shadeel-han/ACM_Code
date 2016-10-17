#include <stdio.h>
#include <string.h>

int main(){
    char prime[1001];
    int i, j, prim[280], num=0, first, second, cnt, half;
    memset(prime,1,sizeof(prime));
    for( i=4; i<1001; i+=2 )
         prime[i]--;
    for( i=3; i<1001; i+=2 )
         for( j=i<<1; j<1001; j+=i )
              if( prime[j] )
                  prime[j]--;
    for( i=1; i<1001; i++ )
         if( prime[i] )
             prim[num++] = i;
    while( scanf("%d %d", &first, &second)!=EOF ){
           cnt = 0;
           for( i=0; i<num; i++ )
                if( prim[i]<=first )
                    cnt++;
           half = (cnt>>1);
           if( cnt&1 )
               half++;
           printf("%d %d:", first, second);
           if( second>=half ){
               for( i=0; i<cnt; i++ )
                    printf(" %d", prim[i]);
               printf("\n\n");
               continue;
           }
           j = ((cnt-(second<<1)+1)>>1);
           i = j;
           j = cnt-j;
           for( i; i<j; i++ )
                printf(" %d", prim[i]);
           printf("\n\n");      
    }
    return 0;
}
