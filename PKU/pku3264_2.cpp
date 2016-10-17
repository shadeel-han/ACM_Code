#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int sparse[17][50001];
int small[17][50001];

int main(){
    
    int i, j, k, que, num, mid, tmp, start, end;
    
    while( scanf("%d %d", &num, &que)!=EOF ){
        
        // first row setting
        for( i=1; i<=num; ++i ){
            scanf("%d", &sparse[0][i]);
            small[0][i] = sparse[0][i];
        }
        
        // j is the needed row in the sparse table
        j = (int)(log((double)num) / log(2.0));
        for( i=1; i<=j; ++i ){
            mid = (int)pow(2.0,(double)(i-1));
            // tmp is the needed column in every row
            tmp = num - mid + 1;
            for( k=1; k<tmp; ++k )
                sparse[i][k] = max(sparse[i-1][k],sparse[i-1][k+mid]);
            for( k=1; k<tmp; ++k )
                small[i][k] = min(small[i-1][k],small[i-1][k+mid]);
        }
        
        // find the asking value between start~end
        for( i=0; i<que; ++i ){
            scanf("%d %d", &start, &end);
            mid=(int)(log((double)(end-start+1)) / log(2.0));
            tmp = end-(int)pow(2.0,(double)mid)+1;            
            printf("%d\n", max(sparse[mid][start],sparse[mid][tmp])-min(small[mid][start],small[mid][tmp]));
            
        }
        
    }    
    
    return 0;
}
