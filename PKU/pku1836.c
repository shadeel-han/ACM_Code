#include <stdio.h> 
 
int main(){
    
    int incre[1001], decre[1001];
    double peo[1001], peo2[1001];
    int i, j, k, num, tmp, left, right, ans;
    
    peo[0] = 0;
    peo2[0] = 0; 
    incre[0] = 0;
    decre[0] = 0; 
    while( scanf("%d", &num)!=EOF ){
           for( i=1; i<=num; i++ )
                scanf("%lf", &peo[i]);
           for( i=1; i<=num; i++ ){
                peo2[num+1-i] = peo[i]; 
                incre[i] = 0;
                decre[i] = 0;
           }
           
           for( i=1; i<=num; i++ )
                for( j=0; j<i; j++ ){
                     if( peo[i] > peo[j] ){ /*做LIS，從左邊看來的LIS*/ 
                         tmp = incre[j]+1;
                         if( tmp > incre[i] )
                             incre[i] = tmp; 
                     } 
                     if( peo2[i] > peo2[j] ){ /*做LDS，從右邊看來的LIS*/ 
                         tmp = decre[j]+1;
                         if( tmp > decre[i] )
                             decre[i] = tmp; 
                     }
                }
           left=1;  right=1;
           for( i=1; i<num; i++ ){
                if( incre[i] > left )
                    left = incre[i]; 
                peo[i] = left;
                if( decre[i] > right )
                    right = decre[i]; 
                peo2[i] = right; 
           } 
           ans = 0;
           for( i=1; i<num; i++ ){
                tmp = peo[i]+peo2[num-i];
                if( tmp>ans )
                    ans = tmp; 
           }  
           printf("%d\n", num-ans); 
    }
    return 0;
} 
    
