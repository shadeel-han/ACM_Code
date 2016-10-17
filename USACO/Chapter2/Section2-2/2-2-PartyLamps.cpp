/*
ID: j9010311
PROG: lamps
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// one element records 20 lamps
struct REC{
    int lamp[5];
};
REC button[4], off, on;
vector<REC> keep, doing;
bool used[1048576];
int limit;

bool cmp( REC a, REC b ){
    
    int i, j, k;
    for( i=0; i<=limit; ++i ){        
        for( j=0,k=1; j<20; ++j,k<<=1 )
        if( (a.lamp[i]&k) != (b.lamp[i]&k) )
            break;
        if( j<20 )  break;
    }
    if( (a.lamp[i]&k) < (b.lamp[i]&k) ) return true;
    else                                return false;
}

int main(){
    
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    
    int i, j, k, m, n, times, num, hash;
    int prime[5] = {149,271,367,509,683};
    REC tmp, now;
    
    while( scanf("%d", &num)!=EOF ){
        
        limit = (num-1)/20;
        scanf("%d", &times);
        if( times >= 3 ){
            if( times&1 )   times = 3;
            else            times = 4;
        }
        
        for( i=0; i<5; ++i ){
            now.lamp[i] = 0;
            button[0].lamp[i] = 0;
            button[1].lamp[i] = 0;
            button[2].lamp[i] = 0;
            button[3].lamp[i] = 0;
            on.lamp[i] = 0;
            off.lamp[i] = 0;
        }
        for( i=1,k=-1; i<=num; ++i,j<<=1 ){
            if( i%20==1 )   ++k,j=1;
            now.lamp[k] |= j;
            button[0].lamp[k] |= j;
            if( i&1 )       button[1].lamp[k] |= j;
            else            button[2].lamp[k] |= j;
            if( i%3==1 )    button[3].lamp[k] |= j;
        }
        
        while( scanf("%d", &i) && i!=-1 ){
            --i;
            on.lamp[i/20] |= (1<<(i%20));
        }
        while( scanf("%d", &i) && i!=-1 ){
            --i;
            off.lamp[i/20] |= (1<<(i%20));
        }
        
        keep.clear();
        keep.push_back(now);
        while( times-- ){
            doing.clear();
            memset(used,0,sizeof(used));
            for( i=0,j=keep.size(); i<j; ++i ){
                now = keep[i];
                for( m=0; m<4; ++m ){
                    hash = 0;
                    for( n=0; n<=limit; ++n ){
                        tmp.lamp[n] = now.lamp[n]^button[m].lamp[n];
                        hash += tmp.lamp[n]*prime[n];
                    }
                    hash %= 1048576;
                    if( !used[hash] ){
                        used[hash] = true;
                        doing.push_back(tmp);
                    }
                }
            }
            keep = doing;
        }
        
        for( i=keep.size()-1; i>=0; --i ){
            for( j=0; j<=limit; ++j ){
                if( (keep[i].lamp[j]&on.lamp[j])!=on.lamp[j] )  break;
                if( keep[i].lamp[j]&off.lamp[j] )               break;
            }
            if( j<=limit )  keep.erase(keep.begin()+i);
        }
        
        if( !keep.size() )  puts("IMPOSSIBLE");
        else{
            sort(keep.begin(),keep.end(),cmp);
            for( i=0,j=keep.size(); i<j; ++i ){
                for( k=0,times=0; k<=limit; ++k )
                for( m=0,n=1; m<20&&times<num; ++m,n<<=1 ){
                    if( keep[i].lamp[k]&n )  putchar('1');
                    else                putchar('0');
                    ++times;
                } 
                putchar('\n');
            }
        }
        
    }
    
    return 0;
}
