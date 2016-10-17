#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
    int bright;
}DATA;
DATA input[10001];

typedef struct{
    int pos;
    int start;
    int tonum;
}COM;
COM comx[10002], comy[10001];

typedef struct{
    int start;
    int end;
    int maxx;
    int num;
}TREE;
TREE tree[32768];

int winx, winy, which;


void initial( int pos, int start, int end ){
    
    tree[pos].start = start;
    tree[pos].end = end;
    tree[pos].maxx = 0;
    tree[pos].num = 0;
    
    if( start==end )    return;
    
    int mid = (start+end)>>1;
    initial(2*pos,start,mid);
    initial(2*pos+1,mid+1,end);
    
}

int change( int pos, int front, int back, int flag ){
    
    if( front>tree[pos].end || back<tree[pos].start )   return tree[pos].maxx+tree[pos].num;
    
    if( front<=tree[pos].start && back>=tree[pos].end ){
        if( flag==1 )   tree[pos].num -= input[which].bright;
        else            tree[pos].num += input[which].bright;
        //printf("start:%d back:%d %d %d\n", front, back, tree[pos].maxx, tree[pos].num);
        return tree[pos].maxx+tree[pos].num;
    }
    
    int a, b;
    a = change(2*pos,front,back,flag);
    b = change(2*pos+1,front,back,flag);
    tree[pos].maxx = max(a,b);
    return tree[pos].maxx+tree[pos].num;
}

int cmp( const void* a, const void* b ){
    DATA* arg1 = (DATA*)a;
    DATA* arg2 = (DATA*)b;
    if( arg1->x > arg2->x )
        return 1;
    else
        return -1;
}

int main(){
    
    int i, j, k, m, num, index, mem, loc, ah, bh, ae, be, tmp, ans;
    map<int,int> dcrx, dcry;
    vector<int> putx, puty;
    
    while( scanf("%d %d %d", &num, &winx, &winy)!=EOF ){
        
        ans = 0;
        --winx;
        --winy;
        dcrx.clear();
        dcry.clear();
        putx.clear();
        puty.clear();
        
        for( i=0; i<num; ++i ){
            scanf("%d %d %d", &input[i].x, &input[i].y, &input[i].bright);
            putx.push_back(input[i].x);
            puty.push_back(input[i].y);
        }
        qsort(input,num,sizeof(DATA),cmp);
        sort( putx.begin(), putx.end() );
        sort( puty.begin(), puty.end() );
        
        /* discretization for x and y coordinate*/
        dcrx[putx[0]] = 1;
        comx[1].pos = putx[0];
        comx[1].start = 0;
        for( i=1,mem=putx[0],index=1; i<num; ++i ){
            if( mem!=putx[i] ){
                ++index;
                dcrx[putx[i]] = index;
                mem = putx[i];
                comx[index].pos = mem;
                comx[index].start = i;
            }
        }
        j = index;
        comx[j+1].start = num;
        
        dcry[puty[0]] = 1;
        comy[1].pos = puty[0];
        for( i=1,mem=puty[0],index=1; i<num; ++i ){
            if( mem!=puty[i] ){
                ++index;
                dcry[puty[i]] = index;
                mem = puty[i];
                comy[index].pos = mem;
            }
        }
        k = index;
        
        initial(1,1,k);
        ////////////////////////////////////////////
        
        for( i=0; i<num; ++i ){
            input[i].x = dcrx[input[i].x];
            input[i].y = dcry[input[i].y];
        }
        
        /* compute the scanline limit for discrete x and y */
        for( i=2,mem=comx[1].pos,loc=1; i<=j; ++i ){
            if( comx[i].pos-mem > winx ){
                comx[loc].tonum = --i;
                mem = comx[++loc].pos;
            }
        }
        for( i=loc; i<=j ;++i )
            comx[i].tonum = j;
        
        /*for( i=1; i<=j; ++i )
            printf("> %d %d\n", i, comx[i].tonum);*/
        
        for( i=2,mem=comy[1].pos,loc=1; i<=k; ++i ){
            if( comy[i].pos-mem > winy ){
                comy[loc].tonum = --i;
                mem = comy[++loc].pos;
            }
        }
        for( i=loc; i<=k ;++i )
            comy[i].tonum = k;
        /*for( i=1; i<=k; ++i )
            printf(">> %d %d %d\n", i, comy[i].pos, comy[i].tonum);*/
        /////////////////////////////////////////////////////
        
        for( i=1,ah=0,be=-1,ae=-1; i<=j; ++i ){
            
            tmp = comx[comx[i].tonum+1].start-1;
            if( be==tmp )   continue;
            else            be = tmp;
            
            bh = comx[i].start;
            for( k=ah; k<bh; ++k ){
                which = k;
                //printf("> %d from:%d to:%d\n", i, input[k].y,comy[input[k].y].tonum);
                change(1,input[k].y,comy[input[k].y].tonum,1);
            }
            ah = bh;
            
            for( k=ae+1; k<=be; ++k ){
                which = k;
                //printf(">> %d from:%d to:%d\n", i, input[k].y,comy[input[k].y].tonum);
                change(1,input[k].y,comy[input[k].y].tonum,2);
            }
            ae = be;
            
            if( tree[1].maxx+tree[1].num > ans ) ans = tree[1].maxx+tree[1].num;
            
        }
        
        printf("%d\n", ans);
        
    }
    
    return 0;
}
