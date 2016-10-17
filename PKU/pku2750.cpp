#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct{
    int sum;
    int maxx;
    int lmax;  /* the maximun sum from the left */
    int rmax;  /* the maximun sum from the right */
    int minn;
    int lmin;  /* the minimum sum from the left */
    int rmin;  /* the minimum sum from the right */
}TREE;

TREE tree[262150];
int flower[100001];

TREE initial( int pos, int start, int end ){
    
    if( start==end ){
        int tmp = flower[start];
        tree[pos].maxx = tmp;
        tree[pos].minn = tmp;
        tree[pos].sum = tmp;
        tree[pos].lmax = tmp;
        tree[pos].rmax = tmp;
        tree[pos].lmin = tmp;
        tree[pos].rmin = tmp;
        return tree[pos];
    }
    
    int mid=(start+end)>>1;
    TREE tmp1, tmp2, tmp3;
    tmp1 = initial(2*pos,start,mid);
    tmp2 = initial(2*pos+1,mid+1,end);
    
    tmp3.sum = tmp1.sum + tmp2.sum;
    tmp3.lmax = max(tmp1.lmax,tmp1.sum+tmp2.lmax);
    tmp3.rmax = max(tmp2.rmax,tmp2.sum+tmp1.rmax);
    tmp3.maxx = max((tmp1.rmax+tmp2.lmax),max(tmp1.maxx,tmp2.maxx));
    
    tmp3.lmin = min(tmp1.lmin,tmp1.sum+tmp2.lmin);
    tmp3.rmin = min(tmp2.rmin,tmp2.sum+tmp1.rmin);
    tmp3.minn = min((tmp1.rmin+tmp2.lmin),min(tmp1.minn,tmp2.minn));
    
    tree[pos] = tmp3;
    
    //printf("pos:%d  sum:%d  lmax:%d  rmax:%d  max:%d  lend:%d  rend:%d\n", pos, tmp3.sum, tmp3.lmax, tmp3.rmax, tmp3.maxx, tmp3.lend, tmp3.rend);
    
    return tmp3;
}

TREE change( int pos, int start, int end, int target ){
    
    if( target<start || target>end )    return tree[pos];
    
    if( start==end ){
        int tmp = flower[target];
        tree[pos].maxx = tmp;
        tree[pos].minn = tmp;
        tree[pos].sum = tmp;
        tree[pos].lmax = tmp;
        tree[pos].rmax = tmp;
        tree[pos].lmin = tmp;
        tree[pos].rmin = tmp;
        return tree[pos];
    }
    
    int mid=(start+end)>>1;
    TREE tmp1, tmp2, tmp3;
    tmp1 = change(2*pos,start,mid,target);
    tmp2 = change(2*pos+1,mid+1,end,target);
    
    tmp3.sum = tmp1.sum + tmp2.sum;
    tmp3.lmax = max(tmp1.lmax,tmp1.sum+tmp2.lmax);
    tmp3.rmax = max(tmp2.rmax,tmp2.sum+tmp1.rmax);
    tmp3.maxx = max((tmp1.rmax+tmp2.lmax),max(tmp1.maxx,tmp2.maxx));
    
    tmp3.lmin = min(tmp1.lmin,tmp1.sum+tmp2.lmin);
    tmp3.rmin = min(tmp2.rmin,tmp2.sum+tmp1.rmin);
    tmp3.minn = min((tmp1.rmin+tmp2.lmin),min(tmp1.minn,tmp2.minn));
    
    tree[pos] = tmp3;
    
    //printf("pos:%d  sum:%d  lmax:%d  rmax:%d  max:%d  lend:%d  rend:%d\n", pos, tmp3.sum, tmp3.lmax, tmp3.rmax, tmp3.maxx, tmp3.lend, tmp3.rend);
    
    return tmp3;
}


int main(){
    
    int i, j, k, que, target, thing, num, maxx;
    TREE tmp;
    
    while( scanf("%d", &num)!=EOF ){
        
        for( i=1; i<=num; ++i )
            scanf("%d", &flower[i]);
        
        initial(1,1,num);
        
        scanf("%d", &que);
        while( que-- ){
            scanf("%d %d", &target, &thing);
            flower[target] = thing;
            tmp = change(1,1,num,target);
            
            if( tmp.sum==tmp.maxx ) /* when sum==maxx, tmp.minn represents the smallest flower */
                printf("%d\n", tmp.sum-tmp.minn);
            else                    /* otherwise, tmp.minn represents the smallest summation of a segment of flowers */
                printf("%d\n", max(tmp.maxx,tmp.sum-tmp.minn));
        }
    }
    
    return 0;
}
