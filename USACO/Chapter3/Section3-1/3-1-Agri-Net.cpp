/*
ID: j9010311
PROG: agrinet
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXX 151

struct EDGE{
    int from;
    int to;
    int len;
};

vector<EDGE> store;
int dis[MAXX][MAXX];
int p[MAXX], rank[MAXX];

int FindSet( int x )
{
    if(x!=p[x])
        p[x] = FindSet(p[x]);
    return p[x];
}

void Link( int x, int y )
{
    if(rank[x]>rank[y])
        p[y] = x;
    else
    {
        p[x] = y;
        if(rank[x]==rank[y])
            rank[y]++;
    }
}

void MakeSet( int x )
{
	p[x]    = x;
	rank[x] = 0;
} 

void Union(int x,int y)
{
    Link(FindSet(x),FindSet(y));
}

bool cmp( EDGE a, EDGE b ){
    if( a.len < b.len ) return true;
    else                return false;
    
}

int main(){
    
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    
    int i, j, num, ans;
    EDGE tmp;
    
    while( scanf("%d", &num)!=EOF ){
        
        store.clear();
        for( i=0; i<num; ++i ){
            MakeSet(i);
            tmp.from = i;
            for( j=0; j<num; ++j ){
                scanf("%d", &dis[i][j]);
                if( i < j ){
                    tmp.to = j;
                    tmp.len = dis[i][j];
                    store.push_back(tmp);
                }
            }
        }
        
        sort(store.begin(),store.end(),cmp);
        
        for( ans=0,i=0,j=store.size(); i<j; ++i )
            if( FindSet(store[i].from)!=FindSet(store[i].to) ){
                Union(store[i].from,store[i].to);
                ans += store[i].len;
            }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
