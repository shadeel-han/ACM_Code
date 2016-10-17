#include <cstdio>

using namespace std;

int in[100000];

int main(){
    
    int i, j, k, num, part, up, down, now;
    
    while( scanf("%d %d", &num, &part)==2 ){
        
        for( i=0,down=0,up=1; i<num; ++i ){
            scanf("%d", &in[i]);
            if( down < in[i] )  down = in[i];
            up += in[i];
        }
        --down;

        while( up-down > 1 ){
            now = (up+down)>>1;
            for( i=0,k=0,j=1; i<num; ++i ){
                k += in[i];
                if( k > now ){
                    k = in[i];
                    ++j;
                }
                if( j > part )  break;
            }
            
            if( j>part )    down = now;
            else            up = now;
        }
        
        printf("%d\n", up);
    }
    
    return 0;
}
