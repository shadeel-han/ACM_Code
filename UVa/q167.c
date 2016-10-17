#include <stdio.h>

int board[64], ans, col[8]={0}, pos[64]={0};

void search(int row, int sum){
	if( row==8 ){
		if( ans < sum ) ans = sum;
		return ;
	}
	int i, j, k;
	for(i=0; i<8; ++i){
		int here = row*8+i;
		if( col[i] || pos[here] )	continue;
		++col[i];
		for(j=i-1, k=here+7; j>=0 && k<64; --j, k+=7)   ++pos[k];
		for(j=i+1, k=here+9; j<8 && k<64; ++j, k+=9)	++pos[k];
		search(row+1, sum+board[here]);
		--col[i];
		for(j=i-1, k=here+7; j>=0 && k<64; --j, k+=7)   --pos[k];
		for(j=i+1, k=here+9; j<8 && k<64; ++j, k+=9)	--pos[k];
	}
}

int main(void){
	/*freopen("in.txt", "r", stdin);*/
	/*freopen("out.txt", "w", stdout);*/
	int c, i;
	scanf("%d", &c);
	while( c-- ){
		for(i=0; i<64; ++i) scanf("%d", &board[i]);
		ans = 0;
		search(0,0);
		printf("%5d\n", ans);
	}
	
	return 0;
}
