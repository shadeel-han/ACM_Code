/*
ID: j9010311
PROG: friday
LANG: C++
*/

#include <cstdio>

using namespace std;

int dp[401][7] = {0};

int main(){
    
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    
    int date[12] = {31,31,28,31,30,31,30,31,31,30,31,30};  /*12.1.2.3..11 month*/
    int i, j, day=3, year=1899; /* 1899/12/13 is Wendesday */
    
    for( i=1; i<=400; ++i ){
        ++year;
        for( j=0; j<12; ++j ){
            
            if( j==2 ){
                if( year%400==0 )   ++day;
                else if( year%100==0 )  ;
                else if( year%4==0 ) ++day;
                else                    ;
            }
            else
                day += (date[j] % 7);
            
            day %= 7;
            ++dp[i][day];
            
        }
    }
    
    for( i=2; i<=400; ++i )
        for( j=0; j<7; ++j )
            dp[i][j] += dp[i-1][j];
    
    while( scanf("%d", &year)!=EOF ){
        printf("%d %d %d %d %d %d %d\n", dp[year][6], dp[year][0], dp[year][1], dp[year][2], dp[year][3], dp[year][4], dp[year][5]);
    }
    
    return 0;
}
