#include <stdio.h>

int in[12], rec[12], count, num;

void back( int n ){
     if( n==num ){
         if( count==6 ){
             int i;
             for( i=0; i<num-1; i++ )
                  if( rec[i] )
                      printf("%d ", in[i]);
             if( rec[num-1] )
                 printf("%d\n", in[num-1]);
         }
     }
     else{
          rec[n] = 1;
          count++;
          back(n+1);
          rec[n] = 0;
          count--;
          back(n+1);
     }
}

int main(){
    int i;
    while( scanf("%d", &num) ){
           if( !num )
               break;
           for( i=0; i<num; i++ )
                scanf("%d", &in[i]);
           count = 0;
           back(0);
    }
    return 0;
}
