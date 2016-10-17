#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define VILLAGER 101
#define RELATION 1001

using namespace std;

/*struct PAIR{
	int a, b;
	PAIR() {};
	PAIR(int a, int b):a(a),b(b) {};
};*/

char color[RELATION];
int pair_adj[VILLAGER][VILLAGER];
//vector<PAIR> pairs;
vector<int> pair_vec[VILLAGER], color_diff[RELATION], color_same[RELATION];

void RelationshipInput(int n, int m){
	//pairs.clear();
	memset(pair_adj, -1, sizeof(pair_adj));
	memset(color, 0, sizeof(color));
	for(int i=0; i<n; ++i) pair_vec[i].clear();
	
	for(int i=0; i<m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		//pairs.push_back(PAIR(a,b));
		pair_adj[a][b] = i; 	pair_vec[a].push_back(b);
		pair_adj[b][a] = i;     pair_vec[b].push_back(a);
		color_diff[i].clear();
		color_same[i].clear();
	}
}

void TripletExamine(int n){
	for(int i=0; i<n; ++i){
		int bound = pair_vec[i].size();
		for(int j=0; j<bound; ++j)
		for(int k=j+1; k<bound; ++k){
			int a = pair_adj[i][pair_vec[i][j]], b = pair_adj[i][pair_vec[i][k]];
			if( pair_adj[pair_vec[i][j]][pair_vec[i][k]] != -1 ){
				color_same[a].push_back(b);
				color_same[b].push_back(a);
			}
			else{
            	color_diff[a].push_back(b);
				color_diff[b].push_back(a);
			}
		}
	}
}

bool DFSColor(int m, int stop){
	if( m == stop )  return true;
	int i, j = color_same[m].size(), p, q = color_diff[m].size();
	
	for(int a=1; a<=2; ++a){    // try to apply 2 different colors
	/////
	bool same_ok = true, diff_ok = true;
	color[m] = a;
	for(i=0; i<j; ++i){
		int to = color_same[m][i];
		if( to > m )	break;
		if( color[to]!=color[m] ){
            same_ok = false;	break;
		}
	}
	if( same_ok )
	for(p=0; p<q; ++p){
		int to = color_diff[m][p];
		if( to > m )	break;
		if( color[to]==color[m] ){
			diff_ok = false;	break;
		}
	}
	if( same_ok && diff_ok && DFSColor(m+1,stop) )  return true;
	//////
	}

	return false;
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	
	while( scanf("%d", &n) && n ){
		scanf("%d", &m);
		RelationshipInput(n, m);
		TripletExamine(n);
		for(int i=0; i<m; ++i){
			sort(color_same[i].begin(), color_same[i].end());
			sort(color_diff[i].begin(), color_diff[i].end());
		}
		if( DFSColor(0, m) )	puts("YES");
		else					puts("NO");
	}

	return 0;
}
