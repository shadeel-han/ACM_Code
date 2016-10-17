#include <stdio.h>

int main(){
    int i, year;
    unsigned int f, mb, ma;
    
    while(scanf("%d", &year)){
       if( year==-1 )
           break;
       f=1;
       mb=0;
       ma=0;
      for( i=0; i<year; i++ ){
            ma = f + mb;
            f = mb+1;
            mb = ma;
       }
       printf("%u %u\n", ma, f+ma);
    }
    return 0;
}
