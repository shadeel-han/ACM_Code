/*
ID: j9010311
PROG: nocows
LANG: C++
*/

#include <cstdio>
#include <cmath>

using namespace std;
int level, ans;
int per[65][65], decom[65][18]={0};
int dp[200][100][65]={0};

int main(){
    
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    
    int i, j, k, m, n, p, q, num;
    int prime[18] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
    int cal[18];
    
    // prime decompose
    for( i=2; i<65; ++i ){
        j = i;
        k = 0;
        while( j!=1 ){
            if( j%prime[k]==0 ){
                ++decom[i][k];
                j /= prime[k];
            }
            else    ++k;
        }
    }
    
    // calculate permutation
    per[1][1] = 1;
    for( i=2; i<65; i+=2 ){
        
        per[i][i] = 1;
        for( j=0; j<18; ++j )   cal[j] = 0;
        
        for( j=1,n=i-1; j<=n; ++j,--n ){
            m = 1;
            for( k=0; k<18; ++k ){
                cal[k] += decom[n+1][k];
                cal[k] -= decom[j][k];
            }
            for( k=0; k<18; ++k )
                m = ( m * (int)(pow((double)prime[k],(double)cal[k])+0.00002)) % 9901;
            per[i][j] = m;
            per[i][n] = m;
        }
    }
    
    // Solution: dynamic programming
    dp[1][1][0] = 1;
    dp[3][2][0] = 1;
    dp[3][2][1] = 1;
    // node number
    for( i=5; i<200; i+=2 ){
        m = (i+1)>>1;
        if( i<8 )           n = 3;
        else if( i<16 )     n = 4;
        else if( i<32 )     n = 5;
        else if( i<64 )     n = 6;
        else if( i<128 )    n = 7;
        else                n = 8;
        // canbe level
        for( j=n; j<=m; ++j ){
            // put number in the level
            for( k=1; k<(i-1)/2; ++k ){
                for( p=(int)ceil(((double)k)/2),q=(i-1)-(k<<1); p<=q && p<65; ++p )
                if( dp[i-(k<<1)][j-1][p] )
                    dp[i][j][k] = (dp[i][j][k] + dp[i-(k<<1)][j-1][p]*per[p<<1][k])%9901;
                dp[i][j][0] = (dp[i][j][0]+dp[i][j][k])%9901;
            }
        }
    }
    
    while( scanf("%d %d", &num, &level)!=EOF ){
        
        if( !(num&1) ){
            puts("0");
            continue;
        }
        printf("%d\n", dp[num][level][0]%9901);
    }
    
    return 0;
}
