#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000001

struct LINE{
	int a, b, cost;
	bool operator<(const LINE &a) const{    // minimum heap for PQ
		return (cost<a.cost);
	}
};

vector<LINE> st;
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
	//while( !pq.empty() )    pq.pop();
	st.clear();	ind = n;
	long long int m = 0;    LINE tmp;
	for(int i=0,j=n-1; i<j; i++){
        scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.cost);
        m += tmp.cost;
	}   printf("%lld\n", m);
	int k;	scanf("%d", &k);
	for(int i=0; i<k; i++){
	    scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.cost);
	    st.push_back(tmp);
	}

	for(int i=1; i<=n; i++) MakeSet(i); // MST_kruskal's initial
	scanf("%lld", &m);
	for(long long int i=0; i<m; i++){
		scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.cost);
		st.push_back(tmp);
	}
	sort(st.begin(), st.end()); // MST_kruskal's sorting
}

long long int Solve(void){   // MST_kruskal
	int index = 0;  long long int c = 0;
	while( ind>1 ){
		if( FindSet(st[index].a) != FindSet(st[index].b) ){
			Union(st[index].a, st[index].b);	ind--;	c += st[index].cost;
		}else   index++;
	}
	return c;
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, first=0;
	while( scanf("%d", &n)!=EOF ){
		if( first++ )   putchar('\n');
        Input(n);
        printf("%lld\n", Solve());
	}
	return 0;
}
