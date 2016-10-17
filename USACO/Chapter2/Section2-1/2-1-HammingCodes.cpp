/*
ID: j9010311
PROG: hamming
LANG: C++
*/

#include <cstdio>

using namespace std;

int ans[64], ansnum, limit, dif;

void search( int num ){
    
    if( num==ansnum )   return;
    else{
        int i, j;
        /* brute force search */
        for( i=ans[num-1]+1,j=0; j!=num; ++i )
            for( j=0; j<num; ++j ){
                int cmp = ans[j]^i, count=0;
                for( ; cmp; cmp>>=1 )
                    if( cmp&1 ) ++count;
                if( count < dif )
                    break;
            }
            
        ans[num] = i-1;
        search(num+1);
    }
    
}

int main(){
    
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    
    int i, j;
    
    ans[0] = 0;
    while( scanf("%d %d %d", &ansnum, &limit, &dif)!=EOF ){
        
        limit = 1<<limit;
        search(1);
        
        for( i=0,j=1; i<ansnum; ++i,++j ){
            if( i==ansnum-1 )   printf("%d\n", ans[i]);
            else if( j==10 ){
                j = 0;
                printf("%d\n", ans[i]);
            }
            else    printf("%d ", ans[i]);
        }
        
    }
    
    return 0;
}
