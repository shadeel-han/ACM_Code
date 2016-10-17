#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[26];
int dir[26];

void EdgeInput(int m){
	for(int i=0; i<26; ++i) edge[i].clear();
	char from[1000], to[1000];
	for(int i=0; i<m; ++i){
		scanf("%s %s", from, to);
		int f=from[0]-'A', t=to[0]-'A';
		edge[f].push_back(t);
		edge[t].push_back(f);
	}
}

void BfsTraverse(int f/*, int t*/){
	memset(dir, -1, sizeof(dir));
	queue<int> que;
	que.push(f);    dir[f] = -100;
	while( !que.empty() ){
		int now = que.front();  que.pop();
		for(int i=0,j=edge[now].size(); i<j; ++i){
			int tmp = edge[now][i];
			if( dir[tmp]==-1 ){
				dir[tmp] = now;
				que.push(tmp);
			}
		}
	}
}

void PrintAns(int t){
	if( t<0 )   return;
	PrintAns(dir[t]);
	putchar('A'+t);
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int c, m, n;
	scanf("%d", &c);
	while( c-- ){
		scanf("%d %d", &m, &n);
		EdgeInput(m);
		char from[1000], to[1000];
		for(int i=0; i<n; ++i){
			scanf("%s %s", from, to);
			BfsTraverse((int)(from[0]-'A')/*,(int)(to[0]-'A')*/);
			PrintAns((int)(to[0]-'A')); putchar('\n');
		}
		if( c )	putchar('\n');
	}
	return 0;
}
