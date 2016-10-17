#include <stdio.h>
#include <string.h>

int main(){
    int sum[26]={0}, count, len, index, num, i;
    char in[101], tmp[5]={0};
    while( scanf("%s",in) ){
           len = strlen(in);
           if( len==1 && in[0]=='0' )
               break;
           count = len>>2;
           index = len - 1;
           for( i=0; i<count; i++ ){
                num = 3;
                for( index; num>=0; index-- )
                     tmp[num--] = in[index];
                sum[i] += atoi(tmp);
           }
           num = len%4 - 1;
           memset(tmp,'\0',4);
           for( index; index>=0; index-- )
                tmp[num--] = in[index];
           sum[i] += atoi(tmp);
    }
    for( i=25; !sum[i]; i-- );
    for( num=0; num<i; num++ ){
         sum[num+1] += sum[num]/10000;
         sum[num] %= 10000;
    }
    printf("%d",sum[i--]);
    for( i; i>=0; i-- ){
         if( sum[i]>999 )
             printf("%d", sum[i]);
         else if( sum[i]>99 )
              printf("0%d", sum[i]);
         else if( sum[i]>9 )
              printf("00%d", sum[i]);
         else
             printf("000%d", sum[i]);
    }
    /*printf("\n"); //you can't change the line after the answer
    while(1);*/
    return 0;
}
