#include <stdio.h>
#include <string.h>

char puzzle[100][30][30], used[100];
int order[100];

typedef struct{
	int top, left, botm, right;
}PIECE;
PIECE piece[100];

char backtrace(int index, int end, int dim){
	if( index==end )    return 1;
	
	int i, df=dim-1, row=index/dim, col=index-row*dim, prer=index-dim, prec=index-1;
	for(i=0; i<end; ++i){
		if( used[i] )   continue;
		if( !row && piece[i].top )		continue;
		if( row==df && piece[i].botm )	continue;
		if( !col && piece[i].left )     continue;
		if( col==df && piece[i].right )	continue;
		if( row && (piece[i].top!=(-piece[order[prer]].botm)) )		continue;
		if( col && (piece[i].left!=(-piece[order[prec]].right)) )   continue;
		
		used[i] = 1;
		order[index] = i;
		if( backtrace(index+1, end, dim) )  return 1;
		used[i] = 0;
	}
	return 0;
}

int main(){
    /*freopen("in.txt", "r", stdin);*/
	/*freopen("out.txt", "w", stdout);*/
	
	int i, j, k, m, c, dim, hei, wid;
	scanf("%d", &c);
	while( c-- ){
		scanf("%d %d %d", &dim, &hei, &wid);
		for(i=0, j=dim*dim; i<j; ++i){
			getchar();  /* flush \n */
			for(k=0; k<hei; ++k)	gets(puzzle[i][k]);
			scanf("%d %d %d %d", &piece[i].top, &piece[i].left, &piece[i].botm, &piece[i].right);
			getchar();
		}
		memset(used, 0, sizeof(used));
		backtrace(0, dim*dim, dim);
		for(i=0, j=dim*dim; i<j; i+=dim){
			for(k=0; k<hei; ++k){
				for(m=0; m<dim; ++m)    printf("%s", puzzle[order[i+m]][k]);
				putchar('\n');
			}
		}
		if( c ) putchar('\n');
	}
	
	return 0;
}
