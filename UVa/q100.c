#include <stdio.h>

int main(){
    int i, j, max, count, temp;
    while( scanf("%d %d", &i, &j) == 2 ){
           printf("%d %d", i, j);
           if( i>j ){
               max = i;
               i = j;
               j = max;
           }
           max = 0;
           while( i<=j ){
                  temp = i++;
                  count = 1;
                  while( temp != 1 ){
                         temp = (temp % 2 == 0)? (temp>>1) : (temp*3+1);
                         count++;
                  }
                  if( count > max )
                     max = count;
           }
           printf(" %d\n", max);
    }
    return 0;
}
