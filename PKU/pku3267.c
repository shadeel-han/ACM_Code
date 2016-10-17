#include <stdio.h>
#include <string.h>
#define INF 100000000

int main(){
    
    char dic[601][30], in[301], len[601];
    int dp[301], dicnum, inlen, i, j, k, m, n, index, tmp;
    
    dp[0] = 0;
    while( scanf("%d %d", &dicnum, &inlen)!=EOF ){
           scanf("%s", in);
           
           for( i=inlen; i>0; i-- )
                in[i] = in[i-1];

           for( i=1; i<=dicnum; i++ ){
                scanf("%s", dic[i]);
                len[i] = strlen(dic[i]);
           }
           
           for( i=1; i<=inlen; i++ )
                dp[i] = i;
           
           for( i=1; i<=inlen; i++ ){
                /*for( j=i-1; j>=0; j-- ){*/
                     for( m=1; m<=dicnum; m++ ){  /*dictionary check*/
                          index = len[m]-1;
                          for( n=i; n>0; n-- ){
                               if( dic[m][index]==in[n] )
                                   index--;
                               if( index==-1 ){
                                   n--;
                                   break;
                               }
                          }
                          if( index!=-1 )
                              continue;
                          tmp = i-n-len[m];
                          tmp += dp[n];
                          if( tmp < dp[i] )
                              dp[i] = tmp;
                     }
                /*}*/
           }
           
           
           printf("%d\n", dp[inlen]);
    }
    return 0;
}
