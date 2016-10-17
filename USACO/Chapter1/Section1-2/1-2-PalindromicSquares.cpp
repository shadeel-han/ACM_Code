/*
ID: j9010311
PROG: palsquare
LANG: C++
*/

#include <cstdio>

using namespace std;

bool test( char out[18], int len ){
    
    if( len==1 )    return true;
    
    bool pali = true;
    int i, j = len>>1, k = len-1;
    for( i=0; i<j; ++i )
        if( out[i]!=out[k-i] ){
            pali = false;
            break;
        }
    return pali;
}

int main(){
    
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    
    int i, j, k, base;
    char number[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
    char out[18], in[10], in2[10];
    
    while( scanf("%d", &base)!=EOF ){
        
        for( i=0; i<18; ++i )
            out[i] = 0;
        for( i=0; i<10; ++i ){
            in[i] = 0;
            in2[i] = 0;
        }
        
        for( i=1; i<=300; ++i ){
            
            k = 0;
            j = i*i;
            while( j ){  /* build the list in the indicating base */
                out[k++] = number[j%base];
                j /= base;
            }
            
            /* check whether it is palidrome */
            if( test(out,k) ){
                k = -1;
                j = i;
                while( j ){
                    in[++k] = number[j%base];
                    j /= base;
                }
                
                for( j=0; j<=k; ++j )
                    in2[k-j] = in[j];
                
                printf("%s %s\n", in2, out);
            }
            
        }
        
        
    }
    return 0;
}
