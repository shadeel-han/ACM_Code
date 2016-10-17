#include <stdio.h>
#include <math.h> 
#define INF 1000000000 

int dp[1000001];
typedef struct{
        int pos;
        int reach; 
        }Build;  

int main(){
    
    Build bui[5001];  
    int i, j, k, cas, num, tmp, tmp2;
    long long int ltmp, cmp; 
    
    scanf("%d", &cas);
    while( cas-- ){
           scanf("%d", &num);
           scanf("%d %d", &bui[1].pos, &j);
           for( i=2; i<=num; i++ ){ 
                scanf("%d %d", &bui[i].pos, &tmp);
                cmp = (long long int)tmp; 
                ltmp = cmp*cmp; 
                cmp -= j; 
                ltmp -= cmp*cmp;
                bui[i].reach = sqrt(ltmp); 
           }
           
           for( i=bui[1].pos; i<=bui[num].pos; i++ )
                dp[i] = INF;
           dp[bui[1].pos] = 0; /*start building*/ 

           for( i=2; i<=num; i++ ){
                tmp = bui[i].pos - bui[i].reach;
                if( tmp < bui[1].pos )
                    tmp = bui[1].pos;
                
                tmp2 = bui[i].pos-tmp; /*處理超過終點*/ 
                j = tmp2-bui[num].pos+bui[i].pos;
                if( j>=0 ){
                    tmp2 = INF; 
                    for( j; j>=0; j--,tmp++ )
                         if( dp[tmp] < tmp2 )
                             tmp2 = dp[tmp]; 
                    if( tmp2 < dp[bui[num].pos] )
                        dp[bui[num].pos] = tmp2+1;
                } 
                
                for( j=tmp; j<bui[i].pos; j++ ){
                     if( dp[j]==INF )
                         continue; 
                     tmp = (bui[i].pos<<1)-j;  
                     if( dp[j] < dp[tmp] )
                         dp[tmp] = dp[j]+1; 
                } 
           } 
           
           tmp = dp[bui[num].pos]; 
           if( tmp==INF )
               printf("-1\n");
           else 
                printf("%d\n", tmp); 
    }
    return 0; 
} 
