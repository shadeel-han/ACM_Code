#include <stdio.h>
#include <string.h>

char dic[100][260], rule[260], output[66000];

void backtrace(int index, int dict){
	if( !rule[index] ){
		puts(output);   return;
	}
	
	int i, len = strlen(output);
	if( rule[index]=='#' ){
		for(i=0; i<dict; ++i){
			sprintf(output, "%s%s", output, dic[i]);
			backtrace(index+1, dict);
			output[len] = 0;
		}
	}
	else{
        for(i=0; i<10; ++i){
			sprintf(output, "%s%d", output, i);
			backtrace(index+1, dict);
			output[len] = 0;
		}
	}
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int dict, n, i;
	
	while( scanf("%d", &dict)!=EOF ){
		getchar();	/* flush \n */
		for(i=0; i<dict; i++)   gets(dic[i]);
		scanf("%d", &n);
		getchar();	/* flush \n */
		puts("--");
		for(i=0; i<n; i++){
			output[0] = 0;
			gets(rule);
			backtrace(0,dict);
		}
	}
	
	return 0;
}
