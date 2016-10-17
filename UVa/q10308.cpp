#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define SIZE 10001

struct EDGE{
	int to, w;
	EDGE() {};
	EDGE(int x, int y):to(x),w(y) {};
};

vector<EDGE> edge[SIZE];
int diameter;

int DFSTraverse(int n, int pn){ // this node, parent node
	int FirstHei = 0, SecondHei = 0;
	for(int i=0,j=edge[n].size(); i<j; ++i)
	if( edge[n][i].to != pn ){
		int hei = DFSTraverse(edge[n][i].to,n) + edge[n][i].w;
		if( FirstHei < hei ){
            SecondHei = FirstHei;
            FirstHei = hei;
		}else if( SecondHei < hei )
		    SecondHei = hei;
	}
	// the diameter exist in this subtree as n is the root
	diameter = (diameter>=(FirstHei+SecondHei))?(diameter):(FirstHei+SecondHei);
	// otherwise this subtree may keep only the part diameter
	return FirstHei;
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char in[100];   bool goon = true;
	while( goon && gets(in)!=NULL ){
		if( strlen(in)==0 ){    // fucking special case with no input
			puts("0");
			continue;
		}
		// input process
		diameter = 0;
		for(int i=1; i<SIZE; ++i)   edge[i].clear();
		int from, to, wei;
		do{
            sscanf(in, "%d %d %d", &from, &to, &wei);
            edge[from].push_back(EDGE(to,wei));
            edge[to].push_back(EDGE(from,wei)); // bidirectional
            if( gets(in)==NULL )    goon = false;
		}while( goon && strlen(in)!=0 );
		
		DFSTraverse(from,from);
		printf("%d\n", diameter);
	}
	return 0;
}
