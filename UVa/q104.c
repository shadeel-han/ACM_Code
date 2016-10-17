#include <stdio.h>

double dp[21][21][21];
int walk[21][21][21], num[21][21][21], path[21], ver;

void visit( int start, int end, int step, int level ){
     
     if( level==1 ){
         path[step] = walk[start][end][1];
     }
     else{
          visit(start,walk[start][end][level],step-num[start][end][level],level-num[start][end][level]);
          visit(walk[start][end][level],end,step,num[start][end][level]);
     }
}

int rec(){
     
     double tmp, cmp;
     int level, i, j, k, m, cnt, step;
     
     for( level=2; level<=ver; level++ )
          for( i=1; i<=ver; i++ )
               for( j=1; j<=ver; j++ ){
                    cmp = 0;
                    for( k=1; k<=ver; k++ ){
                              for( m=1; m<level; m++ ){
                                  tmp = dp[i][k][m]*dp[k][j][level-m];
                                  if( tmp > cmp ){
                                      cmp = tmp;
                                      cnt = level-m;
                                      step = k;
                                  }
                              }
                    }
                    dp[i][j][level] = cmp;
                    walk[i][j][level] = step;
                    num[i][j][level] = cnt;
                    
                    if( i==j && dp[i][j][level]>1.01 ){
                        path[level] = i;
                        
                        visit(i,j,level-1,level);
                        
                        printf("%d", path[0]);
                        for( i=1; i<=level; i++ )
                             printf(" %d", path[i]);
                        putchar('\n');
                        return 0;
                    }
               }
     return 1;
}

int main(){
    
    int i, j;
    
    while( scanf("%d", &ver)!=EOF ){
           for( i=1; i<=ver; i++ )
                dp[i][i][1] = 1;
           for( i=1; i<=ver; i++ )
                for( j=1; j<=ver; j++ )
                     if( i!=j )
                         scanf("%lf", &dp[i][j][1]);
           
           for( i=1; i<=ver; i++ )
                for( j=1; j<=ver; j++ ){
                     walk[i][j][1] = i;
                     num[i][j][1] = 1;
                }
           
           if( rec() )
               puts("no arbitrage sequence exists");
    }
    return 0;
}
