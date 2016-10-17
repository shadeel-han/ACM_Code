#include <cstdio>
#include <vector>
#define INF 1000000000

using namespace std;

typedef struct{
    int from;
    int to;
    int qu;
}NODE;

vector<NODE> vec;
int dp[1001], ver, num;

bool bellford(){
    
    int i, j, limit=vec.size();
    bool change;
    
    for( i=1; i<=ver; ++i ) dp[i]=INF;
    dp[0] = 0;
    
    for( i=0; i<ver; ++i ){
        change = true;
        for( j=0; j<limit; ++j ){
            if( dp[vec[j].from] + vec[j].qu < dp[vec[j].to] ){
                dp[vec[j].to] = dp[vec[j].from] + vec[j].qu;
                change = false;
            }
        }
        if( change ) break;
    }
    
    for( j=0; j<limit; ++j ){
        if( dp[vec[j].from] + vec[j].qu < dp[vec[j].to] )
            return false;
    }
    return true;
}

int main(){
    
    int i, j, from, to, qua;
    char t;
    NODE in;
    
    while( scanf("%d %d", &ver, &num)!=EOF ){
        vec.clear();
        
        in.from = 0;
        in.qu = 0;
        for( i=1; i<=ver; ++i ){
            in.to = i;
            vec.push_back(in);
        }
        
        for( i=0; i<num; ++i ){
            getchar();
            t = getchar();
            if( t=='P' ){
                scanf("%d %d %d", &from, &to, &in.qu);
                
                in.from = from;
                in.to = to;
                vec.push_back(in);
                
                in.from = to;
                in.to = from;
                in.qu *= (-1);
                vec.push_back(in);
            }
            else{
                scanf("%d %d", &in.to, &in.from);
                in.qu = -1;
                vec.push_back(in);
            }
        }
        
        if( bellford() )
            puts("Reliable");
        else
            puts("Unreliable");
        
    }
    return 0;
}
