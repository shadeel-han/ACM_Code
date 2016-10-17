#include <stdio.h>

char tt[10], name[12][35];
int from, to;

int InputProcess(void){
	gets(tt);
	int i = 0;
	while( gets(name[i])!=NULL )
	if( !name[i][0] )	break;
	else				i++;
	
	if( tt[0]=='*' )			from=1, to=i;
	else if( !(tt[1]&&tt[2]) )	sscanf(tt, "%d", &from), to=from;
	else						sscanf(tt, "%d %d", &from, &to);
	
	return i;
}

void backtrace(int n, int limit){
	int i, j, k, pow=1<<n;
	for(i=pow-1; i>=1; --i){
		int cnt = 0;
		for(j=1; j<pow; j<<=1)
		if( i&j )   ++cnt;
		if( cnt==limit ){
			char output[400] = {0};
            for(j=pow>>1,k=0; k<n; j>>=1, ++k)
            if( i&j )	sprintf(output, "%s, %s", output, name[k]);
            puts(output+2);
		}
	}
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c, n, i;
	
	scanf("%d", &c);
	getchar();	getchar();	/* flush \n */
	while( c-- ){
		n = InputProcess();
		for(i=from; i<=to; ++i){
			printf("Size %d\n", i);
            backtrace(n, i);
            putchar('\n');
		}
		if( c ) putchar('\n');
	}

	return 0;
}
