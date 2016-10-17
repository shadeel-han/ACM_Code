#include <stdio.h>
#include <string.h>

int main(){
    int tol, num, i, j;
    char name[201][81], order[201][81];
    scanf("%d", &tol);
    while(tol--){
       scanf("%d", &num);
       getchar();
       for( i=1; i<=num; i++ )
            gets(name[i]);
       for( i=1; i<=num; i++ )
            gets(order[i]);
       for( i=num,j=num; i>0; i-- )
            if( !strcmp(name[i],order[j]) )
                j--;
       for( j; j>0; j-- )
            puts(order[j]);
       printf("\n");
    }
    return 0;
}
