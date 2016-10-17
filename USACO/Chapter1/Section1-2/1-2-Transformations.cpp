/*
ID: j9010311
PROG: transform
LANG: C++
*/

#include <cstdio>

using namespace std;

bool cmp( char trans[12][12], char target[12][12], int num ){
    
    bool same = true;
    for( int i=0; i<num && same; ++i )
        for( int j=0; j<num && same; ++j )
            if( trans[i][j] != target[i][j] )
                same = false;
    return same;
}

int main(){
    
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    
    char in[12][12], target[12][12], trans[12][12], com[12][12];
    int i, j, num;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%s",&in[i]);
        for( i=0; i<num; ++i )
            scanf("%s",&target[i]);
        
        /* rotate clockwise 90 degree */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                trans[j][num-1-i] = in[i][j];
        if( cmp(trans,target,num) ){
            puts("1");
            continue;
        }
        
        /* rotate clockwise 180 degree */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                trans[num-1-i][num-1-j] = in[i][j];
        if( cmp(trans,target,num) ){
            puts("2");
            continue;
        }
        
        /* rotate clockwise 270 degree */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                trans[num-1-j][i] = in[i][j];
        if( cmp(trans,target,num) ){
            puts("3");
            continue;
        }
        
        /* reflect */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                trans[i][num-1-j] = in[i][j];
        if( cmp(trans,target,num) ){
            puts("4");
            continue;
        }
        
        /* reflect and rotate */
        /* rotate clockwise 90 degree */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                com[j][num-1-i] = trans[i][j];
        if( cmp(com,target,num) ){
            puts("5");
            continue;
        }
        /* rotate clockwise 180 degree */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                com[num-1-i][num-1-j] = trans[i][j];
        if( cmp(com,target,num) ){
            puts("5");
            continue;
        }
        /* rotate clockwise 270 degree */
        for( i=0; i<num; ++i )
            for( j=0; j<num; ++j )
                com[num-1-j][i] = trans[i][j];
        if( cmp(com,target,num) ){
            puts("5");
            continue;
        }
        
        /* no change and others */
        if( cmp(in,target,num) )    puts("6");
        else                        puts("7");
        
    }
    
    return 0;
}
