#include <stdio.h>
#include <stdlib.h>

int cmp( const void* a, const void* b ){

    return ((*(int*)a)-(*(int*)b));
}

int main(){
    
    int i, j, k, num, tmp;
    int in[5001], sum, cost;
    
    
    while( scanf("%d", &num) ){
           if( !num )
               break;
           for( i=0; i<num; i++ )
                scanf("%d", &in[i] );
           qsort(in,num,sizeof(int),cmp);
           cost = 0;
           tmp = num-1;
           for( i=0; i<tmp; i++ ){
                sum = in[i]+in[i+1];
                cost += sum;
                for( j=i+2; j<num; j++ )
                     if( sum<in[j] )
                         break;
                for( k=i+2; k<j; k++ )
                     in[k-1] = in[k];
                in[j-1] = sum;
           }
           printf("%d\n", cost);
    }
    return 0;
}
