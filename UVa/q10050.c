#include <stdio.h>
#include <stdlib.h>

int main(){
   int day[3650]={0}, har[100];
   int i, j, num, days, poli, count, now=0;
   scanf("%d", &num);
   while( num-- ){
      now++;
      count = 0;
      scanf("%d", &days);
      scanf("%d", &poli);
      for( i=0; i<poli; i++ )
         scanf("%d", &har[i]);
      for( i=0; i<poli; i++ )
           for( j=har[i]-1; j<days; j+=har[i] )
                day[j] = now;
      for( i=0; i<days; i++ ){
           if( (i-5)%7==0 )
               i += 2;
           if( day[i]==now )
               count++;
      }
      printf("%d\n", count);
   }
   return 0; 
}
