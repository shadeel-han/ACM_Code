#include <stdio.h>
#include <string.h>

int main(){
    char in[6000000], *z, digit[10]={'0','1','2','3','4','5','6','7','8','9'}, first, second;
    int num, age[100]={0}, i;
    
    while(scanf("%d", &num)){
       if( !num )
           break;
       getchar();
       gets(in);
       for( z=strtok(in," "); z; z=strtok(NULL," "))
          age[atoi(z)]++;
       memset(in,'\0',6000000);
       num = 0;
       for( i=1; i<10; i++ )
            if( age[i] ){
                first = digit[i%10];
                do{
                      in[num++] = first;
                      in[num++] = ' ';
                }while( --age[i] );
            }
       for( i ; i<100; i++ )
            if( age[i] ){
                first = digit[i%10];
                second = digit[i/10];
                do{
                       in[num++] = second;
                       in[num++] = first;
                       in[num++] = ' ';
                }while( --age[i] );
            }
       in[num-1] = '\0';
       puts(in);
    }
    return 0;
}
