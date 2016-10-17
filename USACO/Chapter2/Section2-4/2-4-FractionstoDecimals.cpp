/*
ID: j9010311
PROG: fracdec
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool used[100000];
int times[100000];
vector<int> digit, remain;

bool cmp( int a, int b ){
    if( times[a] < times[b] )   return true;
    else                        return false;
}

int main(){
    
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    
    int i, j, a, b, qu;
    
    while( scanf("%d %d", &a, &b)!=EOF ){
        
        memset(used,0,sizeof(used));
        memset(times,0,sizeof(times));
        
        qu = a / b;
        a = a - qu*b;
        if( !a ){
            printf("%d.0\n", qu);
            continue;
        }
        
        i = 0;
        while( !used[a] ){
            used[a] = true;
            times[a] = ++i;
            a *= 10;
            a = a - a/b*b;
        }
        
        digit.clear();
        remain.clear();
        if( !a ){
            for( i=1; i<100000; ++i )
                if( used[i] )
                    remain.push_back(i);
        }
        else{
            for( i=1,j=times[a]; i<100000; ++i )
                if( used[i] && times[i]>=j )
                    digit.push_back(i);
                else if( used[i] )
                    remain.push_back(i);
        }
        
        sort(digit.begin(),digit.end(),cmp);
        sort(remain.begin(),remain.end(),cmp);
        
        if( qu < 10 )           j = 2;
        else if( qu < 100 )     j = 3;
        else if( qu < 1000 )    j = 4;
        else if( qu < 10000 )   j = 5;
        else if( qu < 100000 )  j = 6;
        else                    j = 7;
        
        printf("%d.", qu);
        for( i=0,a=remain.size(); i<a; ++i,++j ){
            if( j==76 ){
                j = 0;
                putchar('\n');
            }
            printf("%d", remain[i]*10/b);
        }
        
        if( digit.size() ){
        if( j==76 ){
            putchar('\n');
            j = 1;
        }
        else    ++j;
        putchar('(');
        
        for( i=0,a=digit.size(); i<a; ++i,++j ){
            if( j==76 ){
                j = 0;
                putchar('\n');
            }
            printf("%d", digit[i]*10/b);
        }
        
        if( j==76 )
            putchar('\n');
        putchar(')');
        }
        
        putchar('\n');
    }
    
    return 0;
}
