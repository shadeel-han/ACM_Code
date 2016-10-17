/*
ID: j9010311
PROG: sort3
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    
    int i, j, num, ans, tmp;
    int number[4], in[1001], dis[4][4];
    
    number[0] = 0;
    while( scanf("%d", &num)!=EOF ){
        
        number[1] = 0;
        number[2] = 0;
        number[3] = 0;
        for( i=0; i<num; ++i ){
            scanf("%d", &in[i]);
            ++number[in[i]];
        }
        
        number[2] += number[1];
        number[3] += number[2];
        for( i=1; i<=3; ++i )
            for( j=1; j<=3; ++j )
                dis[i][j] = 0;
        /* make statistics for three kinds of numbers in three number areas */
        for( i=1; i<=3; ++i )
            for( j=number[i-1]; j<number[i]; ++j )
                ++dis[i][in[j]];
        
        ans = 0;
        /* exchange 2s in 1-area with 1s in 2-area */
        tmp = min(dis[1][2],dis[2][1]);
        ans += tmp;
        dis[1][2] -= tmp;
        dis[2][1] -= tmp;
        /* if there still exits 2s in 1-area, exchange 2s in 1-area with 1s in 3-area */
        if( dis[1][2] ){
            tmp = min(dis[1][2],dis[3][1]);
            ans += tmp;
            dis[1][2] -= tmp;
            dis[3][1] -= tmp;
            dis[3][2] += tmp;
        }
        
        /* exchange 3s in 1-area with 1s in 3-area */
        tmp = min(dis[1][3],dis[3][1]);
        ans += tmp;
        dis[1][3] -= tmp;
        dis[3][1] -= tmp;
        /* if there still exits 3s in 1-area, exchange 3s in 1-area with 1s in 2-area */
        if( dis[1][3] ){
            tmp = min(dis[1][3],dis[2][1]);
            ans += tmp;
            dis[1][3] -= tmp;
            dis[2][1] -= tmp;
            dis[2][3] += tmp;
        }
        /* finally there could only exist 2s in 3-area and 3s in 2-area */
        printf("%d\n", ans+dis[2][3]);
    }
    
    return 0;
}
