/*
ID: j9010311
PROG: inflate
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct PRO{
    int po;
    int mi;
};

vector<PRO> choice;
int times[10001], score[10001];

int main(){
    
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    
    int i, j, num, limit;
    PRO tmp;
    
    while( scanf("%d %d", &limit, &num)!=EOF ){
        
        memset(score,0,sizeof(score));
        for( i=0; i<num; ++i ){
            scanf("%d %d", &tmp.po, &tmp.mi);
            if( score[tmp.mi] < tmp.po )
                score[tmp.mi] = tmp.po;
        }
        
        choice.clear();
        for( i=1,num=0; i<=limit; ++i )
            if( score[i] ){
                tmp.mi = i;
                tmp.po = score[i];
                choice.push_back(tmp);
                ++num;
            }
        
        memset(times,-1,sizeof(times));
        times[0] = 0;
        for( i=0; i<=limit; ++i )
            if( times[i]>-1 ){
                for( j=0; j<num; ++j ){
                    if( i + choice[j].mi > limit )  break;
                    if( times[i+choice[j].mi] < times[i] + choice[j].po )
                        times[i+choice[j].mi] = times[i] + choice[j].po;
                }
            }
        
        for( i=1,j=0; i<=limit; ++i )
            if( j < times[i] )
                j = times[i];
        
        printf("%d\n", j);
    }
    
    return 0;
}
