#include <stdio.h>

int main(){
    int i, j, count, num=0;
    while( scanf("%d", &i) ){
           num++;
           if( i>0 ){
              j = 1;
              count = 0;
              while( i>j ){
                  j *= 2;
                  count++;
              }
              printf("Case %d: %d\n", num, count);
           }
           else break;
    }
    return 0;
}
