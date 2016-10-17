#include <stdio.h>

int main(){
    int a, b, c[10], begin[10], temp;
    long long int sum;
    int i, j, diga, digb, aOK, bOK, cOK;
    while( scanf("%d %d", &a, &b) && a>-1 ){
          sum = 0;
          aOK = 1;
          bOK = 1;
          cOK = 1;
          
          c[9] = b/1000000000 - a/1000000000;
          c[8] = b/100000000 - a/100000000 - c[9];
          c[7] = b/10000000 - a/10000000 - c[9] - c[8];
          c[6] = b/1000000 - a/1000000 - c[9] - c[8] -c[7];
          c[5] = b/100000 - a/100000 - c[9] - c[8] - c[7] - c[6];
          c[4] = b/10000 - a/10000 - c[9] - c[8] - c[7] - c[6] - c[5];
          c[3] = b/1000 - a/1000 - c[9] - c[8] - c[7] - c[6] - c[5] - c[4];
          c[2] = b/100 - a/100 - c[9] - c[8] - c[7] - c[6] - c[5] - c[4] - c[3];
          c[1] = b/10 - a/10 - c[9] - c[8] - c[7] - c[6] - c[5] - c[4] - c[3] - c[2];
          c[0] = b - a - c[9] - c[8] - c[7] - c[6] - c[5] - c[4] - c[3] - c[2] - c[1];
          
          for( i=0; i<10; i++ ){
               if( i==0 )
                  temp = 1;
               else
                  temp *= 10;
               begin[i] = (a/temp)%10;
               if( cOK ){
                  if( (a%temp)!=0 ){
                     cOK = 0;
                     if( i!=0 )
                        c[i-1]++;
                  }
               }
               if( aOK && (a/temp==0) ){
                   diga = i;
                   aOK = 0;
               }
               if( bOK && (b/temp==0) ){
                   digb = i;
                   bOK = 0;
               }
               if( i==9 ){
                   if( a/temp!=0 )
                      diga = 10;
                   if( b/temp!=0 )
                      digb = 10;
               }
          }
          
          for( i=0; i<diga; i++ ){
               if( i==0 )
                  temp = 1;
               else
                  temp *= 10;
               if( (i!=0) && (a%temp!=0) )
                  if( (++begin[i]) == 10 )
                   begin[i] = 1;
          }
          for( i=0; i<diga; i++ )
             if( begin[i] == 0 )
                begin[i] = 1;
          for( i=diga; i<digb; i++ )
             begin[i] = 1;
             
          if( a==1000000000 || a==2000000000 )
              c[9]++;
              
          for( i=0; i<digb; i++ ){
             sum += ((((long long int)c[i])/9)*45);
             c[i] %= 9;
             for(j=0; j<c[i]; j++){
                temp = begin[i] + j;
                if( temp > 9 )
                   sum += (((long long int)(temp)) % 9);
                else
                   sum += ((long long int)temp);
             }
          }
          printf("%lld\n", sum);
    }
    return 0;
}
