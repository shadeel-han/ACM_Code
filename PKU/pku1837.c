#include <stdio.h> 
#define abs(x) ((x>0)?(x):(-x)) 

int main(){
    
    int dp[21][5070]; 
    int torq[21][21], pos[21], wei[21], num[21];
    int h, i, j, k, hook, weight, adjust, limit, tmp;
    
    for( i=2; i<=20; i++ )
         num[i] = 0;
    while( scanf("%d %d", &hook, &weight)!=EOF ){
           for( i=1; i<=hook; i++ )
                scanf("%d", &pos[i]);
           for( i=1; i<=weight; i++ )
                scanf("%d", &wei[i]);
           for( i=1; i<=weight; i++ )
                for( j=1; j<=hook; j++ ) 
                     torq[i][j] = wei[i]*pos[j];
           i = abs(pos[1]);
           j = abs(pos[hook]);
           adjust = (i>j)?(i):(j); 

           k = 0; 
           for( i=1; i<=weight; i++ )
                k += wei[i];
           j = k >> 1;  k = 0; 
           for( i=1; i<=weight; i++ ){
                k += wei[i];
                if( k >= j )
                    break; 
           }
           adjust *= k; /*力矩合為負時的儲存調整*/ 
           limit = adjust << 1; 
           for( i=1; i<=weight; i++ ) 
                for( j=0; j<=limit; j++ )
                     dp[i][j] = 0;
           for( i=1; i<=hook; i++ )
                dp[1][torq[1][i]+adjust] = 1;
           num[1] = hook;
            
           for( i=2; i<=weight; i++ ){
                h = i-1; 
                for( j=0; j<=limit; j++ ){ 
                     if( dp[h][j] ){
                         num[h]--; 
                         for( k=1; k<=hook; k++ ){ 
                              tmp = j+torq[i][k] ;  
                              if( tmp>=0 && tmp<=limit ){
                                  if( !dp[i][tmp] )
                                      num[i]++; 
                                  dp[i][tmp]+=dp[h][j]; 
                              }
                         } 
                     }
                     if( !num[h] )
                         break; 
                } 
           }
           
           printf("%d\n", dp[weight][adjust]); 
    } 
    return 0;
} 
