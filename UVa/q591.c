#include <stdio.h>

int main(){
    int i, num, a[50], count=0, avg, total;
    
    while( scanf("%d", &num) && num!=0 ){
           count++;
           avg = 0;
           total = 0;
           for( i=0; i<num; i++ ){
              scanf("%d", &a[i]);
              avg += a[i];
           }
           avg /= num;
           for( i=0; i<num; i++ )
              if( a[i] > avg )
                 total += (a[i] - avg);
           printf("Set #%d\nThe minimum number of moves is %d.\n\n", count, total);           
    }
    return 0;
}
