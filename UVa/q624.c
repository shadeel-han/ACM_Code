#include <stdio.h>

int time[20], rec[20], num, goal;
int choose[20], now, count, max;

void recu( int n ){
     
     int i;
     
     if( n==num && now<=goal ){
         if( max < now ){
             max = now;
             count = 0;
             for( i=0; i<num; i++ )
                  if( choose[i] )
                      rec[count++] = time[i];
         }
     }
     else if( now<=goal ){
          choose[n] = 1;
          now += time[n];
          recu(n+1);
          choose[n] = 0;
          now -= time[n];
          recu(n+1);
     }
}

int main(){
    
    int i, l;
    
    while( scanf("%d", &goal)!=EOF ){
           scanf("%d", &num);
           for( i=0; i<num; i++ )
                scanf("%d", &time[i]);
           for( i=0; i<num; i++ )
                choose[i] = 0;
           now = 0;
           max = 0;
           recu(0);
           
           for( i=0; i<count; i++ )
                printf("%d ", rec[i]);
           printf("sum:%d\n", max);
    }
    
    return 0;
}
