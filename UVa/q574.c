#include <stdio.h>
#include <string.h>

typedef struct{
	int branch[101], used;
}TRIE;
TRIE trie[2000];

int in[12], keep[12], t, cnt;
char output[55];

char trie_search_build(int len){
	int i=0, pos=0;
	memset(output, 0, sizeof(output));
	while( i!=len ){
		if( !trie[pos].branch[keep[i]] )
            trie[pos].branch[keep[i]] = cnt++;
        pos = trie[pos].branch[keep[i]];
        sprintf(output, "%s+%d", output, keep[i]);  i++;
	}
	if( !trie[pos].used ){
        trie[pos].used = 1; return 1;
	}
	else	return 0;
}

char backtrace(int put, int sum, int index, int end){
	if( index==end ){
		if( sum != t )  return 0;
		if( trie_search_build(put) )	puts(output+1);
		return 1;
	}
	
	char re = 0;
	keep[put] = in[index];
	re |= backtrace(put+1, sum+in[index], index+1, end);
	re |= backtrace(put, sum, index+1, end);
	return re;
}

int main(){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, i;
	
	while( scanf("%d %d", &t, &n) && n ){
		for(i=0; i<n; ++i)  scanf("%d", &in[i]);
		printf("Sums of %d:\n", t); cnt = 1;
		memset(trie, 0, sizeof(trie));
		if( !backtrace(0, 0, 0, n) )   puts("NONE");
	}

	return 0;
}
