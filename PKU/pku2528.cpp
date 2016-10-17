#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef struct{
    int fro;
    int end;
}NODE;
NODE node[10001];

int tree[60000], left, right, total;
bool exist[10001];

void initial( int pos, int start, int end ){
    
    if( start==end ){
        tree[pos] = 0;
        return;
    }
    
    tree[pos] = 0;
    int mid = (start+end)>>1;
    initial(pos*2,start,mid);
    initial(pos*2+1,mid+1,end);
}

void setting( int pos, int start, int end, int num ){
    
    if( left>end || right<start )   return;
    
    if( left<=start && right>=end ){
        tree[pos] = num;
        return ;
    }
    
    if( tree[pos] ){
        tree[2*pos] = tree[pos];
        tree[2*pos+1] = tree[pos];
        tree[pos] = 0;
    }
    
    int mid = (start+end)>>1;
    setting( 2*pos,start,mid,num );
    setting( 2*pos+1,mid+1,end,num );
    
}

void traverse( int pos, int start, int end ){
    
    if( tree[pos] ){
        if( exist[tree[pos]] ){
            ++total;
            exist[tree[pos]] = false;
        }
        return;
    }
    
    int mid = (start+end)>>1;
    traverse(2*pos,start,mid);
    traverse(2*pos+1,mid+1,end);
    
}

int main(){
    
    int cas, i, num, tmp, index, mem; 
    vector<int> rec;
    map<int,int> number;
    
    scanf("%d", &cas);
    
    while( cas-- ){
        
        scanf("%d", &num);
        rec.clear();
        number.clear();
        for( i=0; i<num; ++i ){
            scanf("%d %d", &node[i].fro, &node[i].end);
            rec.push_back(node[i].fro);
            rec.push_back(node[i].end);
        }
        
        sort( rec.begin(), rec.end() );
        tmp = rec.size();
        index = 1;
        number[rec[0]] = index;
        for( i=1,mem=rec[0]; i<tmp; ++i ){
            if( mem!=rec[i] ){
                ++index;
                number[rec[i]] = index;
                mem = rec[i];
            }
        }
        
        initial(1,1,index);
        
        for( i=0; i<num; ++i ){
            left = number[node[i].fro];
            right = number[node[i].end];
            setting(1,1,index,i+1);
        }
        
        for( i=1,total=0; i<=num; ++i )
            exist[i] = true;
        traverse(1,1,index);
        
        printf("%d\n", total);
    }
    return 0;
}
