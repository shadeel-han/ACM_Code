/*
ID: j9010311
PROG: checker
LANG: C++
*/

#include <cstdio>

using namespace std;

int three, num, ans, odd, mid;
long long int board[13];
int pos[13];

void backtrack( int level ){
    
    if( level==num ){
        
        /* for odd num */
        if( num&1 && pos[0]==mid ) ++odd;
        else                       ++ans;
        if( three ){
            --three;
            printf("%d", pos[0]);
            for( int i=1; i<num; ++i )
                printf(" %d", pos[i]);
            putchar('\n');
        }
    }
    else{
        
        int i, j, stop;
        
        /* because of symmetry, only do half for first row */
        if( !level ){
            if( num==6 )    stop = num-1;
            else            stop = (num-1)/2;
        }
        else    stop = num-1;
        
        long long int com = 1LL, front, end, rec[13];
        for( i=0; i<=stop; ++i,com<<=1 ){
            
            /* check whether the position is puttable */
            if( board[level]&com )  continue;
            
            pos[level] = i+1;
            /* use binary to record the board status */
            for( j=level+1,front=(com<<1),end=(com>>1); j<num; ++j,front<<=1,end>>=1 ){
                rec[j] = board[j];
                board[j] |= ( front | com | end );
            }
            
            backtrack(level+1);
            
            /* when backtracking, recover from previous status */
            for( j=level+1; j<num; ++j )
                board[j] = rec[j];
        }
        
    }
    
}

int main(){
    
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    
    int i, j;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            board[i] = 0LL;
        
        ans = 0;
        /* for odd num */
        mid = (num>>1)+1;
        odd = 0;
        
        three = 3;
        backtrack(0);
        
        if( num==6 )    printf("%d\n", ans);
        else            printf("%d\n", (ans<<1)+odd);
        
    }
    
    return 0;
}
