#include <stdio.h>

int coin[100];

int SolveDP(int n, int tol){
	int i, j, half=tol>>1;
	char use[26000]={0};    use[0] = 1;
	for(i=0; i<n; i++){
		for(j=half-1; j>=0; j--)
		if( use[j] )	use[j+coin[i]] = 1;
	}
	for(i=0; i<=half; i++)
	if( use[half+i] || use[half-i] )  break;
	return tol-(half-i)*2;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, n, i, tol;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d", &n);
		for(i=0,tol=0; i<n; i++){
			scanf("%d", &coin[i]);  tol += coin[i];
		}
		printf("%d\n", SolveDP(n, tol));
	}
	return 0;
}
