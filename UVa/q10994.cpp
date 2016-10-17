#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
    
    int i, j, a, b;
    long long int ans;
    
    while( scanf("%d %d", &a, &b) ){
        
        if( a < 0 ) break;
        
        ans = 0;
        while( b-a >= 10 ){
            while( a%10 ){
                ans += a%10;
                ++a;
            }
            while( b%10 ){
                ans += b%10;
                --b;
            }
            a /= 10;
            b /= 10;
            ans += ((long long int)(b-a))*45;
        }
        for( i=a; i<=b; ++i ){
            j = i;
            if( !(j%10) )
                j /= 10;
            ans += j%10;
        }
        cout << ans << endl;
    }
    
    return 0;
}
