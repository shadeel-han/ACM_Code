#include <stdio.h>

int ok, in[5], use[5], num[5], sum;

void back2( int n ){
     
     if( n==9 ){
         if( sum==23 )
             ok--;
         return ;
     }
     if( ok ){
         int i=n-4;
         
          sum += num[i];
          back2(n+1);
          sum -= (num[i]<<1);
          back2(n+1);
          sum += num[i];
          sum *= num[i];
          back2(n+1);
          sum /= num[i];
     }
}


void back( int n ){
     
     if( ok && n==5 ){
         back2(n);
         return ;
     }
     if( ok ){
          int i;
          
          for( i=0; i<5; i++ )
               if( use[i] ){
                   use[i] = 0;
                   num[n] = in[i];
                   if( n==4 )
                       sum = num[0];
                   back(n+1);
                   use[i] = 1;
               }
     }
}

int main(){
    
    int i;
    
    while( scanf("%d %d %d %d %d", &in[0], &in[1], &in[2], &in[3], &in[4]) ){
           if( !in[0] )
               break;
           ok = 1;
           for( i=0; i<5; i++ )
                use[i] = 1;
           back(0);
           if( ok )
               puts("Impossible");
           else
               puts("Possible");
    }
    
    return 0;
}
