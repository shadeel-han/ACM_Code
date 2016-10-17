#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define NAMELEN 100

struct NODE{
	int HashDep, HashArr, StartTime, EndTime;
	NODE() {};
	NODE(int x, int y, int a, int b):HashDep(x),HashArr(y),StartTime(a),EndTime(b) {};
};
vector<NODE> sta[100], resta[100];  // edge, reverse edge
map<string,int> hash;
NODE node[100];

void CityInput(void){
	hash.clear();
	int n;  char name[NAMELEN];
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		sta[i].clear();
		resta[i].clear();
		node[i] = NODE(-1,-1,0,0);
		scanf("%s", name);
		string str(name);
		hash[str] = i;
	}
}

bool cmp(NODE a, NODE b){
	return a.StartTime < b.StartTime;
}

void TrainInput(void){
	int m;  scanf("%d", &m);
	vector<NODE> line;
	for(int i=0; i<m; ++i){
        int t;	char in[NAMELEN];
        scanf("%d %s", &t, in);
		string from(in);
		line.push_back(NODE(hash[from],0,t,0));
	}
	sort(line.begin(), line.end(), cmp);
	/*for(int i=0,j=m-1; i<j; ++i){					// WA
		NODE tmp(line[i].HashDep,line[i+1].HashDep,line[i].StartTime,line[i+1].StartTime);
		sta[line[i].HashDep].push_back(tmp);
		resta[line[i+1].HashDep].push_back(tmp);
	}*/
	for(int i=0; i<m; ++i)for(int j=i+1; j<m; ++j){ // AC
		NODE tmp(line[i].HashDep,line[j].HashDep,line[i].StartTime,line[j].StartTime);
		sta[line[i].HashDep].push_back(tmp);
		resta[line[j].HashDep].push_back(tmp);
	}
}

bool BFSTraverse(int tt, int f, int t){ // start at source, earliest time for all stations
	queue<NODE> que;
	que.push(NODE(-100,f,0,tt));
	node[f] = NODE(-100,f,0,tt);
	bool spfa[100]={0}; spfa[f] = true;
	
	while( !que.empty() ){
		NODE now = que.front(); que.pop();
		int NowSta = now.HashArr, NowTime = now.EndTime;	spfa[NowSta] = false;
		for(int i=0,j=sta[NowSta].size(); i<j; ++i)
		if( NowTime <= sta[NowSta][i].StartTime ){
            int TmpSta = sta[NowSta][i].HashArr, TmpTime = sta[NowSta][i].EndTime;
            if( node[TmpSta].HashDep==-1 || TmpTime < node[TmpSta].EndTime ){
                node[TmpSta] = sta[NowSta][i];
                if( !spfa[TmpSta] ){
                    spfa[TmpSta] = true;
                    que.push(sta[NowSta][i]);
                }
            }
		}
	}
	return (node[t].HashDep==-1)?(false):(true);
}

void BFSReverseTraverse(int tt, int f){ // start at sink, latest time for reachable stations
	queue<NODE> que;
	que.push(NODE(f,-100,tt,2400));
	node[f] = NODE(f,-100,tt,2400);
	bool spfa[100]={0}; spfa[f] = true;

	while( !que.empty() ){
		NODE now = que.front(); que.pop();
		int NowSta = now.HashDep, NowTime = now.StartTime;	spfa[NowSta] = false;
		for(int i=0,j=resta[NowSta].size(); i<j; ++i)
		if( NowTime >= resta[NowSta][i].EndTime ){
            int TmpSta = resta[NowSta][i].HashDep, TmpTime = resta[NowSta][i].StartTime;
            if( node[TmpSta].HashArr==TmpSta || TmpTime > node[TmpSta].StartTime ){
                node[TmpSta] = resta[NowSta][i];
                if( !spfa[TmpSta] ){
                    spfa[TmpSta] = true;
                    que.push(resta[NowSta][i]);
                }
            }
		}
	}
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cas, c=0, n;
	scanf("%d", &cas);
	while( cas-- ){
		printf("Scenario %d\n", ++c);
		CityInput();
		scanf("%d", &n);
		for(int i=0; i<n; ++i)	TrainInput();
		char from[NAMELEN], to[NAMELEN];    int t;
		scanf("%d %s %s", &t, from, to);
		string dep(from), arr(to);
		if( hash.find(dep)!=hash.end() && hash.find(arr)!=hash.end() && BFSTraverse(t,hash[dep],hash[arr]) ){
			BFSReverseTraverse(node[hash[arr]].EndTime,hash[arr]);
			printf("Departure %04d %s\n", node[hash[dep]].StartTime, from);
			printf("Arrival   %04d %s\n\n", node[hash[arr]].StartTime, to);
		}else puts("No connection\n");
	}
	return 0;
}
