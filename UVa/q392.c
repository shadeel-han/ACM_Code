#include <stdio.h>

int main(){
    int in[9], i;
    while(scanf("%d %d %d %d %d %d %d %d %d", &in[8], &in[7], &in[6], &in[5], &in[4], &in[3], &in[2], &in[1], &in[0])!=EOF){
       for( i=8; i>0; i-- )
        if( in[i] )
            break;
       if( !i ){
           printf("%d\n", in[i]);
           continue;
       }
       else if( i==1 ){
              if( in[i]==1 )
                  printf("x");
              else if( in[i]==-1 )
                  printf("-x");
              else
                  printf("%dx", in[i]);
       }
       else{
           if( in[i]==-1 )
                printf("-x^%d", i);
           else if( in[i]==1 )
                printf("x^%d", i);
           else
                printf("%dx^%d", in[i], i);
           for( i-- ; i>1; i-- ){
              if( in[i]>0 ){
                  if( in[i]==1 )
                      printf(" + x^%d", i);
                  else
                      printf(" + %dx^%d", in[i], i);
              }
              else if( in[i] ){
                  if( in[i]==-1 )
                      printf(" - x^%d", i);
                  else
                      printf(" - %dx^%d", -in[i], i);
              }
           }
           if( in[i]>0 ){
                  if( in[i]==1 )
                      printf(" + x");
                  else
                      printf(" + %dx", in[i]);
           }
           else if( in[i] ){
                  if( in[i]==-1 )
                      printf(" - x");
                  else
                      printf(" - %dx", -in[i]);
           }
       }
       
       if( in[--i]>0 )
           printf(" + %d", in[i]);
       else if( in[i] ){
            printf(" - %d", -in[i]);
       }
       printf("\n");
       
    }
    return 0;
 }
