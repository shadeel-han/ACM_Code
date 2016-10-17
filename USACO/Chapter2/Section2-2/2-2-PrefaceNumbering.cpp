/*
ID: j9010311
PROG: preface
LANG: C++
*/

#include <cstdio>

using namespace std;

int ans[3501][7]={0};

int main(){
    
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    
    int i, j, tmp, index;
    int val[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int inc[13][2]={{0},{0,1},{1},{0,2},{2},{2,3},{3},{2,4},{4},{4,5},{5},{4,6},{6}};
    
    for( i=1; i<=3500; ++i ){
        for( j=0; j<7; ++j )
            ans[i][j] = ans[i-1][j];
        tmp = i;
        index = 12;
        while( tmp ){
            if( tmp < val[index] )
                --index;
            else{
                tmp -= val[index];
                if( index&1 )   ++ans[i][inc[index][1]];
                ++ans[i][inc[index][0]];
            }
        }
    }
    
    while( scanf("%d", &tmp)!=EOF ){
        
        if( ans[tmp][0] )   printf("I %d\n", ans[tmp][0]);
        if( ans[tmp][1] )   printf("V %d\n", ans[tmp][1]);
        if( ans[tmp][2] )   printf("X %d\n", ans[tmp][2]);
        if( ans[tmp][3] )   printf("L %d\n", ans[tmp][3]);
        if( ans[tmp][4] )   printf("C %d\n", ans[tmp][4]);
        if( ans[tmp][5] )   printf("D %d\n", ans[tmp][5]);
        if( ans[tmp][6] )   printf("M %d\n", ans[tmp][6]);
    }
    
    return 0;
}
