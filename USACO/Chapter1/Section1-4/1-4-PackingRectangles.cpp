/*
ID: j9010311
PROG: packrec
LANG: C++
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    int lenth;
    int width;
}REC;
REC rec[4], per[4];
int area;
bool use[4];
vector<REC> ans;

bool cmp( REC a, REC b ){
    
    if( a.width < b.width ) return true;
    else                    return false;
}

void answer( REC in, int ab ){
    
    if( ab < area ){
        area = ab;
        ans.clear();
        ans.push_back(in);
    }
    else if( ab==area )
        ans.push_back(in);
}

void layout( int n ){
    
    if( n==4 ){
        
        REC store;
        
        /* first condition */
        store.width = per[0].width + per[1].width + per[2].width + per[3].width;
        store.lenth = max(max(per[0].lenth,per[1].lenth),max(per[2].lenth,per[3].lenth));
        answer(store,store.width*store.lenth);
        
        /* second condition */
        store.width = max(per[0].lenth,per[1].width+per[2].width+per[3].width);
        store.lenth = per[0].width + max(per[1].lenth,max(per[2].lenth,per[3].lenth));;
        answer(store,store.width*store.lenth);
        
        /* third condition */
        store.width = max(per[0].lenth,per[1].width+per[2].width) + per[3].width;
        store.lenth = max(per[3].lenth,per[0].width+max(per[1].lenth,per[2].lenth));
        answer(store,store.width*store.lenth);
        
        /* forth condition */
        store.width = per[0].width + per[3].width + max(per[1].width,per[2].width);
        store.lenth = max(per[1].lenth+per[2].lenth,max(per[0].lenth,per[3].lenth));
        answer(store,store.width*store.lenth);
        
        /* fifth condition */
        store.width = per[2].width + per[3].width + max(per[0].width,per[1].width);
        store.lenth = max(per[0].lenth+per[1].lenth,max(per[2].lenth,per[3].lenth));
        answer(store,store.width*store.lenth);
        
        /* sixth condition */
        if( (per[1].width>per[0].width && per[0].lenth>per[2].lenth) || (per[1].width<=per[0].width && per[0].lenth<=per[2].lenth) ){
            store.width = max(per[0].width+per[2].width,per[1].width+per[3].width);
            store.lenth = max(per[0].lenth+per[1].lenth,per[2].lenth+per[3].lenth);
            answer(store,store.width*store.lenth);
        }
        
        
    }
    else{
        for( int i=0; i<4; ++i ){
            if( use[i] )    continue;
            use[i] = true;
            per[n] = rec[i];
            layout( n+1 );
            per[n].width = rec[i].lenth;  // exchange the width and lenth
            per[n].lenth = rec[i].width;
            layout( n+1 );
            use[i] = false;
        }
    }
    
}

int main(){
    
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    
    int i, j, k;
    
    while( scanf("%d %d", &rec[0].lenth, &rec[0].width)!=EOF ){
        
        scanf("%d %d", &rec[1].lenth, &rec[1].width);
        scanf("%d %d", &rec[2].lenth, &rec[2].width);
        scanf("%d %d", &rec[3].lenth, &rec[3].width);
        
        area = 1000000000;
        for( i=0; i<4; ++i )
            use[i] = false;
        layout(0);
        
        j = ans.size();
        for( i=0; i<j; ++i )
            if( ans[i].width > ans[i].lenth ){
                k = ans[i].width;
                ans[i].width = ans[i].lenth;
                ans[i].lenth = k;
            }
        
        sort( ans.begin(), ans.end(), cmp );
        for( i=0; i<ans. size(); ++i ){
            for( j=i+1; j<ans.size(); ++j )
                if( (ans[i].lenth==ans[j].lenth && ans[i].width==ans[j].width) || (ans[i].lenth==ans[j].width && ans[i].width==ans[j].lenth) ){
                    ans.erase( ans.begin()+j );
                    --j;
                }
        }
        
        printf("%d\n", area);
        for( i=0,j=ans.size(); i<j; ++i )
            printf("%d %d\n", ans[i].width, ans[i].lenth);
        
    }
    
    
    return 0;
}
