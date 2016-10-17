#include <stdio.h>

int main(){
    int count, num, i, a[1000]; 
    double per, avg;
    
    scanf("%d", &count);
    while( count-- ){
         avg = 0;
         per = 0;
         scanf("%d", &num);
         for( i=0; i<num; i++ ){
            scanf("%d", &a[i]);
            avg += a[i];
         }
         avg /= num;
         for( i=0; i<num; i++ )
              if( avg < a[i] )
                 per++;
         printf("%.3f%%\n", per*100/num);
    }
    return 0;
}
