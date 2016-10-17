#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char buf[10001], out[10001];
    int num, i, j1, j2, k, count, countSq;
    
    scanf("%d", &num);
    getchar();
    for( i=0; i<num; i++ ){
         count = 0;
         gets(buf);
         count = strlen(buf);
         countSq = (int)sqrt(count);
         if( count != countSq*countSq){
             printf("INVALID\n");
             continue;
         }
         k = 0;
         for( j1=0; j1<countSq; j1++ )
              for( j2=j1; j2<count; j2+=countSq )
                   out[k++] = buf[j2];  
         printf("%s\n", out);
         memset(out, '\0', 10001);
    }
    return 0;
}

