#include <stdio.h>

#define MAXN 20005
char a[MAXN], b[MAXN];
int order[128][MAXN], sta[MAXN];

int BinarySearch(int start, int end, int val){
	int low=start, up=end, mid;
	while( low!=up ){
        mid = (low+up)>>1;
		if( sta[mid] >= val )	up = mid;
		else                    low = mid + 1;
	}
	return low;
}

int SolveLCS(char* s1, char* s2, int lena, int lenb){
    int num[128] = {0}, i, j, index, nn=0, pos;
    for(i=0; i<lena; i++){
		index = (int)s1[i];
		order[index][num[index]++] = i;
    }
    for(i=0; i<lenb; i++){
		index = (int)s2[i];
		for(j=num[index]-1; j>=0; j--){
            if( order[index][j] > sta[nn] ){
				sta[++nn] = order[index][j];
			}else{
            	pos = BinarySearch(0, nn, order[index][j]);
            	sta[pos] = order[index][j];
        	}
		}
    }
    return nn;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, i, h, w, n, nx, ny, m, mx, my;
	char grid[25][25];
	scanf("%d", &cas);	sta[0] = -1;
	while( cas-- ){
		scanf("%d%d", &h, &w);
		for(i=1; i<=h; i++)	scanf("%s", grid[i]+1);
		scanf("%d%d%d", &n, &nx, &ny);  a[0] = grid[nx][ny];
		if( n ) scanf("%s", a+1);
		for(i=1; i<=n; i++){
			if( a[i]=='N' )			nx--;
			else if( a[i]=='E' )	ny++;
			else if( a[i]=='W' )	ny--;
			else					nx++;
			a[i] = grid[nx][ny];
		}   n++;
		scanf("%d%d%d", &m, &mx, &my);  b[0] = grid[mx][my];
		if( m )	scanf("%s", b+1);
		for(i=1; i<=m; i++){
            if( b[i]=='N' )			mx--;
			else if( b[i]=='E' )	my++;
			else if( b[i]=='W' )	my--;
			else					mx++;
			b[i] = grid[mx][my];
		}   m++;
		if( n < m ) w = SolveLCS(a,b,n,m);  /* for better performance m*log(n) */
		else        w = SolveLCS(b,a,m,n);
		/*w = SolveLCS(a,b,n,m);*/
		printf("Case %d: %d %d\n", ++c, n-w, m-w);
	}
	return 0;
}
