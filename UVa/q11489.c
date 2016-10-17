#include <stdio.h>
#include <string.h>

int main(){
    char in[1002];
    int tol, count, dinum[10], num[3], i, j, len, sum, tmp;
    scanf("%d", &tol);
    getchar();
    for( i=1; i<=tol; i++ ){
           gets(in);
           len = strlen(in);
           memset(dinum,0,sizeof(dinum));
           sum = 0;
           for( j=0; j<len; j++ ){
                tmp = in[j]-'0';
                sum += tmp;
                dinum[tmp]++;
           }
           num[0] = dinum[3] + dinum[6] + dinum[9];
           num[1] = dinum[1] + dinum[4] + dinum[7];
           num[2] = dinum[2] + dinum[5] + dinum[8];
           tmp = sum%3;
           if( tmp ){    /*sum is not multiple of 3*/
               if( !num[tmp] ){
                   printf("Case %d: T\n", i);
                   continue;
               }
               if( len!=1 && num[0]%2 )
                   printf("Case %d: T\n", i);
               else
                   printf("Case %d: S\n", i);
           }
           else{              /*sum is multiple of 3*/
               if( !num[0] || !(num[0]%2) )
                   printf("Case %d: T\n", i);
               else
                   printf("Case %d: S\n", i);
           }
    }
    return 0;
}
