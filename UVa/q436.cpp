#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

double dp[31][31];
map<string,int> rec;


int main(){
    
    int num, i, j, k, ver, cnt=0;
    double tmp;
    char in[100], *p;
    string st;
    
    while( scanf("%d", &ver) ){
           if( !ver )
               break;
           getchar();
           for( i=1; i<=ver; i++ ){
                gets(in);
                st.clear();
                st.append(in);
                rec[st] = i;
           }
           memset(dp,0,sizeof(dp));
           scanf("%d", &num);
           getchar();
           while( num-- ){
                gets(in);
                p = strtok(in, " ");
                st.clear();
                st.append(p);
                j = rec[st];
                p = strtok(NULL, " ");
                tmp = atof(p);
                p = strtok(NULL, " ");
                st.clear();
                st.append(p);
                k = rec[st];
                dp[j][k] = tmp;
           }
           
           for( k=1; k<=ver; k++ )
                for( i=1; i<=ver; i++ )
                     for( j=1; j<=ver; j++ ){
                          tmp = dp[i][k]*dp[k][j];
                          if( tmp > dp[i][j] )
                              dp[i][j] = tmp;
                     }
           
           for( i=1,j=1; i<=ver; i++ )
                if( dp[i][i]>1.0 ){
                    printf("Case %d: Yes\n", ++cnt);
                    j--;
                    break;
                }
           if( j )
               printf("Case %d: No\n", ++cnt);
           
    }
    return 0;
}
