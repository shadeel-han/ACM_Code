#include <stdio.h>

int main(){
    int up, down, i, j, limit;
    long long int count;
    while(scanf("%d %d", &up, &down)){
       if( !up )
           break;
       if( down>(up>>1) )
           limit = up-down;
       else
           limit = down;
       count = 1;
       for( i=up,j=1; j<=limit; i--,j++ ){
            count *= i;
            count /= j;
       }
       printf("%d things taken %d at a time is %d exactly.\n", up, down, (int)count);
    }
    return 0;
}
