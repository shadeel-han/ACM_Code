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

           /*�N1*1���]�q��J�w�s�b��5*5*/
           if( kind[1] > left[5] )
               left[1] = kind[1] - left[5];
           else
               left[1] = 0;

           /*�N2*2���]�q��J�w�s�b��4*4*/
           if( kind[2] > left[4] )
               left[2] = kind[2] - left[4];
           else{
               area2 = ((left[4] - kind[2])<<2);
               left[2] = 0;
           }

           /*�N3*3�ɤO��J�ƭӥ]�q*/
           i = kind[3]%4;
           if( i ){
               left[3] = 1;
               area = 36 - (i*9);
               count++;
           }
           else
               left[3] = 0;
           
           /*�p�G2*2�٦��ѡA��w�s�b��3*3*/
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

           /*�p�G1*1�٦��ѡA��J�w�s�b��3*3*/
           if( left[1] && left[3] ){
               if( left[1]>area )
                   left[1] -= area;
               else
                   left[1] = 0;
           }

           /*�ѤU��2*2�ɤO��J�ƭ�6*6*/
           if( left[2] ){ 
               count += ceil(((double)left[2])/9);
               area = 36-(left[2]%9)*4;
           }
           else
               area = 0;

           /*�ѤU��1*1�ɤO��J�w�s�b��4*4�M2*2�A�A��J�ƭ�6*6*/
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
