/*
ID: j9010311
PROG: shopping
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define INF 1000000000

struct ITEM{
    int number;
    int code[5];
    int num[5];
    int cost;
};

ITEM offer[100], canbe[105];
int dp[6][6][6][6][6], tol;

int backtrack( int one, int two, int three, int four, int five ){
    
    if( dp[one][two][three][four][five]>-1 )
        return dp[one][two][three][four][five];
    
    dp[one][two][three][four][five] = INF;
    for( int i=0; i<tol; ++i ){
        
        if( one-canbe[i].num[0]<0 )     continue;
        if( two-canbe[i].num[1]<0 )     continue;
        if( three-canbe[i].num[2]<0 )   continue;
        if( four-canbe[i].num[3]<0 )    continue;
        if( five-canbe[i].num[4]<0 )    continue;
        
        int val = backtrack(one-canbe[i].num[0],two-canbe[i].num[1],three-canbe[i].num[2],four-canbe[i].num[3],five-canbe[i].num[4]);
        if( dp[one][two][three][four][five] > val + canbe[i].cost )
            dp[one][two][three][four][five] = val + canbe[i].cost;
    }
    return dp[one][two][three][four][five];
}

int main(){
    
    freopen("shopping.in","r",stdin);
    freopen("shopping.out","w",stdout);
    
    int i, j, k, s, b, obc[5], tar[5];
    ITEM tmp;
    
    while( scanf("%d", &s)!=EOF ){
        
        for( i=0; i<s; ++i ){
            scanf("%d", &offer[i].number);
            for( j=0; j<offer[i].number; ++j )
                scanf("%d %d", &offer[i].code[j], &offer[i].num[j]);
            scanf("%d", &offer[i].cost);
        }
        
        memset(tar,0,sizeof(tar));
        scanf("%d", &b);
        for( i=0; i<b; ++i ){
            for( j=0; j<5; ++j )
                canbe[i].num[j] = 0;
            scanf("%d %d %d", &obc[i], &tar[i], &canbe[i].cost);
            canbe[i].num[i] = 1;
        }
        
        for( i=0,tol=b; i<s; ++i ){
            for( j=0; j<5; ++j )
                tmp.num[j] = 0;
            for( j=0; j<offer[i].number; ++j ){
                for( k=0; k<b; ++k )
                    if( obc[k]==offer[i].code[j] )
                        break;
                if( k<b )   tmp.num[k] = offer[i].num[j];
                else        break;
            }
            if( j==offer[i].number ){
                tmp.cost = offer[i].cost;
                canbe[tol] = tmp;
                ++tol;
            }
        }
        
        memset(dp,-1,sizeof(dp));
        dp[0][0][0][0][0] = 0;
        if( b>=1 )  dp[1][0][0][0][0] = canbe[0].cost;
        if( b>=2 )  dp[0][1][0][0][0] = canbe[1].cost;
        if( b>=3 )  dp[0][0][1][0][0] = canbe[2].cost;
        if( b>=4 )  dp[0][0][0][1][0] = canbe[3].cost;
        if( b>=5 )  dp[0][0][0][0][1] = canbe[4].cost;
        
        printf("%d\n", backtrack(tar[0],tar[1],tar[2],tar[3],tar[4]));
        
    }
    
    return 0;
}
