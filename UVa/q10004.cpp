#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct NODE{
	int n;  char c;
	NODE() {};
	NODE(int n, char c):n(n),c(c) {};
};
vector<int> edge[200];

void EdgeInput(void){
	int n, a, b;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

bool BfsTraverse(int s){
	queue<NODE> que;	char color[200];
	memset(color,-1,sizeof(color));
	que.push(NODE(s,1));    color[s] = 1;
	while( !que.empty() ){
		NODE now = que.front(); que.pop();
		for(int i=0,j=edge[now.n].size(); i<j; ++i){
			NODE tmp(edge[now.n][i], (now.c)?(0):(1));
			if( color[tmp.n]==now.c )	return false;
			if( color[tmp.n]==-1 ){
                color[tmp.n] = tmp.c;
                que.push(tmp);
			}
		}
	}
	return true;
}

int main(){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while( scanf("%d", &n) && n ){
		for(int i=0; i<n; ++i)  edge[i].clear();
		EdgeInput();
		if( BfsTraverse(0) )    puts("BICOLORABLE.");
		else					puts("NOT BICOLORABLE.");
	}
	return 0;
}
