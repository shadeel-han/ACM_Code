#include<stdio.h>

int map[11][11], walk, num;
int rec[5], use[11], get;

void back( int start, int n ){
     
     int i;
     if( n==walk ){
         printf("(1");
         for( i=0; i<walk; i++ )
              printf(",%d", rec[i]);
         puts(")");
         get = 0;
     }
     else{
          
          for( i=2; i<=num; i++ )
               if( use[i] && map[start][i] ){
                   use[i] = 0;
                   rec[n] = i;
                   back(i,n+1);
                   use[i] = 1;
               }
     }    
}

int main(){
    
    int i, j;
    
    while( 1 ){
           
           scanf("%d %d", &num, &walk);
           
           for( i=1; i<=num; i++ )
                for( j=1; j<=num; j++ )
                     scanf("%d", &map[i][j]);
           get = 1;
           for( i=2; i<11; i++ )
                use[i] = 1;
           back(1,0);
           
           if( get )
               printf("no walk of length %d\n", walk);
           
           if( scanf("%d", &num)!=EOF ){
               putchar('\n');
               continue;
           }
           else
               break;
    }

    return 0;
}
