/*
ID: j9010311
PROG: contact
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct GET{
    int lenth;
    int times;
    int value;
};

vector<GET> keep;
int ans[13][4096];
char in[200002], tmpin[85];

bool cmp( GET a, GET b ){
    if( a.times > b.times )         return true;
    else if( a.times < b.times )    return false;
    else if( a.lenth < b.lenth )    return true;
    else if( a.lenth > b.lenth )    return false;
    else if( a.value < b.value )    return true;
    else                            return false;
}

int main(){
    
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    
    int i, j, k, down, up, n, len, a, val, cnt;
    GET tmp;
    char out[14];
    bool space;
    
    while( scanf("%d %d %d", &down, &up, &n)!=EOF ){
        
        len = 0;
        while( scanf("%s", tmpin)!=EOF ){
            j = strlen(tmpin);
            for( i=0; i<j; ++i )
                in[len+i] = tmpin[i];
            len += j;
        }
        
        memset(ans,0,sizeof(ans));
        for( i=0,a=len-up; i<=a; ++i ){
            for( j=1,val=0; j<=up; ++j ){
                val = (val<<1) + (int)(in[i+j-1]-'0');
                if( j>=down )   ++ans[j][val];
            }
        }
        
        for( i,a=len-down; i<=a; ++i ){
            for( j=1,val=0; ; ++j ){
                if( i+j-1==len )    break;
                val = (val<<1) + (int)(in[i+j-1]-'0');
                if( j>=down )   ++ans[j][val];
            }
        }
        
        keep.clear();
        a = 1<<up;
        for( i=down; i<=up; ++i )
            for( j=0; j<a; ++j )
                if( ans[i][j] ){
                    tmp.lenth = i;
                    tmp.times = ans[i][j];
                    tmp.value = j;
                    keep.push_back(tmp);
                }
        sort(keep.begin(),keep.end(),cmp);
        
        for( i=0,a=keep.size(); i<a && n; i=j,--n ){
            val = keep[i].times;
            printf("%d\n", val);
            space = true;
            for( j=i,cnt=0; keep[j].times==val && j<a; ++j,++cnt ){
                if( cnt==6 ){
                    putchar('\n');
                    space = true;
                    cnt = 0;
                }
                out[keep[j].lenth] = 0;
                for( k=keep[j].lenth-1; k>=0; --k,keep[j].value>>=1 )
                    if( keep[j].value&1 )   out[k]='1';
                    else                    out[k]='0';
                if( space ) space = false;
                else        putchar(' ');
                printf("%s", out);
            }
            putchar('\n');
        }
    }
    
    return 0;
}
