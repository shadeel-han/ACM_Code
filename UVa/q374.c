#include <stdio.h>
#include <math.h>
#define SQ(x) (x*x)

int bigmod(int a, int b, int c, int d)
{
    if( b==1 )
       return d;
    else if( !(b%2) )
        return SQ(bigmod(a,b>>1,c,d)%c)%c;
    else
        return (d*bigmod(a,b-1,c,d))%c;
}

int main(){
    int base, exp, mod, one;
    while( scanf("%d%d%d", &base, &exp, &mod)!=EOF ){
           if( exp ){
               one = base%mod;
               printf("%d\n", bigmod(base,exp,mod,one));
           }
           else
               printf("1\n");
    }
    return 0;
}
