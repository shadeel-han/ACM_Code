/*
ID: j9010311
PROG: game1
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

int dp[2][101][102], data[101];

int backtrack( int who, int front, int end ){
    
    if( dp[who][front][end]>-1 )
        return dp[who][front][end];
        
    int next = (who==0)?(1):(0);
    if( backtrack(next,front+1,end)+data[front+1] > backtrack(next,front,end-1)+data[end-1] ){
        dp[next][front][end] = dp[next][front+1][end] + data[front+1];
        dp[who][front][end] = dp[who][front+1][end];
    }
    else{
        dp[next][front][end] = dp[next][front][end-1] + data[end-1];
        dp[who][front][end] = dp[who][front][end-1];
    }
    return dp[who][front][end];
}

int main(){
    
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    
    int i, num;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=1; i<=num; ++i )
            scanf("%d", &data[i]);
        
        memset(dp,-1,sizeof(dp));
        for( i=0; i<101; ++i ){
            dp[0][i][i+1] = 0;
            dp[1][i][i+1] = 0;
        }
        backtrack(1,0,num+1);
        printf("%d %d\n", dp[0][0][num+1], dp[1][0][num+1]);
        
    }
    
    return 0;
}
