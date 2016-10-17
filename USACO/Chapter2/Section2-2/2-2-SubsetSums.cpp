/*
ID: j9010311
PROG: subset
LANG: C++
*/

#include<cstdio>
#include<cstring>

using namespace std;

unsigned int ans[821], tmp[821];

int main(){
    
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    
    int i, j, in, total, half;
    
    while( scanf("%d", &in)!=EOF ){
        
        if( in==1 ){
            puts("0");
            continue;
        }
        total = (in+1)*in >> 1;
        if( total&1 ){
            puts("0");
            continue;
        }
        
        half = total>>1;
        
        memset(ans,0,sizeof(ans));
        for( i=1; i<=in; ++i ){
            memset(tmp,0,sizeof(tmp));
            ++tmp[i];
            for( j=1; j<=(half-i); ++j )
                if( ans[j] )    tmp[j+i] += ans[j];
            for( j=1; j<=half; ++j )
                ans[j] += tmp[j];
        }
        
        printf("%u\n", ans[half]>>1);
    }
    
    return 0;
}
