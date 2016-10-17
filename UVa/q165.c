#include <stdio.h>

int pos[100], rec[10][200], use[10], get[10], target, take, stamp, ans, limit;

void backtrack( int n, int j ){
     int i, sum=0;
     
     if( n>target ){
         for( i=1; i<=target; i++ )
              sum += use[i];
         for( i=1; i<=target; i++ )
              if( !rec[pos[use[i]]][sum] ){
                  rec[pos[use[i]]][sum] = 1;
                  rec[0][sum]++;
              }
     }
     else{
          for( i=j; i<=stamp; i++ ){
               use[n] = rec[i][0];
               backtrack(n+1,i);
          }
     }
}

void back( int n ){
     int i, j, tmp;
     
     if( n>stamp ){
         
         for( i=1; i<=limit; i++ )
              rec[0][i] = 0;
         for( i=1; i<=stamp; i++ ){
              limit = (take-1)*rec[stamp][0]+rec[i][0];
              for( j=1; j<=limit; j++ )
                   rec[i][j] = 0;
         }
                     
         for( target=1; target<=take; target++ )
                backtrack(1,1);
    
         for( i=1; i<=limit+1; i++ )
              if( !rec[0][i] ){
                  tmp = i-1;
                  break;
              }
         if( tmp > ans ){
             ans = tmp;
             for( i=1; i<=stamp; i++ )
                  get[i] = rec[i][0];
         }
         
     }
     else{
          rec[n][0] = rec[n-1][0];
          do{
                rec[n][0]++;
                pos[rec[n][0]] = n;
                back(n+1);
          }while( rec[0][rec[n][0]]!=1 );
     }
}

int main(){
    
    int i, j;
    
    while( scanf("%d %d", &take, &stamp) ){
           if( !take )
               break;
           ans = 0;
           limit = 0;
           for( i=0; i<=stamp; i++ )
                for( j=0; j<200; j++ )
                     rec[i][j] = 0;
           
           back(1);
                    
           for( i=1; i<=stamp; i++ )
                printf("%3d", get[i]);
           printf(" ->%3d\n", ans);
    }
    return 0;
}
