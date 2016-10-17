#include <stdio.h>
#include <string.h>

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, i, j, k;
	char in[10000];
	scanf("%d", &n);
	while( n-- ){
		scanf("%s", in);    k = strlen(in);
		j = k - 1;	i = 0;
		while( j > i ){
			if( in[j-1]=='A' && in[j]=='B' )    j -= 2;
			else if( in[j]=='A' && in[i]=='B' ) i++, j--;
			else break;
		}
		if( i!=j || in[i]!='A' )    puts("MUTANT");
		else{
			if( k==1 )				puts("SIMPLE");
			else if( in[k-1]=='B' ) puts("FULLY-GROWN");
			else                    puts("MUTAGENIC");
		}
	}
	return 0;
}
