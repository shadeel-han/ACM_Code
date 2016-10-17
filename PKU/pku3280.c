#include <stdio.h>

int dp[2002][2002];

int main(){
    
    int val[26], sum[2002];
    int num, len, i, j, tmpa, tmpb, back;
    char in[2002], t;
    
    sum[0] = 0;
    while( scanf("%d %d", &num, &len)!=EOF ){
           scanf("%s", in);
           for( i=len-1; i>=0; i-- )
                in[i+1] = in[i]-'a';
           for( i=0; i<num; i++ ){
                getchar();
                scanf("%c %d %d", &t, &tmpa, &tmpb);
                if( tmpa < tmpb )
                    val[t-'a']=tmpa;
                else
                    val[t-'a']=tmpb;
                /*val[t-'a']=(tmpa<tmpb)?(tmpa):(tmpb);*/
           }
           back = len+1;
           for( tmpa=0,i=1; i<back; i++ ){
                tmpa += val[in[i]];
                sum[i] = tmpa;
           }
           for( i=0; i<back; i++ ){
                dp[i][back] = sum[i];
                dp[0][i+1] = sum[len]-sum[i];
           }
           for( i=1; i<len; i++ )
                for( j=len; j>i; j-- ){
                     tmpa = dp[i-1][j]+val[in[i]];
                     tmpb = dp[i][j+1]+val[in[j]];
                     if( tmpb < tmpa )
                         tmpa = tmpb;
                     /*tmpa = (tmpa<tmpb)?(tmpa):(tmpb);*/
                     if( in[i]==in[j] ){
                         tmpb = dp[i-1][j+1];
                         if( tmpb < tmpa )
                             tmpa = tmpb;
                         /*tmpa = (tmpa<tmpb)?(tmpa):(tmpb);*/
                     }
                     dp[i][j] = tmpa;
                }
           tmpa = 2000000000;
           for( i=0; i<len; i++ ){
                tmpb = i+2;
                if( tmpa > dp[i][tmpb] )
                    tmpa = dp[i][tmpb];
           }
           for( i=0; i<back; i++ ){
                tmpb = i+1;
                if( tmpa > dp[i][tmpb] )
                    tmpa = dp[i][tmpb];
           }
                
           printf("%d\n", tmpa);
           
    }
    
    return 0;
}
