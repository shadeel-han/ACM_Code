/*
ID: j9010311
PROG: milk
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    int cost;
    int quan;
}FARM;
FARM farmer[5005];

bool cmp( FARM a, FARM b ){
    if( a.cost < b.cost )  return true;
    else                   return false;
}

int main(){
    
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    
    int i, j, amount, num, cost;
    
    while( scanf("%d %d", &amount, &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%d %d", &farmer[i].cost, &farmer[i].quan);
        
        sort( farmer, farmer+num, cmp );
        
        for( i=0,j=0,cost=0; j<amount; ++i ){
            j += farmer[i].quan;
            cost += (farmer[i].quan * farmer[i].cost);
        }
        
        /* if more than need, return the superfluous part */
        cost -= (farmer[i-1].cost * (j-amount));
        printf("%d\n", cost);
        
    }
    
    return 0;
}
