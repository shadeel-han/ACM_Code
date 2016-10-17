#include <stdio.h>

int main(){
    int start, count=0, i;
    int a[12], b[12];
    
    while( scanf("%d", &start) ){
           if( start>-1 ){
               count++;
               scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9], &a[10], &a[11]);
               scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &b[10], &b[11]);
               if( start >= b[0] ){
                   printf("Case %d:\nNo problem! :D\n", count);
                   start -= b[0];
               }
               else
                   printf("Case %d:\nNo problem. :(\n", count);
               for( i=1; i<12; i++ ){
                    start += a[i-1];
                    if( start >= b[i] ){
                       printf("No problem! :D\n");
                       start -= b[i];
                    }
                    else
                       printf("No problem. :(\n");
               }
           }
           else break;
    } 
    return 0;
}
