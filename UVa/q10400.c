#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[100], op[100];
char walk[101][64000];

char backtrace(int index, int end, int result, int target){
    if( walk[index][result+32000] )   return 0;
    else    walk[index][result+32000] = 1;

	if( index==end ){
		if( result!=target )    return 0;
		printf("%d", num[0]);   int i;
		for(i=1; i<end; i++){
			if( op[i]==1 )      printf("+%d", num[i]);
			else if( op[i]==2 ) printf("-%d", num[i]);
			else if( op[i]==3 ) printf("*%d", num[i]);
			else                printf("/%d", num[i]);
		}	printf("=%d\n", target);
		return 1;
	}
	
	int new_result = result+num[index];
	if( abs(new_result)<32000 ){
		op[index] = 1;
		if( backtrace(index+1, end, new_result, target) )	return 1;
	}
	
	new_result = result-num[index];
	if( abs(new_result)<32000 ){
		op[index] = 2;
		if( backtrace(index+1, end, new_result, target) )	return 1;
	}
	
	new_result = result*num[index];
	if( abs(new_result)<32000 ){
		op[index] = 3;
		if( backtrace(index+1, end, new_result, target) )	return 1;
	}
	
	new_result = result/num[index];
	if( new_result*num[index]==result ){
		op[index] = 4;
		if( backtrace(index+1, end, new_result, target) )	return 1;
	}

	return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, p, target, i;
	
	scanf("%d", &c);
	while(c--){
		scanf("%d", &p);
		for(i=0; i<p; ++i)  scanf("%d", &num[i]);
		scanf("%d", &target);
		memset(walk, 0, sizeof(walk));
		if( !backtrace(1,p,num[0],target) )	puts("NO EXPRESSION");
	}
	
	return 0;
}
