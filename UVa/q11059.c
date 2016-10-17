#include <stdio.h>

int main(){
    int i, j, num, in, count=1, a[18];
    long long int pro, get;
    while( scanf("%d", &num)!=EOF ){
           get = 0;
           for( i=0; i<num; i++ )
              scanf("%d", &a[i]);
           for( i=0; i<num; i++ ){
              pro = 1;
              for( j=i; j<num; j++ ){
                  if( !a[j] )
                     break;
                  else if( a[j]!=1 ){
                     pro *= a[j];
                     if( pro > get )
                        get = pro;
                  }
              }
           }
           printf("Case #%d: The maximum product is %lld.\n\n", count++, get);
    }
    return 0;
}
