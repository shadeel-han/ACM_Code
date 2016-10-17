/*
ID: j9010311
PROG: pprime
LANG: C++
*/

#include <cstdio>
#include <cmath>

using namespace std;

int palin[1000], num=0;
int prime[1231], primenum=1;
bool isprime[5001]={0};

bool check( int in ){
    
    bool is = true;
    int i, sq = (int)sqrt(in);
    for( i=0; prime[i]<=sq; ++i )
        if( !(in%prime[i]) ){
            is = false;
            break;
        }
    return is;
}

int main(){
    
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    
    int i, j, m, n, cal, tmp, tmp2, tmp3;
    int out[4] = {1,3,7,9};
    
    /* produce prime within 10000 */
    prime[0] = 2;
    for( i=1; i<5001; i++ )
		 if(!isprime[i]){
		 	tmp = (i<<1) + 1;
			for( j=i+tmp; j<5001; j+=tmp )
				isprime[j] = true;
			prime[primenum++] = tmp;
		 }
    prime[primenum] = 10001;
    
    /* one digit */
    palin[num++] = 2;
    palin[num++] = 3;
    palin[num++] = 5;
    palin[num++] = 7;
    
    /* two digits */
    palin[num++] = 11;
    
    /* three digits */
    for( i=0; i<4; ++i ){
        cal = out[i]*101;
        for( j=0; j<10; ++j ){
            tmp = cal + 10*j;
            if( check(tmp) )
                palin[num++] = tmp;
        }
    }
    
    /* four digits */ 
    for( i=0; i<4; ++i ){
        cal = out[i]*1001;
        for( j=0; j<10; ++j ){
            tmp = cal + 110*j;
            if( check(tmp) )
                palin[num++] = tmp;
        }
    }
    
    /* five digits */
    for( i=0; i<4; ++i ){
        cal = out[i]*10001;
        for( j=0; j<10; ++j ){
            tmp = cal + 1010*j;
            for( m=0; m<10; ++m ){
                tmp2 = tmp + 100*m;
                if( check(tmp2) )
                    palin[num++] = tmp2;
            }
        }
    }
    
    /* six digits */
    for( i=0; i<4; ++i ){
        cal = out[i]*100001;
        for( j=0; j<10; ++j ){
            tmp = cal + 10010*j;
            for( m=0; m<10; ++m ){
                tmp2 = tmp + 1100*m;
                if( check(tmp2) )
                    palin[num++] = tmp2;
            }
        }
    }
    
    /* seven digits */
    for( i=0; i<4; ++i ){
        cal = out[i]*1000001;
        for( j=0; j<10; ++j ){
            tmp = cal + 100010*j;
            for( m=0; m<10; ++m ){
                tmp2 = tmp + 10100*m;
                for( n=0; n<10; ++n ){
                    tmp3 = tmp2 + 1000*n;
                    if( check(tmp3) )
                        palin[num++] = tmp3;
                }
            }
        }
    }
    
    /* eight digits */
    for( i=0; i<4; ++i ){
        cal = out[i]*10000001;
        for( j=0; j<10; ++j ){
            tmp = cal + 1000010*j;
            for( m=0; m<10; ++m ){
                tmp2 = tmp + 100100*m;
                for( n=0; n<10; ++n ){
                    tmp3 = tmp2 + 11000*n;
                    if( check(tmp3) )
                        palin[num++] = tmp3;
                }
            }
        }
    }
    
    /* put a terminal */
    palin[num] = 100000001;
    
    while( scanf("%d %d", &m, &n)!=EOF ){
        
        for( i=0; ; ++i )
            if( palin[i]>=m )
                break;
        
        for( ; palin[i]<=n ; ++i )
            printf("%d\n", palin[i]);
        
    }
    
    return 0;
}
