#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
	int x;
	int y;
}BOARD;
BOARD card1[5002];
BOARD card2[5002];
int box[5002];

int input( int x, int y, int ending ){

	int begin=-1, end=ending, i, mid, tmpx, tmpy, cross;

	do{
		mid = (begin+end+1)>>1;
		tmpx = x-card2[mid].x;
		tmpy = y-card2[mid].y;

		cross = tmpx*card1[mid].y - tmpy*card1[mid].x;
		if( cross==0 )	return mid;
		else if( cross>0 )	begin = mid;
		else				end = mid;
		
	}while(end-begin>1);
	
	if( cross < 0 )	return mid-1;
	else			return mid;
}

int main(){

	int i, j, board, toy, bb, posx, posy;
	bool ok = true;

	while( scanf("%d", &board) ){

		if( !board )	break;
		bb = board+1;

		if( ok )	ok = false;
		else		putchar('\n');

		scanf("%d", &toy);

		scanf("%d %d %d %d", &card1[0].x, &card1[0].y, &card2[bb].x, &card2[bb].y);
		card2[0].x = card1[0].x;
		card2[0].y = card2[bb].y;
		card1[bb].x = card2[bb].x;
		card1[bb].y = card1[0].y;

		for( i=1; i<=board; ++i ){
			scanf("%d %d", &card1[i].x, &card2[i].x);
			card1[i].y = card1[0].y;
			card2[i].y = card2[bb].y;
		}

		for( i=0; i<=bb; ++i ){
			card1[i].x -= card2[i].x;
			card1[i].y -= card2[i].y;
		}

		memset(box,0,4*bb);
		for( i=0; i<toy; ++i ){
			scanf("%d %d", &posx, &posy);
			j = input(posx, posy, bb);
			++box[j];
		}

		for( i=0; i<=board; ++i )
			printf("%d: %d\n", i, box[i]);

	}

	return 0;
}
