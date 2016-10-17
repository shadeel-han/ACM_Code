#include <stdio.h>
#include <string.h>

int main(){
    int start, end, tempsum, a, b, c, d, e, i, lock=0;
    int happy[100000]={0};
    memset(happy,-1,sizeof(int)*406);
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
    happy[203] = 4;
    happy[208] = 4;
    happy[219] = 4;
    happy[226] = 6;
    happy[230] = 4;
    happy[236] = 6;
    happy[239] = 6;
    happy[262] = 6;
    happy[263] = 6;
    happy[280] = 4;
    happy[291] = 4;
    happy[293] = 6;
    happy[301] = 3;
    happy[302] = 4;
    happy[310] = 3;
    happy[313] = 6;
    happy[319] = 6;
    happy[320] = 4;
    happy[326] = 6;
    happy[329] = 6;
    happy[331] = 6;
    happy[338] = 5;
    happy[356] = 7;
    happy[362] = 6;
    happy[365] = 7;
    happy[367] = 6;
    happy[368] = 6;
    happy[376] = 6;
    happy[379] = 7;
    happy[383] = 5;
    happy[386] = 6;
    happy[391] = 6;
    happy[392] = 6;
    happy[397] = 7;
    happy[404] = 5;

    while( scanf("%d %d", &start, &end)!=EOF ){
           if( lock )
               printf("\n");
           else
               lock = 1;
           for( i=start; i<=end; i++ ){
              if( !happy[i] ){  /*只有i>405時,happy[i]才有可能為0*/
                     a = i/10000;
                     b = (i%10000)/1000;
                     c = (i%1000)/100;
                     d = (i%100)/10;
                     e = i%10;
                     tempsum = a*a + b*b + c*c + d*d + e*e;
                     if( happy[tempsum]==-1 )
                             happy[i] = -1;
                     else{
                          happy[i] = happy[tempsum];
                          printf("%d %d\n", i, ++happy[i]);
                     }
                     continue;
              }
              if( happy[i]==-1 )
                 ;
              else
                   printf("%d %d\n", i, happy[i]);
         }
    }
    return 0;
}
