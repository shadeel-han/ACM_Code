#include <stdio.h>

int main(){
    int tol, num, in, stack[20], rec[20], pointer, i, j, tmp;
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d", &num);
           pointer = 0;
           for( i=0; i<num; i++ ){
                  scanf("%d", &in);
                  if( in!=pointer ){
                      for( pointer; pointer<in-1; pointer++ )
                           stack[pointer] = 1;
                      stack[pointer++] = 0;
                      rec[i] = 1;
                  }
                  else
                       for( j=2; ; j++ ){
                            tmp = pointer - j;
                            if( stack[tmp] ){
                                stack[tmp]--;
                                rec[i] = j;
                                break;
                            }
                       }
           }
           printf("%d", rec[0]);
           for( i=1; i<num; i++ )
                printf(" %d", rec[i]);
           printf("\n");
    }
    return 0;
}
