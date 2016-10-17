#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int cmp( const void* a, const void* b ){
     return (*(char*)a - *(char*)b);
}

int main(){
    int tol, len;
    char st[12];
    scanf("%d\n", &tol);
    //getchar();
    while( tol-- ){
           gets(st);
           len = strlen(st);
           qsort(st,len,sizeof(char),cmp);
            do{
                puts(st);
            }while(next_permutation(st,st+len));
           printf("\n");
    }
    return 0;
}
