#include <stdio.h>
#include <stdlib.h>

long long int compute(int number, int maximum) 
{ 
   if (number==0 || number==1 || maximum==1)
      return 1;
   else if( maximum==2 )
      return (number>>1)+1;
   /*else if (number<maximum)
      return compute(number, number); */
   else if (number<=maximum)
      return 1+compute(number,number-1); 
   else 
      return compute(number, maximum-1)+ compute(number-maximum, maximum);
}

int main(){
    int num, i;
    long long int tol, sel, out;
    scanf("%d", &num);
    for( i=0; i<num; i++ ){
         scanf("%lld %lld", &sel, &tol);
         //tol -= (sel*(sel+1))>>1;
         out = compute(tol, sel)%1000000007;
         printf("%lld\n", out);
    }
    return 0;
}
