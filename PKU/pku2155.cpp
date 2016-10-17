#include <cstdio>
#include <cstring>

using namespace std;

int cell[1001][1001];
int lowbit[1001];
int maxsize;

int getsum ( int x, int y )
{
	int ans = 0;
	for( int i=x; i>0; i-=lowbit[i] )
       for( int j=y; j>0; j-=lowbit[j] )
	       ans += cell[i][j];
	return ans;
}

void change ( int x, int y, int data )
{
	for( int i=x; i<=maxsize; i+=lowbit[i] )
	    for( int j=y; j<=maxsize; j+=lowbit[j] )
	       cell[i][j] += data;
}

int main(){
    
    int i, cas, num, fromx, fromy, tox, toy, tmp, j, k;
    char w;
    bool ok = true;
    
    for( i=1; i<1001; ++i )
        lowbit[i] = i&(-i);
    
    scanf("%d", &cas);
    
    while( cas-- ){
        
        if( ok )    ok = false;
        else        putchar('\n');
        
        memset(cell,0,sizeof(cell));
        scanf("%d %d", &maxsize, &num);
        
        for( i=0; i<num; ++i ){
            
            getchar();
            w = getchar();
            
            if( w=='C' ){
                scanf("%d %d %d %d", &fromx, &fromy, &tox, &toy);
                change(fromx,fromy,1);
                change(fromx,toy+1,-1);
                change(tox+1,fromy,-1);
                change(tox+1,toy+1,1);               
            }
            else{
                scanf("%d %d", &fromx, &fromy);
                tmp = getsum(fromx,fromy);
                if( tmp&1 ) puts("1");
                else        puts("0");
            }
            
        }
        
    }
    return 0;
}
