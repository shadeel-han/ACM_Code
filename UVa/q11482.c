#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, pro, i, ii, j, k, count=0;
    while( scanf("%d %d", &a, &b) ){
       if( a==0 )  /*a=size,b=level*/
           break;
       printf("Triangular Museum %d\n", ++count);
       pro = a * b;
       for( i=1; i<=b; i++ )
            for( j=1; j<=a; j++ ){
                 ii = i+1;
                 for( k=(--pro); k>0; k-- ) /*the space of every line*/
                      printf(" ");          /*because decreasing, use --pro*/
                 while(--ii){       /*only print upright triangles, the number depends on the level, so ii=i+1*/
                    printf("/");
                    if( j==a )                           /*if print the last line of triangles of every level, print underline*/
                        for( k=0; k<((j-1)<<1); k++ )
                             printf("_");
                    else if( j!=1 )                      /*else print the space*/
                         for( k=0; k<((j-1)<<1); k++ )
                              printf(" ");
                    printf("\\");
                    if( ii>1 )
                        for( k=0; k<(((a-j)<<1)); k++ )
                             printf(" ");
                    else
                        printf("\n");
                 }
            }
       printf("\n");
    }
    return 0;
}
