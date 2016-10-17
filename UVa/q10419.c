#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXX (300/2+1)

typedef struct{
	int num;    char str[10];
} PRIME;
PRIME prime[MAXX];
int prime_num=1, cnt[MAXX], take[14];

char backtrace(int start, int index, int t, int rmd){
	if( index==t )	return (rmd)?(0):(1);
	
	int i;
	for(i=start; i<prime_num; i++)if( prime[i].num<=rmd ){
		if( prime[i].num==2 && cnt[i]==1 )  continue;
		else if( cnt[i]==2 )				continue;

		cnt[i]++;
		take[index] = prime[i].num;
		if( backtrace(i, index+1, t, rmd-prime[i].num) )    return 1;
		cnt[i]--;
	}
	return 0;
}

int compare( const void* a, const void* b ){
	PRIME aa=*(PRIME*)a, bb=*(PRIME*)b;
	return strcmp(aa.str, bb.str);
	/* sorting lexicographically small to big */
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, n, t, c=0;
	char notprime[MAXX] = {0};
	prime[0].num = 2;   sprintf(prime[0].str, "%d", 2);
	for(i=1; i<MAXX; i++)if( !notprime[i] ){
        n = (i<<1) + 1;
		for(j=i+n; j<MAXX; j+=n)	notprime[j] = 1;
		prime[prime_num].num = n;
		sprintf(prime[prime_num].str, "%d", n); prime_num++;
    }
    qsort(prime, prime_num, sizeof(PRIME), compare);

	while( scanf("%d %d", &n, &t) && n ){
		printf("CASE %d:\n", ++c);
		memset(cnt, 0, sizeof(cnt));
		if( !backtrace(0,0,t,n) )	puts("No Solution.");
		else{
            printf("%d", take[0]);
			for(i=1; i<t; i++)  printf("+%d", take[i]);
			putchar('\n');
		}
	}
	return 0;
}
