#include <stdio.h>
#include <string.h>

int party[20], bit_table[21], sum_table[1048576];

void backtrace(int index, int end, int sum, int bit_form, int half){

	if( index == end ){
		sum_table[bit_form] = sum;
		return;
	}
	
	backtrace(index+1, end, sum, bit_form, half);
	int new_sum = sum+party[index];
	if( new_sum < half )
	backtrace(index+1, end, new_sum, bit_form|bit_table[index], half);
}

int main(){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, n, i, j, t, half, ans;

	bit_table[0] = 1;
	for(i=1; i<=20; ++i)	bit_table[i] = bit_table[i-1] << 1;
	scanf("%d", &c);
	while( c-- ){
		scanf("%d", &n);
		for(i=0,t=0; i<n; ++i){
			scanf("%d", &party[i]);
			t += party[i];
		}
		half = t/2 + 1;
		memset(sum_table, 0, sizeof(sum_table));
		backtrace(0, n, 0, 0, half);
		
		for(i=0; i<n; ++i){
			ans = 0;
			for(j=0; j<bit_table[n]; ++j){
				if( j&bit_table[i] )  						j = j+bit_table[i]-1;
				else if( !sum_table[j] )   					continue;
				else if( sum_table[j]+party[i] >= half )	++ans;
			}
            printf("party %d has power index %d\n", i+1, ans);
		}
		putchar('\n');
	}

	return 0;
}
