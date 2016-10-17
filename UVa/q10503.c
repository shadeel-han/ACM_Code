#include <stdio.h>
#include <string.h>

typedef struct{
	int f, e;
}POINT;

POINT point[16], p[14];
char used[14];

char backtrace(int index, int end, int m){
	if( index==end ){
		if( point[end].f==point[end-1].e )  return 1;
		else                                return 0;
	}
	int i;
	for(i=0; i<m; i++)if( !used[i] ){
		if( p[i].f!=point[index-1].e && p[i].e!=point[index-1].e )  continue;
		used[i] = 1;
		point[index].e = (p[i].f==point[index-1].e)?(p[i].e):(p[i].f);
		if( backtrace(index+1, end, m) )	return 1;
		used[i] = 0;
	}
	return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, m, i;
	
	while(scanf("%d", &n) && n){
		scanf("%d", &m);
		scanf("%d %d", &point[0].f, &point[0].e);
		scanf("%d %d", &point[n+1].f, &point[n+1].e);
		for(i=0; i<m; i++) scanf("%d %d", &p[i].f, &p[i].e);
		memset(used, 0, sizeof(used));
		if( backtrace(1,n+1,m) )    puts("YES");
		else                        puts("NO");
	}
	
	return 0;
}
