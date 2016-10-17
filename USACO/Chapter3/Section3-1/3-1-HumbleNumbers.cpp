/*
ID: j9010311
PROG: humble
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct NODE{
    int n;
    bool operator < (const NODE &k) const{
        if( n > k.n )   return true;
        else            return false;
    }
};

vector<int> prime;
priority_queue<NODE> que;

int main(){
    
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    
    int i, j, num, k;
    NODE tmp, now;
    
    while( scanf("%d %d", &num, &k)!=EOF ){
        
        prime.clear();
        for( i=0; i<num; ++i ){
            scanf("%d", &j);
            prime.push_back(j);
        }
        
        while( !que.empty() )
            que.pop();
        tmp.n = 1;
        que.push(tmp);
        now.n = 0;
        i = 1;
        while( k-- ){
            while( now.n==que.top().n ){
                que.pop();
                --i;
            }
            now = que.top();
            que.pop();
            for( j=0; j<num; ++j ){
                tmp.n = now.n*prime[j];
                //  size controll and overflow detection
                if( (i>2000000) || (tmp.n/prime[j]!=now.n) )   break;
                else {
                    ++i;
                    que.push(tmp);
                }
            }
        }
        while( now.n==que.top().n )
            que.pop();
        printf("%d\n", que.top().n);
    }
    
    return 0;
}
