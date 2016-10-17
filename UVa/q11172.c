#include <stdio.h>

int main(){
    int i, j, count;
    scanf( "%d", &count );
    while( (count--)>0 ){
        scanf( "%d %d", &i, &j );
        if( i>j )
           printf(">\n");
        else if( i<j )
           printf("<\n");
        else
           printf("=\n");
    }
    return 0;
}
