#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dfn[101], low[101], map[101][101];
int state[101], back[101], head[101], ver, cnt;

void DFS( int n ){
     
     int i, child=0;
     state[n] = 0;
     dfn[n] = cnt;
     low[n] = cnt++;
     
     for( i=1; i<=ver; i++ )
          if( map[n][i] ){
              if( state[i] ){
                  map[i][n] = 0;
                  DFS(i);
                  child++;
              }
              else{
                   map[n][i] = 0;
                   map[i][n] = 0;
                   if( dfn[i] < back[n] )
                       back[n] = dfn[i];
              }
          }
     state[n] = child;  /*record the number of child*/
}

void SetLow( int n ){
     
     int i, cmp=low[n];
     
     for( i=1; i<=ver; i++ )
          if( map[n][i] ){
              SetLow(i);
              if( cmp > low[i] )
                  cmp = low[i];
          }
     if( back[n]!=1000 )
         if( cmp > back[n] )
             cmp = back[n];
     low[n] = cmp;
}

void GetAns( int n ){
     
     int i, cmp;
     
     if( state[n]<2 ){
         cmp = 1000;
         for( i=1; i<=ver; i++ )
              if( map[n][i] ){
                  GetAns(i);
                  if( cmp > low[i] )
                      cmp = low[i];
              }
     }
     else{
          cmp = 0;
          for( i=1; i<=ver; i++ )
               if( map[n][i] ){
                   GetAns(i);
                   if( cmp < low[i] )
                       cmp = low[i];
               }
     }
     back[n] = cmp;
}

int main(){
    
    int num, i, j, start, end;
    char in[400], *p;
    
    while( scanf("%d", &ver)!=EOF ){
           
           if( !ver )
               break;
           
           for( i=1; i<=ver; i++ ){
                state[i] = -1;
                head[i] = 0;
                back[i] = 1000;
           }
           
           for( i=1; i<=ver; i++ )
                for( j=1; j<=ver; j++ )
                     map[i][j] = 0;
           
           getchar();
           while( 1 ){
                  gets(in);
                  p = strtok(in, " ");
                  start = atoi(p);
                  if( !start )
                      break;
                  p = strtok(NULL, " ");
                  while( p!=NULL ){
                         end = atoi(p);
                         map[start][end] = 1;
                         map[end][start] = 1;
                         p = strtok(NULL, " ");
                  }
           }
           
           for( i=1; i<=ver; i++ )
                if( state[i]==-1 ){
                    cnt = 1;
                    DFS(i);
                    head[i] = 1;
                }
           
           for( i=1; i<=ver; i++ )
                if( head[i] )
                    SetLow(i);
                
           for( i=1; i<=ver; i++ )
                if( head[i] )
                    GetAns(i);
           /*printf("dfn   ");
           for( i=1; i<=ver; i++ )
                printf("%d ", dfn[i]);
           printf("\nlow   ");
           for( i=1; i<=ver; i++ )
                printf("%d ", low[i]);
           printf("\nback  ");
           for( i=1; i<=ver; i++ )
                printf("%d ", back[i]);
           printf("\nchli  ");
           for( i=1; i<=ver; i++ )
                printf("%d ", state[i]);
           putchar('\n');*/
             
           for( i=1,j=0; i<=ver; i++ ){
                if( head[i] ){
                    if( state[i]>=2 ){
                        /*printf("%d\n", i);*/
                        j++;
                    }
                    else if( !state[i] ){
                         /*printf("%d\n", i);*/
                         j++;
                    }
                }
                else if( state[i] && (back[i]>=dfn[i]) ){
                         /*printf("%d\n", i);*/
                         j++;
                }
           }
           printf("%d\n", j);
    }
    return 0;
}
