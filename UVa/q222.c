#include <stdio.h>
#include <math.h>

#define EPS 0.000001

typedef struct{
	double far, dollar;
}STAT;
STAT sta[51];
double dis, fuel_cap, mile_perg, orig_cost, ans;
int station;

void backtrack(int index, double pos, double remain_gas, double cost){
	if( index==station ){
		if( ans > cost )    ans = cost;
		return ;
	}
	
	double now_pos = sta[index].far, now_remain_gas = remain_gas-(now_pos-pos)/mile_perg;
	double run_dis = now_remain_gas*mile_perg + EPS;
	
	/* fill at this station */
	if( (now_remain_gas<=fuel_cap/2.0) ||
		(index<station-1 && run_dis<sta[index+1].far-now_pos) ||
		(index==station-1 && run_dis<dis-now_pos) ){
		double here_cost = (fuel_cap-now_remain_gas)*sta[index].dollar/100.0;
		/* DO NOT round the cost at every stop as described;
			otherwise, you will get WA because of little inaccuracy*/
		backtrack(index+1, now_pos, fuel_cap, cost+2.0+here_cost);
	}
	
	/* don't fill, only if remain_gas is enough to arriving next station or destination */
	if( run_dis>=(dis-now_pos) || (index<station-1 && run_dis>=sta[index+1].far-now_pos) )
		backtrack(index+1, now_pos, now_remain_gas, cost);
}

int main(void){
    /*freopen("in.txt", "r", stdin);*/
	/*freopen("out.txt", "w", stdout);*/
	int c=0, i;
	
	while( scanf("%lf", &dis) && dis>0 ){
		scanf("%lf %lf %lf %d", &fuel_cap, &mile_perg, &orig_cost, &station);
		for(i=0; i<station; ++i)    scanf("%lf %lf", &sta[i].far, &sta[i].dollar);
		ans = 2147483647;
		backtrack(0, 0.0, fuel_cap, orig_cost);
		printf("Data Set #%d\nminimum cost = $%.2lf\n", ++c, ans);
	}
	
	return 0;
}
