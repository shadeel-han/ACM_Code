#include <stdio.h>

int main(){
    int i;
    while( scanf("%d", &i) && i ){
           if( i<=101 )
              printf("f91(%d) = 91\n", i);
           else
              printf("f91(%d) = %d\n", i, i-10);
    }
    return 0;
}
