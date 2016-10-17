#include <stdio.h>
#include <math.h>

int main(){
    int kind[7], i, count, left[6], area, area2;
    
    while( scanf("%d %d %d %d %d %d", &kind[1], &kind[2], &kind[3], &kind[4], &kind[5], &kind[6] ) ){
           if( !kind[1] && !kind[2] && !kind[3] && !kind[4] && !kind[5] && !kind[6] )
               break;
           area2 = 0;
           area = 0;
           count = kind[6] + kind[5] + kind[4] + (kind[3]>>2);
           left[5] = kind[5]*11;
           left[4] = kind[4]*5;

           /*將1*1的包裹塞入已存在的5*5*/
           if( kind[1] > left[5] )
               left[1] = kind[1] - left[5];
           else
               left[1] = 0;

           /*將2*2的包裹塞入已存在的4*4*/
           if( kind[2] > left[4] )
               left[2] = kind[2] - left[4];
           else{
               area2 = ((left[4] - kind[2])<<2);
               left[2] = 0;
           }

           /*將3*3盡力塞入數個包裹*/
           i = kind[3]%4;
           if( i ){
               left[3] = 1;
               area = 36 - (i*9);
               count++;
           }
           else
               left[3] = 0;
           
           /*如果2*2還有剩，塞已存在的3*3*/
           if( left[2] && left[3] ){
               if( left[2]<(7-(i<<1)) ){
                   area = area - left[2]*4;
                   left[2] = 0;
               }
               else{
                   left[2] -= (7-(i<<1));
                   area = 8-i;
               }
           }

           /*如果1*1還有剩，塞入已存在的3*3*/
           if( left[1] && left[3] ){
               if( left[1]>area )
                   left[1] -= area;
               else
                   left[1] = 0;
           }

           /*剩下的2*2盡力塞入數個6*6*/
           if( left[2] ){ 
               count += ceil(((double)left[2])/9);
               area = 36-(left[2]%9)*4;
           }
           else
               area = 0;

           /*剩下的1*1盡力塞入已存在的4*4和2*2，再塞入數個6*6*/
           if( left[1] ){
               if( area2>0 )
                   left[1] -= area2;
               if( left[1]>0 )
                   left[1] -= area;
               if( left[1]>0 ){
                   count += ceil(((double)left[1])/36);
               }
           }

           printf("%d\n", count);
    }
    return 0;
}
