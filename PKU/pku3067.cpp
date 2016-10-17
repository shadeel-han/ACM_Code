#include <cstdio>
#include <cstring>

using namespace std;

int s[1001], maxsize;
bool cnt[1001][1001];

int lowbit( int in ){
    return in&(-in);
}

int getsum( int end ){
	int sum = 0;
	while(end>0)
	{
		sum += s[end];
		end -= lowbit(end);
	}
	return sum;
}

void change( int end, int data )
{
	for(int i=end; i<=maxsize; i+=lowbit(i))
		s[i] += data;
}

int main(){
    
    int i, j, cas, c=0, west, east, num, from, to;
    long long int ans;
    
    scanf("%d", &cas);
    while( cas-- ){
        
        memset(s,0,sizeof(s));
        memset(cnt,0,sizeof(cnt));
        
        scanf("%d %d %d", &west, &east, &num);
        maxsize = east;
        
        for( i=0; i<num; ++i ){
            scanf("%d %d", &from, &to);
            cnt[from][to] = true;
            change(to,1);
        }
        
        for( i=1,ans=0; i<west; ++i )
            for( j=1; j<=east; ++j )
            if( cnt[i][j] ){
                ans += (long long int)getsum(j-1);
                change(j,-1);
            }
        printf("Test case %d: %lld\n", ++c, ans);
        
    }
    
    return 0;
}
