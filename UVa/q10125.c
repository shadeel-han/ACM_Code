#include <stdio.h>

int main(){
    int num, i, j, k, l, judge;
    int a[1000], temp;
    while( scanf("%d", &num) && num!=0 ){
           for(i=0; i<num; i++)
              scanf("%d", &a[i]);
           for(i=0; i<(num-1); i++)
              for( j=i+1; j<num; j++ )
                 if( a[i] < a[j] ){
                     temp = a[j];
                     a[j] = a[i];
                     a[i] = temp;
                 }
           if( num < 4 )
              printf("no solution\n");
           else{
              judge = 1;
              for( l=0; l<num && judge; l++ )
                 for( k=0; k<(num-2) && judge; k++ )
                    for( j=k+1; j<(num-1) && judge; j++ )
                       for( i=j+1; i<num && judge; i++ )
                          if( k!=l && j!=l && i!=l && a[l]==(a[i] + a[j] + a[k]) ){
                             printf("%d\n", a[l]);
                             judge = 0;
                          }
           }
           if( judge && num>=4 )
                 printf("no solution\n");
    }
    return 0;
}
