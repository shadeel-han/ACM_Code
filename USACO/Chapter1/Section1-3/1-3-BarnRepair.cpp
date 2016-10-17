/*
ID: j9010311
PROG: barn1
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp( int a, int b ){
    if( a <= b ) return false;
    else        return true;
}

int main(){
    
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    
    int i, j, start, end, use, stall;
    int cow[201], dif[200];
    
    while( scanf("%d %d %d", &use, &stall, &j)!=EOF ){
        
        for( i=0; i<j; ++i )
            scanf("%d", &cow[i]);
        
        if( use > j ){
            printf("%d\n", j);
            continue;
        }
        
        /* sort the cow */
        sort( cow, cow+j, cmp );    
        end = cow[0];
        start = cow[j-1];
        
        --j;
        for( i=0; i<j; ++i )
            dif[i] = cow[i] - cow[i+1] - 1;
        /* sort the diffecrence between cow */
        sort( dif, dif+j, cmp );
        
        /* we can use n board means we can abandon n-1 most unecessary difference */
        --use;
        for( i=0,stall=0; i<use ; ++i )
            stall += dif[i];
        
        printf("%d\n", end-start+1-stall);
        
    }
    
    return 0;
}
