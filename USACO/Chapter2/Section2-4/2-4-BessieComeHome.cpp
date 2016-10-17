/*
ID: j9010311
PROG: comehome
LANG: C++
*/

#include <cstdio>

using namespace std;

char tran( char in ){
    if( in>'Z' )    return (in-'a');
    else            return (in-'A'+26);
};

int dis[52][52];

int main(){
    
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    
    int i, j, k, num, from, to;
    char a, b;
    
    while( scanf("%d\n", &num)!=EOF ){
        
        for( i=0; i<52; ++i )
            for( j=0; j<52; ++j )
                dis[i][j] = 10000000;
        
        for( i=0; i<num; ++i ){
            scanf("%c %c %d\n", &a, &b, &j);
            from = tran(a);
            to = tran(b);
            if( from==to )  continue;
            if( dis[from][to] > j ){
                dis[from][to] = j;
                dis[to][from] = j;
            }
        }
        
        for( k=0; k<52; ++k )
        for( i=0; i<52; ++i )
        for( j=0; j<52; ++j )
            if( i!=j && j!=k ){
                if( dis[i][j] > dis[i][k] + dis[k][j] )
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        
        for( i=26,j=1000000; i<51; ++i )
            if( j > dis[i][51] ){
                j = dis[i][51];
                k = i;
            }
        
        printf("%c %d\n", 'A'+(k-26), j);
        
    }
    
    return 0;
}
