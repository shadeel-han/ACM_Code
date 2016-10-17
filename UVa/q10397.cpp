#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 751
struct POINT{
	int x, y;
	double dis;
	POINT(){};
	POINT(int a, int b, double c):x(a), y(b), dis(c){};
	bool operator<(const POINT &a) const{	// minimum heap for PQ
		return (dis>a.dis);
	}
};

POINT point[MAXN];
int p[MAXN], r[MAXN], ind;

int FindSet(int x){
    if(x!=p[x])	p[x] = FindSet(p[x]);
    return p[x];
}

void Link(int x,int y){
    if(r[x]>r[y])	p[y] = x;
    else{
        p[x] = y;
        if(r[x]==r[y])	r[y]++;
    }
}

void Union(int x,int y){
    Link(FindSet(x),FindSet(y));
}

void MakeSet(int x){
	p[x] = x;	r[x] = 0;
}

void Input(int n){
	int m, a, b;
	for(int i=1; i<=n; i++)  scanf("%d %d", &point[i].x, &point[i].y);

	scanf("%d", &m);    ind = n-1;
	for(int i=1; i<=n; i++) MakeSet(i); // MST_kruskal's initial
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if( FindSet(a) != FindSet(b) ){
			Union(a, b);    ind--;
		}
	}
}

double Solve(int n){  // MST_kruskal
	priority_queue<POINT> pq;
	for(int i=1; i<n; i++)for(int j=i+1; j<=n; j++)
	if( FindSet(i) != FindSet(j) ){
		int x=point[i].x-point[j].x, y=point[i].y-point[j].y;
		double dis = sqrt(double(x*x+y*y));
		pq.push(POINT(i,j,dis));
	}
	double ans = 0.0;
	while( !pq.empty() && ind ){
		POINT now = pq.top();   pq.pop();
		if( FindSet(now.x) == FindSet(now.y) )  continue;
		Union(now.x, now.y);    ind--;  ans += now.dis;
	}
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n;
	while( scanf("%d", &n)!=EOF ){
		Input(n);
		printf("%.2lf\n", Solve(n));
	}
	return 0;
}
