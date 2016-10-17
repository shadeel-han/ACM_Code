/*
ID: j9010311
PROG: dualpal
LANG: C++
*/

#include <cstdio>

using namespace std;

bool test( int rec[30], int len ){
    
    if( len==1 )    return true;
    
    bool pali = true;
    int i, j = len>>1, k = len-1;
    for( i=0; i<j; ++i )
        if( rec[i]!=rec[k-i] ){
            pali = false;
            break;
        }
    return pali;
}

int main(){
    
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    
    int i, j, k, base, start, num, count;
    char number[10]={'0','1','2','3','4','5','6','7','8','9'};
    int rec[30];
    
    while( scanf("%d %d", &num, &start)!=EOF ){
        
        for( i=0; i<30; ++i )
            rec[i] = 0;
        
        for( i=start+1; num; ++i ){
            for( base=2,count=2; base<=10 && count; ++base ){  /* count counts the palidrome time */
                k = 0;
                j = i;
                while( j ){
                    rec[k++] = number[j%base];
                    j /= base;
                }
                if( test(rec,k) )   --count;
            }
            
            if( !count ){   /* if dualpal */
                printf("%d\n", i);
                --num;
            }
            
        }
    }
    return 0;
}
