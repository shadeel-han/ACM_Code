/*
ID: j9010311
PROG: holstein
LANG: C++
*/

#include <cstdio>

using namespace std;

int need[25], neednum, now[25];
int scoop[15][25], sconum, used[15];
int ans[15], minn;

void backtrack( int n, int use ){
    
    if( n==sconum ){
        int i, j;
        for( i=0; i<neednum; ++i )
            if( now[i]<need[i] )    break;
        if( i==neednum && use<minn ){
            minn = use;
            for( i=0,j=0; j<minn; ++i )
                if( used[i] )   ans[j++] = i;
        }
    }
    else if( use<minn ){
        for( int i=0; i<neednum; ++i )
            now[i] += scoop[n][i];
        used[n] = true;
        backtrack( n+1, use+1 );
        for( int i=0; i<neednum; ++i )
            now[i] -= scoop[n][i];
        used[n] = false;
        backtrack( n+1, use );
    }
}

int main(){
    
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    
    int i, j, num;
    
    while( scanf("%d", &neednum)!=EOF ){
        
        for( i=0; i<neednum; ++i ){
            scanf("%d", &need[i]);
            now[i] = 0;
        }
        scanf("%d", &sconum);
        for( i=0; i<sconum; ++i )
            for( j=0; j<neednum; ++j )
                scanf("%d", &scoop[i][j]);
        minn = sconum+1;
        
        backtrack(0,0);
        
        printf("%d", minn);
        for( i=0; i<minn; ++i )
            printf(" %d", ans[i]+1);
        putchar('\n');
    }
    
    return 0;
}
