#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int cas, i, j, k, m, num, count, tol;
    char in[202], out[3002], cnt[6];
    
    scanf("%d", &cas);
    getchar();
    for( k=1; k<=cas; k++ ){
           memset(out,'\0',sizeof(out));
           gets(in);
           num = strlen(in);
           tol = 0;
           for( i=0; i<num; i=j ){
                for( m=0; m<6; m++ )
                     cnt[m] = '\0';
                for( count=0,j=i+1; j<num; j++,count++ ){
                     if( !isdigit(in[j]) )
                         break;
                     cnt[count] = in[j];
                }
                count = atoi(cnt);
                for( m=0; m<count; m++ )
                     out[tol++] = in[i];
           }
           printf("Case %d: %s\n", k, out);
    }
    return 0;
}
