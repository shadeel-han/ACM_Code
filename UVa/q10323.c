#include <stdio.h>

int main(){
    int in;
    while( scanf("%d", &in)!=EOF ){
           if( in<8 ){
               if(in<0 && (in&1)) puts("Overflow!");    
               else puts("Underflow!");
               continue;
           }
           if( in>13 ){
               puts("Overflow!");
               continue;
           }
           switch(in){
              case 8:puts("40320"); break;
              case 9:puts("362880"); break;
              case 10:puts("3628800"); break;
              case 11:puts("39916800"); break;
              case 12:puts("479001600"); break;
              case 13:puts("6227020800"); break;
           }
    } 
    return 0;
}
