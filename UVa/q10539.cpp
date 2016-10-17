#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

char prime[1001000];
long long int prim[200000];

int main(){

    int i, num=0, cas, limit, cnt;
    long long int low, high, j;
    
    memset(prime,1,sizeof(prime));
    for( i=4; i<1001000; i+=2 )
         prime[i]--;
    for( i=3; i<1001000; i+=2 )
         for( j=i<<1; j<1001000; j+=i )
              if( prime[j] )
                  prime[j]--;
    
    for( i=2; i<1001000; i++ )
         if( prime[i] )
             prim[num++] = ((long long int)i);
    
    cin >> cas;
    while( cas-- ){
           cnt = 0;
           cin >> low >> high;
           limit = (int)sqrt(high);
           for( i=0; prim[i]<=limit; i++ ){
                j = prim[i]*prim[i];
                while( j<=high ){
                       if( j>=low )
                           cnt++;
                       j *= prim[i];
                }
           }
           cout << cnt <<endl;
    }
    return 0;
}
