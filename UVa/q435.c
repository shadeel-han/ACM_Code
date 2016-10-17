#include <stdio.h>

int party[20], ans;

void backtrace(int start, int end, int sum, int half, int pick, int pv){
	if( start==end )    return;
	
	/* not take party[i]*/
	backtrace(start+1, end, sum, half, pick, pv);
	/* take party[i]*/
	int new_sum = sum + party[start];
	if( start!=pick && new_sum < half ){
		if( new_sum+pv>=half )  ++ans;
		backtrace(start+1, end, new_sum, half, pick, pv);
	}

	/*int i;    // a little faster form of standard backtrace
	for(i=start; i<end; ++i){
        int new_sum = sum + party[i];
		if( i!=pick && new_sum < half ){
			if( new_sum+pv>=half )	++ans;
			backtrace(i+1, end, new_sum, half, pick, pv);
		}
	}*/
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, n, i, j, t, half;

	scanf("%d", &c);
	while( c-- ){
		scanf("%d", &n);
		for(i=0,t=0; i<n; ++i){
			scanf("%d", &party[i]);
			t += party[i];
		}
		half = t/2 + 1;
		
		for(i=0; i<n; ++i){
			/*if( party[i]>=half )    ans = 1;
			else                    */ans = 0;
            backtrace(0, n, 0, half, i, party[i]);
            printf("party %d has power index %d\n", i+1, ans);
		}
		putchar('\n');
	}

	return 0;
}
