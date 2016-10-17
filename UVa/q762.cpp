#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define NAMELEN 5

struct TRIE{
	int next[26], num;
} trie[705];
int trie_end, trie_num;
vector<int> edge[680];
char NtoC[680][NAMELEN]={0};
int dir[680];

void BuildTrie(char in[NAMELEN]){
    // build trie
	int index = 0;
	for(int i=0; i<2; ++i)  // strlen(in)
	if( !trie[index].next[in[i]-'A'] ){
    	trie[index].next[in[i]-'A'] = ++trie_end;
        index = trie_end;
	} else
		index = trie[index].next[in[i]-'A'];
	trie[index].num = ++trie_num;
	strncpy(NtoC[trie_num],in,2);	// strlen(in)
}

int SearchTrie(char in[NAMELEN]){
	int i, index=0;
	for(i=0; i<2; ++i)  // strlen(in)
    if( !trie[index].next[in[i]-'A'] )  break;
	else	index = trie[index].next[in[i]-'A'];
	if( i!=2 || !trie[index].num )  return -1;
	else                            return trie[index].num;
}

void Input(int n){
	memset(trie,0,sizeof(trie));
	trie_end = 0;   trie_num = 0;
	for(int i=1; i<680; ++i)  edge[i].clear();
	
	char from[NAMELEN], to[NAMELEN];
	for(int i=0; i<n; ++i){
		scanf("%s %s", from, to);
		int f=SearchTrie(from), t=SearchTrie(to);
		if( f==-1 ){
            BuildTrie(from);
			f = trie_num;
		}
		if( t==-1 ){
            BuildTrie(to);
			t = trie_num;
		}
		edge[f].push_back(t);
		edge[t].push_back(f);
	}
}

bool BfsTraverse(int f, int t){
	if( f==-1 || t==-1 )    return false;
	int dis[680];   memset(dis,-1,sizeof(dis));
	queue<int> que; bool spfa[680]={0};
	que.push(f);	dis[f] = 0;	dir[f] = 0;	//spfa[f]=true;
	while( !que.empty() ){
		int now = que.front();  que.pop();  spfa[now] = false;
		for(int i=0,j=edge[now].size(); i<j; ++i){
			int tmp = edge[now][i], dt = dis[now]+1;
			if( dis[tmp] > dt || dis[tmp]==-1 ){
                dis[tmp] = dt;  dir[tmp] = now;
                if( !spfa[tmp] ){
                    spfa[tmp] = true;
                    que.push(tmp);
                }
			}
		}
	}
	if( dis[t]==-1 )    return false;
	else                return true;
}

void PrintRoute(int t){
	if( !dir[t] )    return;
	PrintRoute(dir[t]);
	printf("%s %s\n", NtoC[dir[t]], NtoC[t]);
}

int main(){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, c=0;
	while( scanf("%d", &n)!=EOF ){
		if( c++ )   putchar('\n');
		Input(n);
		char from[NAMELEN], to[NAMELEN];
		scanf("%s %s", from, to);
		int f=SearchTrie(from), t=SearchTrie(to);
		if( BfsTraverse(f,t) )	PrintRoute(t);
		else        			puts("No route");
	}
	return 0;
}
