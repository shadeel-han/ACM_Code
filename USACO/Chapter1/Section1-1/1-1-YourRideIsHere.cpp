/*
ID: shadeel
PROG: ride
LANG: C++
*/


#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    
    char aa[10], bb[10];
    int i, lena, lenb, numa, numb;
    
    while( scanf("%s", aa)!=EOF ){
        scanf("%s", bb);
        lena = strlen(aa);
        lenb = strlen(bb);
        for( i=0,numa=1; i<lena; ++i )
            numa *= (aa[i]-'A'+1);
        for( i=0,numb=1; i<lenb; ++i )
            numb *= (bb[i]-'A'+1);
        
        if( numa%47 == numb%47 )    puts("GO");
        else                        puts("STAY");
        
    }
    return 0;
}
