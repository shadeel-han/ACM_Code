#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct NODE{
    int index;
    int x;
    int y;
};
NODE st[100000];
int s[100002], ans[100000], maxsize;

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

void change( int end, int data ){
	for(int i=end; i<=maxsize; i+=lowbit(i))
		s[i] += data;
}

bool cmp( NODE a, NODE b ){
    if( a.y!=b.y ){
        if( a.y > b.y ) return true;
        else            return false;
    }
    else{
        if( a.x < b.x ) return true;
        else            return false;
    }
}

int main(){
    
    int i, j, num, forthx, forthy, cnt;
    
    while( scanf("%d", &num) ){
        
        if( !num )  break;
        
        for( i=0,maxsize=0; i<num; ++i ){
            scanf("%d %d", &st[i].x, &st[i].y);
            ++st[i].x;
            if( st[i].x>maxsize )   maxsize = st[i].x;
            st[i].index = i;
        }
        sort(st,st+num,cmp);
        
        memset(s,0,sizeof(s));
        for( i=0,forthx=-1,forthy=-1,cnt=0; i<num; ++i ){
            if( st[i].x==forthx && st[i].y==forthy )    ++cnt;
            else{
                forthx = st[i].x;
                forthy = st[i].y;
                cnt = 0;
            }
            ans[st[i].index] = getsum(st[i].x)-cnt;
            change(st[i].x,1);
        }
        
        printf("%d", ans[0]);
        for( i=1; i<num; ++i )
            printf(" %d", ans[i]);
        putchar('\n');
    }
    
    return 0;
}
