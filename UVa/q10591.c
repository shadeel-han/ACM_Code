#include <stdio.h>

int main(){
    int num, a, b, c, d, e, f, g, h, i, j;
    long long int test, temp;
    int happy[199]={0};
    happy[1] = 1;
    happy[7] = 6;
    happy[10] = 2;
    happy[13] = 3;
    happy[19] = 5;
    happy[23] = 4;
    happy[28] = 4;
    happy[31] = 3;
    happy[32] = 4;
    happy[44] = 5;
    happy[49] = 5;
    happy[68] = 3;
    happy[70] = 6;
    happy[79] = 4;
    happy[82] = 4;
    happy[86] = 3;
    happy[91] = 5;
    happy[94] = 5;
    happy[97] = 4;
    happy[100] = 2;
    happy[103] = 3;
    happy[109] = 5;
    happy[129] = 4;
    happy[130] = 3;
    happy[133] = 6;
    happy[139] = 6;
    happy[167] = 4;
    happy[176] = 4;
    happy[188] = 5;
    happy[190] = 5;
    happy[192] = 4;
    happy[193] = 6;
    
    scanf("%d", &num);
    for( j=1; j<=num; j++ ){
         scanf("%lld", &test);
         temp = test;
         if( test>729 ){
             a = test/100000000;
             b = (test%100000000)/10000000;
             c = (test%10000000)/1000000;
             d = (test%1000000)/100000;
             e = (test%100000)/10000;
             f = (test%10000)/1000;
             g = (test%1000)/100;
             h = (test%100)/10;
             i = test%10;
             temp = a*a + b*b + c*c + d*d + e*e + f*f + g*g + h*h + i*i;
         }
         if( temp>198 ){
             a = temp/100;
             b = (temp%100)/10;             
             c = temp%10;    
             temp = a*a + b*b + c*c;
         }
         if( !happy[temp] )
             printf("Case #%d: %lld is an Unhappy number.\n", j, test);
         else
             printf("Case #%d: %lld is a Happy number.\n", j, test);
    }
    return 0;
}
