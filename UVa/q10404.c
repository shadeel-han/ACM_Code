#include <stdio.h>
#include <string.h>

char dp[1000001] ;

int main ()
{
    int goal , n , i , j , tmp, m[10];
    char win ;
    while ( scanf("%d",&goal)!=EOF )
    {
          scanf ("%d",&n) ;
          memset(dp,0,(goal+1)*sizeof(char)) ;
          for ( i=0 ; i<n ; i++ )
          {
              scanf("%d",&m[i]) ;
              dp[m[i]] = 1 ;
          }
          for ( i=2 ; i<=goal ; i++ )
          {
              if ( dp[i] )
                  continue ;
              win = 0 ;
              for ( j=0 ; j<n ; j++ )
              {
                  tmp = i - m[j];
                  if ( tmp<=0 )
                     continue;
                  if ( !dp[tmp] )
                  {
                     win++;
                     break;
                  }
              }
              dp[i] = win ;
          }
          if ( dp[goal] )
             puts ("Stan wins") ;
          else
              puts ("Ollie wins") ;
    }
    
    return 0 ;
} 
