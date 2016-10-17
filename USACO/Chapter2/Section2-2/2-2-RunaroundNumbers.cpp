/*
ID: j9010311
PROG: runround
LANG: C++
*/

// This problem is tricky. There is no runaround number with eight/nine digits.

#include<cstdio>
#include<cmath>

using namespace std;

bool used[10], pass[10];
int in[11], len, two, lent, digit[10];

bool recursive( int index ){
    
    if( (index==-1) && (two>in[0]) ){
        int i, j, index=0;
        i = lent;
        j = two;
        while( j ){
            --i;
            digit[i] = j%10;
            j /= 10;
        }
        
        for( i=0; i<10; ++i )   pass[i] = true;
        j = 0;
        while( pass[index] ){
            ++j;
            pass[index] = false;
            index = (index+digit[index])%lent;
        }
        if( j==lent && !index ) return true;
        else                    return false;
    }
    else{
        int i, j;
        for( i=1; i<10; ++i ){
            if( used[i] )   continue;
            
            j = i*(int)pow(10.0,index);
            two += j;
            if( two < in[index] ){
                two -= j;
                continue;
            }
            used[i] = true;
            if( recursive(index-1) )    return true;
            two -= j;
            used[i] = false;
        }
        return false;
    }
}

int main(){
    
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    
    int i, j, k;
    
    while( scanf("%d", &in[0])!=EOF ){
        
        len = 0;
        i = in[0];
        while( i ){
            ++len;
            i /= 10;
            j = len;
            k = i;
            while( j-- )    k *= 10;
            in[len] = k;
        }
        
        for( i=1; i<10; ++i )   used[i] = false;
        two = 0;
        for( i=len; ; ++i ){
            lent = i;
            if( recursive(i-1) )
                break;
        }
        
        printf("%d\n", two);
        
    }
    
    return 0;
}
