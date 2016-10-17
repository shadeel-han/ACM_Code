#include <stdio.h>

int main(){
    
    int in, sum, cas;
    
    scanf("%d", &cas);
    while( cas-- ){
           scanf("%d", &in);
           sum = 0;
           while( in>=5 ){
                  in /= 5;
                  sum += in;
           }
           printf("%d\n", sum);
    }
    
    return 0;
}
