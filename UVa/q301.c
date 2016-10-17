#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int on, off, earn, peo;
}ORDER;

int cap, Bnum, ord, ans, addback[10]={0};
ORDER order[25];

int compare( const void* a, const void* b ){
	ORDER aa = *(ORDER*)a, bb = *(ORDER*)b;
	return ( aa.on - bb.on );
    /* return value <0  => exchange */
	/* return value >=0 => not exchange */
}

void backtrack(int sta, int start, int earn, int c){
	if( sta==Bnum ){
		if( ans < earn )	ans = earn;
		return ;
	}
	int i;
	for(i=start; order[i].on==sta; ++i){
		/* accept this order */
		if( c < order[i].peo )  continue;
		addback[order[i].off] += order[i].peo;
		backtrack(sta, i+1, earn+order[i].earn, c-order[i].peo);
		addback[order[i].off] -= order[i].peo;
	}
	/* accept no order at this station */
	backtrack(sta+1, i, earn, c+addback[sta+1]);
}

int main(void){
    /*freopen("in.txt", "r", stdin);*/
	/*freopen("out.txt", "w", stdout);*/
	int i;
	
	while( scanf("%d %d %d", &cap, &Bnum, &ord) && (cap || Bnum || ord) ){
		for(i=0; i<ord; ++i){
			scanf("%d %d %d", &order[i].on, &order[i].off, &order[i].peo);
			order[i].earn = (order[i].off - order[i].on)*order[i].peo;
		}
		qsort(order, ord, sizeof(ORDER), compare);
		order[ord].on = Bnum;   /* for backtrack termination */
		ans = 0;
		backtrack(0, 0, 0, cap);
		printf("%d\n", ans);
	}
	
	return 0;
}
