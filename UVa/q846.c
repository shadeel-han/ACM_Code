#include <stdio.h>
#include <math.h>

int main(){
    int num, start, end, sq, sq2;
    scanf("%d", &num);
    while( num-- ){
           scanf("%d %d", &start, &end);
           end -= start;
           if( !end ){
               printf("0\n");
               continue;
           }
           sq = (int)sqrt(end); /*sq=square-root of distance*/
           sq2 = sq*sq;         /*sq2=square of sq*/
           if( end==sq2 )               /*example sq=6*/
               printf("%d\n", (sq<<1)-1);   /*end=36*/
           else if( end-sq2<=sq )
                printf("%d\n", sq<<1);    /*37<=end<=42*/
           else
               printf("%d\n", (sq<<1)+1);   /*43<=end<=48*/
    }
    return 0;
}
