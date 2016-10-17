/*
ID: j9010311
PROG: beads
LANG: C++
*/

#include <cstdio>

using namespace std;

char in[1060];

int main(){
    
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    
    int i, j, m, n, len, ans, left, right;
    char now;
    
    while( scanf("%d", &len)!=EOF ){
        
        getchar();
        gets(in);
        ans = 0;
        
        for( i=len,j=len<<1; i<j; ++i ){
            in[i] = in[i-len];
            in[i+len] = in[i];
        }
        
        for( i=len+1; i<j; ++i ){
            
            now = in[i-1];
            left = 1;
            n = i - len;
            for( m=i-2; m>=n; --m ){
                if( now=='w' ){
                    if( in[m]=='r' )        now = 'r';
                    else if( in[m]=='b' )   now = 'b';
                    ++left;
                }
                else if( now==in[m] || in[m]=='w' )   ++left;
                else                    break;
            }
            
            now = in[i];
            right = 1;
            n = i + len;
            for( m=i+1; m<n; ++m ){
                if( now=='w' ){
                    if( in[m]=='r' )        now = 'r';
                    else if( in[m]=='b' )   now = 'b';
                    ++right;
                }
                else if( now==in[m] || in[m]=='w' )   ++right;
                else                    break;
            }
            
            if( left + right > ans )
                ans = left + right;
            
        }
        
        if( ans >= len )
            printf("%d\n", len);
        else
            printf("%d\n", ans);
        
    }
    
    return 0;
}
