/*
ID: j9010311
PROG: rect1
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct BOARD{
    int lw;
    int lh;
    int rw;
    int rh;
    int color;
};

struct ELE{
    int index;
    int w;
};

struct TREE{
    int left;
    int right;
    int col;
};

vector<BOARD> st;
vector<ELE> work, put;
TREE tree[200000];
bool on[1000];
int color[2501], width;

void segtree_initial( int index, int left, int right ){
    
    tree[index].left = left;
    tree[index].right = right;
    
    if( left != right ){
        int mid = (left+right)>>1, dou = index<<1;
        segtree_initial(dou,left,mid);
        segtree_initial(dou+1,mid+1,right);
    }
}

void coloring( int index, int left, int right, int col ){
    
    if( (left>tree[index].right) || (right<tree[index].left) )
        return ;
    
    if( (left<=tree[index].left) && (right>=tree[index].right) )
        tree[index].col = col;
    else{
        int dou=index<<1;
        if( tree[index].col ){
            tree[dou].col = tree[index].col;
            tree[dou+1].col = tree[index].col;
            tree[index].col = 0;
        }
        coloring(dou,left,right,col);
        coloring(dou+1,left,right,col);
    }
}

void counting( int index, int left, int right ){
    
    if( tree[index].col )
        color[tree[index].col] += ((right-left+1)*width);
    else{
        int mid=(left+right)>>1, dou=index<<1;
        counting(dou,left,mid);
        counting(dou+1,mid+1,right);
    }
}

bool cmp( ELE a, ELE b ){
    if( a.w < b.w )         return true;
    else                    return false;

}

bool cmp2( ELE a, ELE b ){
    if( a.index < b.index ) return true;
    else                    return false;
}

int main(){
    
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    
    int i, j, k, wid, hei, num, mem;
    BOARD tmp;
    ELE tmp2;
    
    while( scanf("%d %d %d", &wid, &hei, &num)!=EOF ){
        
        st.clear();
        /* base color */
        tmp.lw = 0;
        tmp.lh = 0;
        tmp.rw = wid;
        tmp.rh = hei;
        tmp.color = 1;
        st.push_back(tmp);
        ////////////////
        
        for( i=0; i<num; ++i ){
            scanf("%d %d %d %d %d", &tmp.lw, &tmp.lh, &tmp.rw, &tmp.rh, &tmp.color);
            st.push_back(tmp);
        }
        
        // if overlapping, delete
        for( i=0; i<st.size(); ++i ){
            for( j=i+1; j<st.size(); ++j )
                if( (st[i].lw>=st[j].lw) && (st[i].lh>=st[j].lh) && (st[i].rw<=st[j].rw) && (st[i].rh<=st[j].rh) )
                    break;
            if( j<st.size() ){
                st.erase(st.begin()+i);
                --i;
            }
        }
        
        // take out leftx and rightx of every coloring
        work.clear();
        for( i=0,j=st.size(); i<j; ++i ){
            tmp2.index = i;
            tmp2.w = st[i].lw;
            work.push_back(tmp2);
            tmp2.w = st[i].rw;
            work.push_back(tmp2);
        }
        
        // sort according to x coordinate
        sort(work.begin(),work.end(),cmp);
        
        // put one more coloring rightx for ending
        tmp2.w = wid;
        work.push_back(tmp2);
        
        put.clear();
        memset(on,0,sizeof(on));
        memset(color,0,sizeof(color));
        for( i=0,num=work.size()-1; i<num; i=j ){
            
            mem = work[i].w;
            for( j=i; work[j].w==mem && j<num; ++j ){
                if( !on[work[j].index] ){           // first time: turn on the coloring
                    on[work[j].index] = true;
                    put.push_back(work[j]);
                }
                else    on[work[j].index] = false;  // second time: turn off the coloring
            }
            // sort according to input order
            sort(put.begin(),put.end(),cmp2);
            
            // segment tree initialize
            segtree_initial(1,0,hei-1);
            
            // do coloring on segment tree
            for( k=0; k<put.size(); ++k )
                if( on[put[k].index] )
                    coloring(1,st[put[k].index].lh,st[put[k].index].rh-1,st[put[k].index].color);
                else{
                    put.erase(put.begin()+k);
                    --k;
                }
            
            // count the grid number of colors
            width = work[j].w - mem;
            counting(1,0,hei-1);
            
        }
        
        for( i=1; i<2501; ++i )
            if( color[i] )
                printf("%d %d\n", i, color[i]);
    }
    
    return 0;
}
