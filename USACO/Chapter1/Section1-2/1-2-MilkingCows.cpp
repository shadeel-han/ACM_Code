/*
ID: j9010311
PROG: milk2
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    int start;
    int end;
}FARMER;
FARMER farmer[5002];

bool cmp( FARMER a, FARMER b ){
    
    if( a.start < b.start )         return true;
    else if( a.start > b.start )    return false;
    else{
        if( a.end <= b.end )    return true;
        else                    return false;
    }
}

int main(){
    
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    
    int i, num, con, no, tmp, start, end;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%d %d", &farmer[i].start, &farmer[i].end);
        
        sort( farmer, farmer+num, cmp );
        
        con = 0;
        no = 0;
        start = farmer[0].start;
        end = farmer[0].end;
        for( i=1; i<num; ++i ){
            
            if( farmer[i].start <= end ){
                end = max(end,farmer[i].end);
            }
            else{
                tmp = end - start;
                if( tmp > con ) con = tmp;
                start = farmer[i].start;
                tmp = start - end;
                if( tmp > no )  no = tmp;
                end = farmer[i].end;
            }
        }
        tmp = end - start;
        if( tmp > con ) con = tmp;
        printf("%d %d\n", con, no);
    }
    
    return 0;
}
