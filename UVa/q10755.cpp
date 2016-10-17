#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 20
#define MAX(a,b) (((a)>(b))?(a):(b))
long long int box[MAXN][MAXN][MAXN];

long long int Solve1D(int c, long long int sb[MAXN]){
	int i;
	long long int ans = -2147483649LL, s = 0;
	for(i=0; i<c; i++){
		if( s <= 0 )	s = sb[i];
		else        	s += sb[i];
		ans = MAX(ans,s);
	}
	return ans;
}

long long int Solve2D(int b, int c, long long int sa[MAXN][MAXN]){
	int i, j, k;
	long long int ans = -2147483649LL, tmp;
	for(i=0; i<b; i++){
		long long int s[MAXN]={0};
		for(j=i; j<b; j++){
			for(k=0; k<c; k++)	s[k] += sa[j][k];
			tmp = Solve1D(c, s);
			ans = MAX(ans,tmp);
		}
	}
	return ans;
}

long long int Solve3D(int a, int b, int c){
	int i, j, k, l;
	long long int ans = -2147483649LL, tmp;
	for(i=0; i<a; i++){
		long long int s[MAXN][MAXN]={{0}};
		for(j=i; j<a; j++){
			for(k=0; k<b; k++)for(l=0; l<c; l++)	s[k][l] += box[j][k][l];
			tmp = Solve2D(b, c, s);
			ans = MAX(ans,tmp);
		}
	}
	return ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cc=0, cas, a, b, c, i, j, k;
	scanf("%d", &cas);
	while( cas-- ){
		if( cc++ )   putchar('\n');
		scanf("%d %d %d", &a, &b, &c);
		for(i=0; i<a; i++)for(j=0; j<b; j++)for(k=0; k<c; k++)	cin >> box[i][j][k];
		cout << Solve3D(a, b, c) << endl;
	}
	return 0;
}
