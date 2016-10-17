#include <stdio.h>

int main(){
    
    char in[1002];
    int num, i, a, b;
    while( gets(in) ){
           num = strlen(in);
           if( num==1 && in[0]=='0' )
               break;
           a=0; b=0;
           for( i=0; i<num; i+=2 )
                a += (in[i]-'0');
           for( i=1; i<num; i+=2 )
                b += (in[i]-'0');
           if( a > b )
               i = a - b;
           else
               i = b - a;
           if( i%11 )
               printf("%s is not a multiple of 11.\n", in);
           else
               printf("%s is a multiple of 11.\n", in);
    }
    return 0;
}
