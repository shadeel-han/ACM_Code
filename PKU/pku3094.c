#include <stdio.h>
#include <string.h>

int main(){
    char in[257];
    int len, i, sum;
    while( gets(in) ){
           if( in[0]=='#' )
               break;
           sum = 0;
           len = strlen(in);
           for( i=0; i<len; i++ ){
                if( in[i]==' ' );
                else
                    sum += (i+1)*(in[i]-64);
           }
           printf("%d\n", sum);
    } 
    return 0;
}
