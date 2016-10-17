#include <stdio.h>

int main(){
    
    int in1, in2, a, b, tmp;
    
    while( scanf("%d %d", &in1, &in2)!=EOF ){
           a = in1;  b = in2;
           tmp = a%b;
           while( tmp ){
                  a = b;
                  b = tmp;
                  tmp = a%b;
           }
           if( b==1 )
               printf("%10d%10d    Good Choice\n\n", in1, in2);
           else
               printf("%10d%10d    Bad Choice\n\n", in1, in2);
    }
    return 0;
}
