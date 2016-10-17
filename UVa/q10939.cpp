#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define TREESIZE 5001
#define ANTSIZE 1001

struct EDGE{    // for edge: front,end; for pool: num,next; for move: ant,pos
	int num, next;
	EDGE() {};
	EDGE(int x, int y):num(x),next(y) {};
} pool[TREESIZE*2], edge[TREESIZE];
int PoolIndex, AntOnTree[TREESIZE], parent[TREESIZE], MinDis[TREESIZE];
int AntPos[ANTSIZE], cnt[ANTSIZE];
vector<EDGE> move;

void EdgeInput(int n){
	memset(edge, 0, sizeof(edge));
	memset(pool, 0, sizeof(pool));  PoolIndex = 0;
	for(int i=1; i<n; ++i){ // n-1 edge
		int from, to;   scanf("%d %d", &from, &to);
		// one direction
		if( !edge[from].num )	edge[from].num = ++PoolIndex;
		else					pool[edge[from].next].next = ++PoolIndex;
		edge[from].next = PoolIndex;
		pool[PoolIndex].num = to;
		// the other
		if( !edge[to].num )	edge[to].num = ++PoolIndex;
		else				pool[edge[to].next].next = ++PoolIndex;
		edge[to].next = PoolIndex;
		pool[PoolIndex].num = from;
	}
}

void AntInput(int k){
    memset(cnt, 0, sizeof(cnt));
    memset(AntOnTree, 0, sizeof(AntOnTree));
	for(int i=1; i<=k; ++i){
		int p;	scanf("%d", &p);
		AntOnTree[p] = i;
		AntPos[i] = p;
	}
}

int BuildParent(int x, int px){		// node index, parent
	parent[x] = px;
	if( AntOnTree[x] ){
        move.push_back(EDGE(AntOnTree[x],x));
		return MinDis[x] = 0;
	}
	
	int mindis = TREESIZE;
	for(int i=edge[x].num; i; i=pool[i].next)
	if( !parent[pool[i].num] ){
		int md = BuildParent(pool[i].num,x) + 1;
		if( mindis > md )   mindis = md;
	}
	return MinDis[x] = mindis;
}

void UpdateMindis(int x, int px){
	if( MinDis[x] > MinDis[px] )	MinDis[x] = MinDis[px];
    for(int i=edge[x].num; i; i=pool[i].next)
	if( pool[i].num!=px && MinDis[pool[i].num] < TREESIZE ){
        UpdateMindis(pool[i].num, x);
    }
}

int MoveDestination(int x, int n){ // node, step
	if( !n || AntOnTree[parent[x]] || MinDis[parent[x]]!=MinDis[x]+1 ){
        MinDis[x] = TREESIZE;   return x;
	}else{
        MinDis[x] = TREESIZE;   return MoveDestination(parent[x],n-1);
	}
}

int AntSort(EDGE a, EDGE b){
	return a.num < b.num;
}

void LadybugCome(void){
	int pos;    scanf("%d", &pos);
	memset(parent, 0, sizeof(parent));	move.clear();
	int shortest = BuildParent(pos,pos);
	UpdateMindis(pos,pos);
	sort(move.begin(), move.end(), AntSort);    // smaller index moves first
	for(int i=0,j=move.size(); i<j; ++i){
		int to = MoveDestination(move[i].next,shortest);
        if( to!=move[i].next ){
            AntPos[move[i].num] = to;
			AntOnTree[to] = AntOnTree[move[i].next];    // update the index of ant on new position
			AntOnTree[move[i].next] = 0;                // clear the index of ant on old position
        }
	}
	++cnt[AntOnTree[pos]];
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, k, l;
	while( scanf("%d", &n) && n ){
		EdgeInput(n);
		scanf("%d", &k);
		AntInput(k);
		scanf("%d", &l);
		for(int i=0; i<l; ++i)	LadybugCome();
		for(int i=1; i<=k; ++i) printf("%d %d\n", AntPos[i], cnt[i]);
	}
	return 0;
}
