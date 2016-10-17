#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
    int from;
    int to;
}RANGE;

RANGE range[100001], road[200001], base[100001];
/* for road, from means the road leads to the number, to means the next */
/* for base, from means the first road, to means the last road */
bool visit[100001];
int tree[100001], number, maxsize;


int lowbit( int in ){
    return in&(-in);
}

int getsum( int end )
{
	int ans = 0;
	for( int i=end; i>0; i-=lowbit(i) )
	   ans += tree[i];
	return ans;
}

void change (int end, int delta)
{
	for(int i=end; i<=maxsize; i+=lowbit(i))
		tree[i] += delta;
}

void create( int index ){
    
    int i, tmp;
    visit[index] = true;
    
    range[index].from = ++number;
    for( i=base[index].from; i; i=road[i].to )
        if( !visit[road[i].from] )
            create(road[i].from);
    range[index].to = number;
}


int main(){
    
    int i, j, num, from, to;
    char w;
    
    road[0].to = 0;
    while( scanf("%d", &num)!=EOF ){
        
        memset(base,0,num+1);
        number = 0;
        for( i=1; i<num; ++i ){
            scanf("%d %d", &from, &to);
            
            if( !base[from].from ){
                base[from].from = ++number;
                base[from].to = number;
                road[number].from = to;
                road[number].to = 0;
            }
            else{
                road[base[from].to].to = ++number;
                base[from].to = number;
                road[number].from = to;
                road[number].to = 0;
            }
            
            if( !base[to].from ){
                base[to].from = ++number;
                base[to].to = number;
                road[number].from = to;
                road[number].to = 0;
            }
            else{
                road[base[to].to].to = ++number;
                base[to].to = number;
                road[number].from = to;
                road[number].to = 0;
            }
        }
        
        memset(visit,false,num+1);
        
        number = 0;
        create(1);
        maxsize = num;
        memset(tree,0,4*(num+1));
        for( i=1; i<=num; ++i )
            change(range[i].from,1);
        
        scanf("%d", &num);
        
        for( i=0; i<num; ++i ){
            getchar();
            w = getchar();
            scanf("%d", &j);
            if( w=='C' ){
                if( visit[range[j].from] ){
                    visit[range[j].from] = false;
                    change(range[j].from,-1);
                }
                else{
                    visit[range[j].from] = true;
                    change(range[j].from,1);
                }
            }
            else
                printf("%d\n", getsum(range[j].to)-getsum(range[j].from-1));
        }
    }
    
    return 0;
}
