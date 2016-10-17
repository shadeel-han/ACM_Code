#include <cstdio>
#include <cstring>

using namespace std;
int s[32002], cnt[15000], cor[15000], maxsize;
int lowbit[32002];

int getsum (int end)
{
	int ans = 0;
	while(end>0)
	{
		ans += s[end];
		end -= lowbit[end];
	}
	return ans;
}

void change (int end, int delta)
{
	for(int i=end; i<=maxsize; i+=lowbit[i])
		s[i] += delta;
}


int main(){
    
    int i, j, num, x, y;
    
    for( i=1; i<32002; ++i )
        lowbit[i] = i&(-i);
    
    while( scanf("%d", &num)!=EOF ){
        
        memset(s,0,sizeof(s));
        memset(cnt,0,sizeof(cnt));
        
        for( i=0,y=-1; i<num; ++i ){
            scanf("%d %d", &cor[i], &j);
            ++cor[i];
            if( cor[i]>y )  y = cor[i];
        }
        
        maxsize = y;
        
        for( i=0; i<num; ++i ){
            ++cnt[getsum(cor[i])];
            change(cor[i],1);
        }
        
        for( i=0; i<num; ++i )
            printf("%d\n", cnt[i]);
        
    }
    
    return 0;
}
