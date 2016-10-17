/*
ID: j9010311
PROG: milk3
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct{
    int one;
    int two;
    int thr;
}BUK;

bool use[194461];
bool ans[21];
queue<BUK> que;

int main(){
    
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    
    int i, j, cal, cha;
    BUK tmp, now, com;
    
    while( scanf("%d", &com.one)!=EOF ){
        
        scanf("%d%d", &com.two, &com.thr);
        memset(use,0,sizeof(use));
        memset(ans,0,sizeof(ans));
        
        tmp.one = 0;
        tmp.two = 0;
        tmp.thr = com.thr;
        cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
        use[cal] = true;
        ans[tmp.thr] = true;
        
        que.push(tmp);
        while( !que.empty() ){
            
            now = que.front();
            que.pop();
            
            /* a pours to b and c */
            cha = min(com.two-now.two,now.one);
            tmp.two = now.two + cha;
            tmp.one = now.one - cha;
            tmp.thr = now.thr;
            cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
            if( !use[cal] ){
                use[cal] = true;
                que.push(tmp);
                if( !tmp.one )  ans[tmp.thr] = true;
            }
            
            cha = min(com.thr-now.thr,now.one);
            tmp.thr = now.thr + cha;
            tmp.one = now.one - cha;
            tmp.two = now.two;
            cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
            if( !use[cal] ){
                use[cal] = true;
                que.push(tmp);
                if( !tmp.one )  ans[tmp.thr] = true;
            }
            
            /* b pours to a and c */
            cha = min(com.one-now.one,now.two);
            tmp.one = now.one + cha;
            tmp.two = now.two - cha;
            tmp.thr = now.thr;
            cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
            if( !use[cal] ){
                use[cal] = true;
                que.push(tmp);
                if( !tmp.one )  ans[tmp.thr] = true;
            }
            
            cha = min(com.thr-now.thr,now.two);
            tmp.thr = now.thr + cha;
            tmp.two = now.two - cha;
            tmp.one = now.one;
            cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
            if( !use[cal] ){
                use[cal] = true;
                que.push(tmp);
                if( !tmp.one )  ans[tmp.thr] = true;
            }
            
            /* c pours to a and b */
            cha = min(com.one-now.one,now.thr);
            tmp.one = now.one + cha;
            tmp.thr = now.thr - cha;
            tmp.two = now.two;
            cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
            if( !use[cal] ){
                use[cal] = true;
                que.push(tmp);
                if( !tmp.one )  ans[tmp.thr] = true;
            }
            
            cha = min(com.two-now.two,now.thr);
            tmp.two = now.two + cha;
            tmp.thr = now.thr - cha;
            tmp.one = now.one;
            cal = 21*tmp.one + 441*tmp.two + 9261*tmp.thr;
            if( !use[cal] ){
                use[cal] = true;
                que.push(tmp);
                if( !tmp.one )  ans[tmp.thr] = true;
            }
        }
        
        for( j=20; j>=0; --j )
            if( ans[j] )
                break;
        
        for( i=0; i<j; ++i )
            if( ans[i] )
                printf("%d ", i);
        printf("%d\n", j);
        
    }
    
    return 0;
}
