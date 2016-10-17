/*
ID: j9010311
PROG: fact4
LANG: C++
*/

#include <cstdio>

using namespace std;

int main(){
    
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    
    int i, ans[4221];
    
    ans[1] = 1;
    for( i=2; i<4221; ++i ){
        ans[i] = ans[i-1]*i;
        while( !(ans[i]%10) )
            ans[i] /= 10;
        ans[i] %= 1000000;
    }
    
    while( scanf("%d", &i)!=EOF )
        printf("%d\n", ans[i]%10);
    
    return 0;
}
