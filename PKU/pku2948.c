#include <stdio.h>

int dp[501][501], blo[501][501], yey[501][501];

int main(){
    
    int row, col, i, j, k, gblo, gyey;
    
    for( i=0; i<501; i++ )
         dp[0][i] = 0;
    for( i=1; i<501; i++ )
         dp[i][0] = 0;
    
    while( scanf("%d %d", &row, &col) ){
           if( !row )
               break;
           for( i=1; i<=row; i++ )
                for( j=1; j<=col; j++ )
                     scanf("%d", &yey[i][j]);
           for( i=1; i<=row; i++ )
                for( j=1; j<=col; j++ )
                     scanf("%d", &blo[i][j]);
           for( i=1; i<=row; i++ )
                for( j=2; j<=col; j++ )
                     yey[i][j] += yey[i][j-1];
           for( i=1; i<=col; i++ )
                for( j=2; j<=row; j++ )
                     blo[j][i] += blo[j-1][i];
                     
           for( i=1; i<=row; i++ )
                for( j=1; j<=col; j++ ){
                     gblo = dp[i][j-1] + blo[i][j];
                     gyey = dp[i-1][j] + yey[i][j];
                     if( gblo>gyey )
                         dp[i][j] = gblo;
                     else
                         dp[i][j] = gyey;
                     /*dp[i][j] = (gblo>gyey)?(gblo):(gyey);*/
                }
           
           printf("%d\n", dp[row][col]);
    }
    return 0;
}
