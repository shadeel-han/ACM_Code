#include <stdio.h>

int main(){
    
    int in, ans, i;
    
    while( scanf("%d",&in)!=EOF ){
        if( !in )
            break;
        if( in==1 ){
            puts("0");
            continue;
        }
        ans = in;
        for( i=2; i*i<=in; i++ ){
            if( !(in%i) ){
                ans -= ans/i;
                while( !(in%i) ){
                    in /= i;
                }
            }
        }
        /* n is prime itself */
        if( in!=1 ) 
             ans -= ans/in;
        printf("%d\n",ans);
    }
    
    return 0;
}
