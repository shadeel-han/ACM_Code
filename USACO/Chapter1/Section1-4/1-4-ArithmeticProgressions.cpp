/*
ID: j9010311
PROG: ariprog
LANG: C++
*/

#include <cstdio>
#include <cstring>

using namespace std;

int squ[251], start[15400];
bool besq[125001];

int main(){
    
    //freopen("ariprog.in","r",stdin);
    //freopen("ariprog.out","w",stdout);
    
    int i, j, k, m, n, len, limit, num, stop, up, half;
    
    /* build the square table */
    for( i=0; i<251; ++i ){
        j = i*i;
        squ[i] = j;
    }
    
    while( scanf("%d", &len)!=EOF ){
        
        scanf("%d", &limit);
        
        /* whether a number is bisquare */
        memset(besq,0,sizeof(besq));
        for( i=0; i<=limit; ++i )
            for( j=i; j<=limit; ++j )
                besq[squ[i]+squ[j]] = true;
        
        /* pick out bisquare numbers */
        m = limit*limit;
        for( i=0,j=0; i<=m; ++i )
            if( besq[i] )   start[j++] = i;
        start[j] = 1000000000;
        
        --len;
        stop = 2*limit*limit / len;
        half = len>>1;
        
        for( i=1,num=0; i<=stop; ++i ){
            
            up = 2*limit*limit - i*len;
            for( j=0; start[j]<=up; ++j ){  /* start only from bisquare numbers */
                
                /* check from beginning and end at the same time */
                for( k=0,m=start[j],n=m+len*i; k<half; ++k,m+=i,n-=i )
                    if( !besq[m] || !besq[n] )
                        break;
                
                if( k==half && besq[m] && besq[n] ){
                    ++num;
                    printf("%d %d\n", start[j], i);
                }
            }
        }
        
        if( !num )  puts("NONE");
        
    }
    
    return 0;
}
