/*
ID: j9010311
PROG: crypt1
LANG: C++
*/

#include <cstdio>

using namespace std;

int num, digit[10], a, b, ans;
bool use[10];

void backtrack( int in ){
    
    if( in==0 ){
        for( int i=0; i<num; ++i ){
            if( !digit[i] ) continue;
            a += (100*digit[i]);
            backtrack(1);
            a -= (100*digit[i]);
        }
    }
    else if( in==1 ){
        for( int i=0; i<num; ++i ){
            a += (10*digit[i]);
            backtrack(2);
            a -= (10*digit[i]);
        }
    }
    else if( in==2 ){
        for( int i=0; i<num; ++i ){
            a += (digit[i]);
            backtrack(3);
            a -= (digit[i]);
        }
    }
    else if( in==3 ){
        for( int i=0; i<num; ++i ){
            if( !digit[i] || a*digit[i]>999 ) continue;
            b += (10*digit[i]);
            backtrack(4);
            b -= (10*digit[i]);
        }
    }
    else if( in==4 ){
        for( int i=0; i<num; ++i ){
            if( a*digit[i]>999 ) continue;
            b += (digit[i]);
            if( a*b < 10000 )
                backtrack(5);
            b -= (digit[i]);
        }
    }
    else{
        int part1, part2, sum;
        part1 = a*(b%10);
        if( !use[part1/100] || !use[(part1%100)/10] || !use[part1%10] ) return ;
        part2 = a*(b/10);
        if( !use[part2/100] || !use[(part2%100)/10] || !use[part2%10] ) return ;
        
        sum = a*b;
        if( use[sum/1000] && use[(sum%1000)/100] && use[(sum%100)/10] && use[sum%10] ){
            ++ans;
            //printf("%d * %d = %d\n", a, b, sum);
        }
    }
    
}

int main(){
    
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    
    int i, j;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=0; i<10; ++i )
            use[i] = false;
        
        for( i=0; i<num; ++i ){
            scanf("%d", &digit[i]);
            use[digit[i]] = true;
        }
        
        ans = 0;
        a = 0;
        b = 0;
        backtrack(0);
        printf("%d\n", ans);
    }
    
    return 0;
}
