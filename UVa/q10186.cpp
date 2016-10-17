#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct MATCH{
	int a, b;
    MATCH(){};
	MATCH(int a, int b): a(a), b(b){};
};

map<string,int> hash;
string back[21];
int point[21], best[21], worst[21];
MATCH match[10];

int Input(int n){
	char from[35], to[35];
	hash.clear();
	for(int i=1; i<=n; i++){
		scanf("%s", from);  back[i] = string(from);
		hash[back[i]] = i;
	}
	
	int m, a, b, f, t, cnt[20][20]={0};
	memset(point, 0, sizeof(point));
	memset(best, 127, sizeof(point));
	memset(worst, 0, sizeof(worst));
	for(int i=1; i<=n; ++i)for(int j=i+1; j<=n; ++j) cnt[i][j] = 2;
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%s %s %d %d", from, to, &a, &b);
		f = hash[string(from)]; t = hash[string(to)];
		if( a>b )   	point[f] += 3;
		else if( b>a )  point[t] += 3;
		else            point[f] += 1, point[t] += 1;
		if( f<t )   cnt[f][t]--;
		else        cnt[t][f]--;
	}
	
	int mat = 0;
	for(int i=1; i<=n; ++i)for(int j=i+1; j<=n; ++j)
	if( cnt[i][j] ){
		match[mat++] = MATCH(i, j);
		cnt[i][j]--;    j--;
	}
	return mat;
}

bool cmp(MATCH a, MATCH b){
	if( a.b > b.b ) return true;
	else            return false;
}

void backtrace(int index, int m, int n){
	if( index==m ){
		MATCH sorting[20];
		for(int i=1; i<=n; ++i)  sorting[i-1] = MATCH(i, point[i]);
		sort(sorting, sorting+n, cmp);
		
		int b[21]={0}, w[21]={0};
		//  best ranking
		for(int i=0,j,pre=100; i<n; i++){
			if( pre!=sorting[i].b ){
				j=i+1;	pre = sorting[i].b;
			}
			b[sorting[i].a] = j;
		}
		// worst ranking
		for(int i=n-1,j,pre=-1; i>=0; i--){
			if( pre!=sorting[i].b ){
				j=i+1;	pre = sorting[i].b;
			}
			w[sorting[i].a] = j;
		}
		for(int i=1; i<=n; i++){
			if( best[i] > b[i] )    best[i] = b[i];
			if( worst[i] < w[i] )   worst[i] = w[i];
		}
		return ;
	}
	
	point[match[index].a] += 3;
	backtrace(index+1, m, n);
	point[match[index].a] -= 3;
	
	point[match[index].b] += 3;
	backtrace(index+1, m, n);
	point[match[index].b] -= 3;
	
	point[match[index].a] += 1;
	point[match[index].b] += 1;
	backtrace(index+1, m, n);
	point[match[index].a] -= 1;
	point[match[index].b] -= 1;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cc=0, n, m;

	while( scanf("%d", &n) && n ){
		m = Input(n);
		backtrace(0, m, n);
		printf("Group #%d\n", ++cc);
		for(int i=1; i<=n; i++) printf("%s %d-%d\n", back[i].c_str(), best[i], worst[i]);
		putchar('\n');
    }

	return 0;
}
