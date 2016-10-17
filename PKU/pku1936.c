#include <stdio.h>
#include <string.h>

int main(){
    int i, j, sublen, stlen;
    char sub[100001], st[100001];
    while( scanf("%s %s", sub, st)!=EOF ){
           sublen = strlen(sub);
           stlen = strlen(st);
           for( i=0,j=0; i<sublen && j<stlen; j++ )
                if( sub[i]==st[j] )
                    i++;
           if( i==sublen )
               puts("Yes");
           else
               puts("No");
    }
    return 0;
}
