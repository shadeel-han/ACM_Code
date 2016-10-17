#include <cstdio>
#include <cstring>

using namespace std;

long long int cell[1025][1025];
int lowbit[1025];
int maxsize;

long long int getsum ( int x, int y )
{
	long long int ans = 0;
	for( int i=x; i>0; i-=lowbit[i] )
       for( int j=y; j>0; j-=lowbit[j] )
	       ans += cell[i][j];
	return ans;
}

void change ( int x, int y, long long int data )
{
	for( int i=x; i<=maxsize; i+=lowbit[i] )
	    for( int j=y; j<=maxsize; j+=lowbit[j] )
	       cell[i][j] += data;
}

int main(){
    
    int in, from, to, val, i, j;
    
    for( i=1; i<1025; ++i )
        lowbit[i] = i&(-i);
    
    while( scanf("%d", &in)!=EOF ){
        
        memset(cell,0,sizeof(cell));
        scanf("%d", &maxsize);
        
        while( scanf("%d", &in) ){
            if( in==3 ) break;
            if( in==1 ){
                scanf("%d %d %d", &from, &to, &val);
                change(from+1,to+1,(long long int)val);
            }
            else if( in==2 ){
                scanf("%d %d %d %d", &from, &to, &i, &j);
                printf("%lld\n", getsum(i+1,j+1)-getsum(i+1,to)-getsum(from,j+1)+getsum(from,to));
            }
        }
        
    }
    return 0;
}
