#include <stdio.h>
#include <string.h>

char sor[50], des[50], stack[50], output[200];

void backtrace(int end, int top, int push, int pop){
	if( pop == end ){
		puts(output);
		return ;
	}
	
	int index = (push+pop)<<1;
	if( push < end ){
		output[index] = 'i';
		int tmp = stack[top];	stack[top] = sor[push];
        backtrace(end, top+1, push+1, pop);
        stack[top] = tmp;
	}
	if( pop < push && stack[top-1]==des[pop] ){
        output[index] = 'o';
        backtrace(end, top-1, push, pop+1);
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	while( scanf("%s", sor)!=EOF ){
		scanf("%s", des);
		int len = strlen(sor);
		memset(output, ' ', sizeof(output));
		output[(len<<2)-1] = 0;
		puts("[");
		if( len==strlen(des) )
		backtrace(len,0,0,0);
		puts("]");
	}
	
	return 0;
}
