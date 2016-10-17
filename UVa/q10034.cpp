#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

struct POINT{
	int index;
	double x, y;
	POINT(){};
	POINT(int a, double b):index(a), x(b){};
	bool operator<(const POINT &a) const{	// minimum heap for PQ
		return (x>a.x);
	}
};

POINT p[100];

double Solve(int n){
	priority_queue<POINT> pq;	bool touch[100]={0};
	int num = n;    double ans = 0;
	pq.push(POINT(0,0.0));
	while( !pq.empty() && num ){
		POINT now = pq.top();   pq.pop();
		if( touch[now.index] )  continue;
		touch[now.index] = true;    num--;  ans += now.x;
		for(int i=1; i<n; i++)if( !touch[i] ){
			double x=p[now.index].x-p[i].x, y=p[now.index].y-p[i].y;
			pq.push(POINT(i, sqrt(x*x+y*y)));
		}
	}
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, n, first=0;
	scanf("%d", &cas);
	while( cas-- ){
		if( first++ )   putchar('\n');
		scanf("%d", &n);
		for(int i=0; i<n; i++)  scanf("%lf %lf", &p[i].x, &p[i].y);
		printf("%.2lf\n", Solve(n));
	}
	return 0;
}
