/*
ID: j9010311
PROG: ratios
LANG: C++
*/

#include <cstdio>

using namespace std;


int gcd( int a, int b ){
    
    if( !a && !b )  return 1;
    if( !a )        return b;
    if( !b )        return a;
    
    while( a%b && b%a ){
        if( a>b )   a %= b;
        else        b %= a;
    }
    if( a>b )   return b;
    else        return a;
}

int main(){
    
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    
    int i, j, k, sum, get, tmp, tmp2;
    int targ[3], give[3][3], total[3], ans[4];
    
    while( scanf("%d %d %d", &targ[0], &targ[1], &targ[2])!=EOF ){
        
        for( i=0; i<3; ++i )
            scanf("%d %d %d", &give[i][0], &give[i][1], &give[i][2]);
        
        tmp2 = gcd(targ[0],gcd(targ[1],targ[2]));
        targ[0] /= tmp2;
        targ[1] /= tmp2;
        targ[2] /= tmp2;
        
        get = 301;
        for( i=0; i<100; ++i )
            for( j=0; j<100; ++j )
                for( k=0; k<100; ++k ){
                    
                    sum = i + j + k;
                    if( sum >= get )    break;
                    total[0] = give[0][0]*i + give[1][0]*j + give[2][0]*k;
                    total[1] = give[0][1]*i + give[1][1]*j + give[2][1]*k;
                    total[2] = give[0][2]*i + give[1][2]*j + give[2][2]*k;
                    tmp = gcd(total[0],gcd(total[1],total[2]));
                    if( (targ[0]==(total[0]/tmp)) && (targ[1]==(total[1]/tmp)) && (targ[2]==(total[2]/tmp)) && (total[0]>=targ[0]*tmp2) ){
                        get = sum;
                        ans[0] = i;
                        ans[1] = j;
                        ans[2] = k;
                        if( targ[0] )       ans[3] = total[0]/(targ[0]*tmp2);
                        else if( targ[1] )  ans[3] = total[1]/(targ[1]*tmp2);
                        else                ans[3] = total[2]/(targ[2]*tmp2);
                    }
                    
                }
            
        if( get==301 )  puts("NONE");
        else            printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
        
    }
    
    return 0;
}
