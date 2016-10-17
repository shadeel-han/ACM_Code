#include <stdio.h>
#include <string.h>
#define sub(x,y) ((x>y)?(x-y):(y-x))

int pos[27], con[27][27], ver[8], per[8], ans, get[8], count;

void backtrack( int n ){
     int tmp=0, tmpans, i, j, k;
     
     if( n==count+1 ){
         for( i=1; i<=con[0][0]; i++ ){
              k = con[0][i];
              for( j=1; j<=con[k][0]; j++ ){
                   tmpans = sub(pos[k],pos[con[k][j]]);
                   if( tmpans > tmp )
                       tmp = tmpans;
              }
         }
         if( tmp < ans ){
             ans = tmp;
             for( i=0; i<8; i++ )
                  get[i] = per[i];
         }
     }
     else{
          for( i=0; i<8; i++ )
               if( ver[i] ){
                   tmp = ver[i];
                   ver[i] = 0;
                   pos[tmp] = n;
                   per[n-1] = tmp;
                   backtrack(n+1);
                   ver[i] = tmp;
               }
     }
}

int main(){
    int i, j, len, head, tmp;
    char in[50];
    
    while( scanf("%s", in) ){
           len = strlen(in);
           if( in[0]=='#' )
               break;
           memset(pos,0,sizeof(pos));
           for( i=0; i<27; i++ )
                con[i][0] = 0;
           ans = 10;
           
           for( i=0; i<len; i++ ){
                if( in[i]==':' ){
                    for( i=i+1; i<len; i++ ){
                         if( in[i]==';' )
                             break;
                         tmp = in[i]-64;
                         con[head][++count] = tmp;
                         pos[tmp] = 1;
                    }
                    con[head][0] = count;
                }
                else{
                    tmp = in[i]-64;
                    count = 0;
                    head = tmp;
                    pos[head] = 1;
                    con[0][++con[0][0]] = tmp;
                }
           }
           count = 0;
           for( i=1; i<27; i++ )
                if( pos[i] )
                    ver[count++] = i;
           backtrack(1);
           for( i=0; i<count-1; i++ )
                printf("%c ", get[i]+64);
           printf("%c -> %d\n", get[count-1]+64, ans);
    }
    return 0;
}
