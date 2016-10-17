#include <cstdio>
#include <cstring>
#include <vector>
#define INF 100000000

using namespace std;

typedef struct{
    int from;
    int to;
    int qua;
}NODE;

int maxx, minn;
vector<NODE> vec;
int dp[50002], num;
bool use[50002];

void bellford(){
    
    int i, j, limit=vec.size();
    bool change;
    
    for( i=minn; i<=maxx; ++i ) dp[i]=INF;
    
    for( i=minn; i<=maxx; ++i ){
        change = true;
        for( j=0; j<limit; ++j ){
            if( dp[vec[j].from] + vec[j].qua < dp[vec[j].to] ){
                dp[vec[j].to] = dp[vec[j].from] + vec[j].qua;
                change = false;
            }
        }
        if( change ) break;
    }
}

int main(){
    
    int i, j, from, to, qua;
    NODE in;
    
    while( scanf("%d", &num)!=EOF ){
        vec.clear();
        for( i=0, maxx=0, minn=50002; i<num; ++i ){
            scanf("%d %d %d", &from, &to, &qua);
            
            if( to > maxx )   maxx = to;
            if( from < minn ) minn = from;
            
            in.to = from;
            in.from = to+1;
            in.qua = -qua;
            vec.push_back(in);
            
        }
        ++maxx;
        
        for( i=minn; i<maxx; ++i ){
            in.from = i;
            in.to = i+1;
            in.qua = 1;
            vec.push_back(in);
        }
        
        for( i=maxx; i>minn; --i ){
            in.from = i;
            in.to = i-1;
            in.qua = 0;
            vec.push_back(in);
        }

        bellford();
        
        /*for( i=minn; i<=maxx; ++i )
            printf("%d %d\n", i, dp[i]);*/
        printf("%d\n", dp[maxx]-dp[minn]);
        
    }
    return 0;
}
