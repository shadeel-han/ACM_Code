#include <stdio.h>
#include <stdlib.h>

int cmp( const void* a, const void* b ){
    return ((*(int*)a)-(*(int*)b));
}

int main(){
    
    int num, i, in[10000];
    
    while( scanf("%d", &num)!=EOF ){
           for( i=0; i<num; i++ )
                scanf("%d", &in[i]);
           qsort(in,num,sizeof(num),cmp);
           printf("%d\n", in[num>>1]);
    }
    return 0;
}
