/*
ID: j9010311
PROG: sprime
LANG: C++
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int super[100], num=0;
int prime[1231], primenum=1;
bool isprime[5001]={0};
int put[4] = {1,3,7,9};

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

void produce( int level, int in ){
    
    /* at most eight digits */
    if( level==8 )      return;
    if( !check(in) )   return;
    super[num++] = in;
    
    /* if in is prime, try to add another odd number */
    for( int i=0; i<4; ++i )
        produce(level+1,in*10+put[i]);
}

int main(){
    
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    
    int i, j, tmp, bottom, top;
    
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
    
    /* the beginning of the answer of every number must be 2,3,5,7 */
    produce(0,2);
    produce(0,3);
    produce(0,5);
    produce(0,7);
    sort(super,super+num);
    super[num] = 100000001;
    
    while( scanf("%d", &tmp)!=EOF ){
        
        top = (int)pow(10.0,(double)tmp);
        bottom = top/10;
        
        for( i=0; ; ++i )
            if( super[i]>bottom )
                break;
        
        for( ; super[i]<top; ++i )
            printf("%d\n", super[i]);
        
    }
    
    return 0;
}
