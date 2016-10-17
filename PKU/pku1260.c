#include <stdio.h>

int main(){
    int i, j, sum, tmp, tol, cla, num[1001], pri[1001] ,dp[1001];
    
    dp[0] = 0;
    num[0] = 0; 
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d", &cla);
           for( i=1; i<=cla; i++ ){
                dp[i] = 100000000;
                scanf("%d %d", &tmp, &pri[i]);
                num[i] = num[i-1]+tmp; 
           }
           dp[1] = (num[1]+10)*pri[1]; 
           for( i=2; i<=cla; i++ ){
                for( j=i-1; j>=0; j-- ){
                     sum = num[i]-num[j]; 
                     tmp = dp[j] + (sum+10)*pri[i];
                     if( tmp < dp[i] )
                         dp[i] = tmp;
                }
           }
           printf("%d\n", dp[cla]);
           
    }
    return 0;
} 
