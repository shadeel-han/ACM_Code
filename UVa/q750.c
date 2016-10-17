#include <stdio.h>

int col[8]={0}, pos[64]={0}, cc=0;
char output[20]="                ";

void backtrace(int row, int r, int c){
	if( row==8 ){
		printf("%2d     ", ++cc);
		puts(output);
		return ;
	}
	
	int i=(row==r)?(c):(0), ii=(row==r)?(c):(7), j, k;
	for( ; i<=ii; ++i){
		int here = row*8+i;
		if( col[i] || pos[here] )	continue;
		output[row*2+1] = '1'+i;
		++col[i];
		for(j=i-1, k=here+7; j>=0 && k<64; --j, k+=7)   ++pos[k];
		for(j=i+1, k=here+9; j<8 && k<64; ++j, k+=9)	++pos[k];
		backtrace(row+1, r, c);
		--col[i];
		for(j=i-1, k=here+7; j>=0 && k<64; --j, k+=7)   --pos[k];
		for(j=i+1, k=here+9; j<8 && k<64; ++j, k+=9)	--pos[k];
	}
}
int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int r, c, cas;
	
	scanf("%d", &cas);
	while( cas-- ){
        scanf("%d %d", &r, &c);
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
		cc = 0;
		backtrace(0, c-1, r-1); /* reverse(r,c) for output order */
		if( cas )	putchar('\n');
    }

	return 0;
}
