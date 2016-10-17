/*
ID: j9010311
PROG: zerosum
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

int in;
char op[10];

void backtrack( int index ){
    
    if( index==in ){
        int i, j, sum=0, tmp;
        for( i=0; i<in; i=j ){
            if( op[i]=='+' || op[i]=='-' ){
                tmp = 0;
                for( j=i+1; j<=in; ++j ){
                    tmp = tmp*10 + j;
                    if( op[j]!=' ' ){
                        if( op[i]=='+' )    sum += tmp;
                        else                sum -= tmp;
                        break;
                    }
                }
            }
        }
        if( !sum ){
            for( i=1; i<in; ++i )
            printf("%c%c", '0'+i,op[i]);
            printf("%d\n", in);
        }
    }
    else{
        op[index] = ' ';
        backtrack(index+1);
        op[index] = '+';
        backtrack(index+1);
        op[index] = '-';
        backtrack(index+1);
    }
}

int main(){
    
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    
    int i, j;
    op[0] = '+';
    while( scanf("%d", &in)!=EOF ){
        
        op[in] = '+';
        backtrack(1);
    }
    
    return 0;
}
