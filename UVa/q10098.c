#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void perm(char list[], int at, int end)
{
    if( at==end )
         puts(list);
    else
    {
        int j, i, tmp;
        for( j=at; j<=end; j++ ){
             if( j>at && list[j]==list[j-1] )
                 continue;
             tmp = list[j];
             for( i=j-1; i>=at; i-- )
                  list[i+1] = list[i];
             list[at] = tmp;
             
             perm(list,at+1,end);
             
             for( i=at+1; i<=j; i++ )
                  list[i-1] = list[i];
             list[j] = tmp;
        }
    }
}

int cmp( const void* a, const void* b ){
     return (*(char*)a - *(char*)b);
}

int main(){
    int tol, len;
    char st[12];
    scanf("%d", &tol);
    getchar();
    while( tol-- ){
           gets(st);
           len = strlen(st);
           qsort(st,len,sizeof(char),cmp);
           perm(st,0,len-1);
           printf("\n");
    }
    return 0;
}
