#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>

#define MAXN 101
using namespace std;

struct ROAD{
	string name;
	int to, cost;
};

map<string,int> dir_hash;
map<int,string> rev_hash;
vector<ROAD> road[MAXN];

void MinDis(int f, int t){
	queue<int> que;
	int dis[MAXN], path[MAXN], inque[MAXN]={0};
	memset(dis, -1, sizeof(dis));
	
	que.push(f);	dis[f] = 0;
	while( !que.empty() ){
		int now = que.front();	que.pop();	inque[now] = 0;
		for(int i=0,j=road[now].size(); i<j; i++){
			int tmp = road[now][i].to;
			if( dis[tmp]==-1 || dis[tmp] > dis[now]+road[now][i].cost ){
				dis[tmp] = dis[now] + road[now][i].cost;
				path[tmp] = now;
				if( !inque[tmp] ){
					inque[tmp] = 1;	que.push(tmp);
				}
			}
		}
	}
	
	int a = t, b = -1, c;
	while( b!=f ){
		c = path[a];
		path[a] = b;
		b = a;
		a = c;
	}
	
	puts("\n\nFrom                 To                   Route      Miles");
	puts("-------------------- -------------------- ---------- -----");
	a = f;
	while( a!=t ){
		ROAD tmp;
		c = dis[path[a]] - dis[a];
		for(int i=0, j=road[a].size(); i<j; i++)if( road[a][i].cost==c ){
			tmp = road[a][i];	break;
		};
		printf("%-20s %-20s %-10s %5d\n", rev_hash[a].c_str(), rev_hash[tmp.to].c_str(), tmp.name.c_str(), c);
		a = path[a];
	}
	puts("                                                     -----");
	printf("                                          Total      %5d\n", dis[t]);
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	char input[100], *p;
	string from, to;
	int city = 0;
	ROAD tmp;
	
	while( gets(input) && strlen(input) ){
		p = strtok(input, ",");
		from = string(p);
		if( dir_hash.find(from)==dir_hash.end() ){
			dir_hash[from] = ++city;	rev_hash[city] = from;
		}
		p = strtok(NULL, ",");
		to = string(p);
		if( dir_hash.find(to)==dir_hash.end() ){
			dir_hash[to] = ++city;	rev_hash[city] = to;
		}
		p = strtok(NULL, ",");
		tmp.name = string(p);
		p = strtok(NULL, ",");
		tmp.cost = atoi(p);
		tmp.to = dir_hash[to];
		road[dir_hash[from]].push_back(tmp);
		tmp.to = dir_hash[from];
		road[dir_hash[to]].push_back(tmp);
	}
	
	int f, t;
	
	while( gets(input)!=NULL ){
		p = strtok(input, ",");	f = dir_hash[string(p)];
		p = strtok(NULL, ",");	t = dir_hash[string(p)];
		MinDis(f,t);
	}
	
	return 0;
}

