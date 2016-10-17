#include <stdio.h>
#include <string.h>

int main(){
    
    int i, j, sum, a, b;
    char in[22], prime[1041];
    
    memset(prime,1,sizeof(prime));
    for( i=4; i<1041; i+=2 )
         prime[i]--;
    for( i=3; i<1041; i+=2 )
         for( j=i<<1; j<1041; j+=i )
              if( prime[j] )
                  prime[j]--;

    while( gets(in)!=NULL ){
           sum = 0;
           a=0; b=0;
           for( i=0; in[i]!='\0'; i++ ){
                if( in[i]<'a' ){
                    sum += (in[i]-'A');
                    a++;
                }
                else{
                    sum += (in[i]-'a');
                    b++;
                }
           }
           sum += ( 27*a+b );
           if( prime[sum] )
               puts("It is a prime word.");
           else
               puts("It is not a prime word.");
    }
    return 0;
}
