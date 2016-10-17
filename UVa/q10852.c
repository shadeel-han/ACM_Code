#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i, j, num, in, sq;
    scanf("%d", &num);
    while((--num)>=0){
       scanf("%d", &in);
       for( i=(in>>1)+1; i<=10000; i++ ){
            sq = (int)sqrt(i);
            for( j=2; j<=sq; j++ )
                 if( i == (int)(i/j)*j )
                     break;
            if( j>sq ){
                printf("%d\n", i);
                break;
            }
       }
    }
    return 0;
}
