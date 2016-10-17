/*
ID: j9010311
PROG: frac1
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    int up;
    int down;
    double val;
}REC;
REC rec[100000];

bool gcd(int a, int b){
    int c;
    while( a%b ){
        c = a;
        a = b;
        b = c%b;
    }
    if( b==1 )  return true;
    else        return false;
}

bool cmp( REC a, REC b ){
    if( a.val < b.val ) return true;
    else                return false;
}

int main(){
    
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    
    int i, j, num, count;
    
    rec[0].up = 0;
    rec[0].down = 1;
    while( scanf("%d", &num)!=EOF ){
        
        count = 1;
        /* store the number only when numerator and denominator are coprime */
        for( i=1; i<num; ++i )
            for( j=i+1; j<=num; ++j )
                if( gcd(j,i) ){
                    rec[count].up = i;
                    rec[count].down = j;
                    rec[count].val = (double)i/j;
                    ++count;
                }
        rec[count].up = 1;
        rec[count].down = 1;
        rec[count].val = 1.0;
        
        sort(rec,rec+count,cmp);
        
        for( i=0; i<=count; ++i )
            printf("%d/%d\n", rec[i].up,rec[i].down);
        
    }
    
    return 0;
}
