#include <stdio.h>
#include <string.h>

int main(){
    int tol, num, from, to, max, i, j;
    int position[200];
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d", &num);
           memset(position,0,sizeof(position));
           while( num-- ){
                scanf("%d %d", &from, &to);
                if( from<to ){
                    i = (from-1)>>1;
                    j = (to-1)>>1;
                }
                else{
                    i = (to-1)>>1;
                    j = (from-1)>>1;
                }
                for( i; i<=j; i++ )
                     position[i]++;
           }
           for( max=position[0],i=1; i<200; i++ )
                if( position[i]>max )
                    max = position[i];
           printf("%d\n", max*10);       
    }
    return 0;
}
