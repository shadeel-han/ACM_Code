#include <stdio.h>
#include <string.h>

int main(){
    int total, num, i, j, k, small, open=0;
    int day, fine, output[1001];
    double avg[1001], temp;
    
    scanf("%d", &total);
    while(total--){
       if(open)
          printf("\n");
       else
            open++;
       scanf("%d", &num);
       for( i=1; i<=num; i++ ){
            scanf("%d %d", &day, &fine);
            avg[i] = (double)fine/(double)day;
            output[i] = i;
       }
       
		for(i=num; i>1; --i){
			for(j=1; j<i; ++j){
                k = j+1;
				if(avg[j] < avg[k]){
					temp = avg[j];
                    avg[j] = avg[k];
                    avg[k] = temp;
                    small = output[j];
                    output[j] = output[k];
                    output[k] = small;
				}
			}
		}
       
       printf("%d", output[1]);
       for( i=2; i<=num; i++ )
            printf(" %d", output[i]);
       printf("\n");
    }
    return 0;
}
