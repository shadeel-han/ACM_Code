#include <stdio.h> 

int main(){
    
    int dp[1001], in[1001];
    int i, j, num, tmp;
    
    dp[1] = 1; 
    while( scanf("%d", &num)!=EOF ){
           for( i=1; i<=num; i++ )
                scanf("%d", &in[i]);
           for( i=2; i<=num; i++ )
                dp[i] = 1;
           for( i=2; i<=num; i++ ){
                for( j=1; j<i; j++ )
                     if( in[i] > in[j] ){
                         tmp = dp[j] + 1;
                         if( tmp > dp[i] )
                             dp[i] = tmp; 
                     }
           } 
           tmp = 1;
           for( i=2; i<=num; i++ )
                if( tmp < dp[i] )
                    tmp = dp[i];
           printf("%d\n", tmp); 
    } 
    return 0; 
} 
