#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct TRIE{
	int next[26], num;
} trie[50];
int trie_end;
vector<int> edge[31];

void HouseNameInput(int m){
	memset(trie,0,sizeof(trie));
	trie_end = 0;
	char name[5];
	for(int i=1; i<=m; ++i){
		scanf("%s", name);
		// build trie
		int index = 0;
		for(int j=0; j<2; ++j)
		if( !trie[index].next[name[j]-'A'] ){
            trie[index].next[name[j]-'A'] = ++trie_end;
            index = trie_end;
		} else
			index = trie[index].next[name[j]-'A'];
		trie[index].num = i;
	}
}

int SearchTrie(char in[5]){
	int i, index=0;
	for(i=0; i<2; ++i)
    if( !trie[index].next[in[i]-'A'] )  break;
	else	index = trie[index].next[in[i]-'A'];
	if( i!=2 || !trie[index].num )  return -1;
	else                            return trie[index].num;
}

void LegInput(int m, int n){
	char from[5], to[5];
	for(int i=1; i<=m; ++i)	edge[i].clear();
    for(int i=0; i<n; ++i){
		scanf("%s %s", from, to);
		int f = SearchTrie(from), t = SearchTrie(to);
		if( f!=-1 && t!=-1 ){
            edge[f].push_back(t);
			edge[t].push_back(f);
		}
	}
}

int traverse(int from, int to){
	int walk[30];	queue<int> que;

	memset(walk,-1,sizeof(walk));
	que.push(from); walk[from] = 0;
    while( !que.empty() ){
		int now = que.front();  que.pop();
		for(int i=0,j=edge[now].size(); i<j; ++i){
			if( walk[edge[now][i]]==-1 ){
                walk[edge[now][i]] = walk[now]+1;
                que.push(edge[now][i]);
			}
		}
    }
    return walk[to];
}

void Request(void){
	char from[5], to[5];    int size;
	scanf("%d %s %s", &size, from, to);
	int f = SearchTrie(from), t = SearchTrie(to);
	int dis;
	if( f!=-1 && t!=-1 )	dis = traverse(f,t);
	else					dis = -1;
	if( dis!=-1 )   printf("$%d\n", size*dis*100);
	else            puts("NO SHIPMENT POSSIBLE");
}

int main(void){

    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int dataset, m, n, p;
	scanf("%d", &dataset);
	puts("SHIPPING ROUTES OUTPUT");
	for(int i=1; i<=dataset; ++i){
		printf("\nDATA SET  %d\n\n", i);
		scanf("%d %d %d", &m, &n, &p);
		HouseNameInput(m);
		LegInput(m,n);
		for(int j=0; j<p; ++j)	Request();
	}
	puts("\nEND OF OUTPUT");
	return 0;
}
