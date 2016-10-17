#include <stdio.h>
#include <string.h>

int main(){
    int num, index, length, wrong;
    char in[129], stack[129];
    
    scanf("%d", &num);
    getchar();
    while( num-- ){
           wrong = 0;
           index = 0;
           gets(in);
           length = strlen(in);
           while( length-- ){
                if( in[length]==')' || in[length]==']' )
                    stack[index++] = in[length];
                else{
                     if( --index<0 ){
                         wrong++;
                         break;
                     }
                     if(stack[index]==')' && in[length]=='(');
                     else if (stack[index]==']' && in[length]=='[');
                     else{
                          wrong++;
                          break;
                     }
                }
           }
           if( wrong || index )
               printf("No\n");
           else
               printf("Yes\n");
    }
    
    return 0;
}
