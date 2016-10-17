#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXX (300/2+1)

typedef struct{
	int num, cnt;    char str[5];
} PRIME;
PRIME prime[MAXX], cnt[MAXX];
int prime_num=1, take[13];

char backtrace(int start, int t, int rmd, int two_used){
	/* 2 is used, and remaining chosen number and rmd are not both odd/even */
	if( two_used && (t&1)!=(rmd&1) )  return -1;

	if( !t )    return (rmd)?(-1):(0);

	int i;
	for(i=start; i<prime_num; i++)
	if( prime[i].num<=rmd && cnt[i].cnt ){
		cnt[i].cnt--;
		take[t] = prime[i].num;
		if( !backtrace(i, t-1, rmd-prime[i].num, two_used||(prime[i].num==2)) )	return 0;
		cnt[i].cnt++;
	}
	return -1;
}

int compare( const void* a, const void* b ){
	PRIME aa=*(PRIME*)a, bb=*(PRIME*)b;
	return strcmp(aa.str, bb.str);
	/* sorting lexicographically small to big */
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, n, t, b, bb=0, hash_table[MAXX];
	char notprime[MAXX] = {0};
	prime[0].num = 2;   sprintf(prime[0].str, "%d", 2); prime[0].cnt = 0;
	for(i=1; i<MAXX; i++)if( !notprime[i] ){
        n = (i<<1) + 1;
		for(j=i+n; j<MAXX; j+=n)	notprime[j] = 1;
		prime[prime_num].num = n;   prime[prime_num].cnt = prime_num;
		sprintf(prime[prime_num].str, "%d", n); prime_num++;
    }
    qsort(prime, prime_num, sizeof(PRIME), compare);
	for(i=0; i<prime_num; ++i)  hash_table[prime[i].cnt] = i;

	scanf("%d", &b);
	while( b-- ){
		printf("Block %d:\n", ++bb);
		for(i=1; i<=61; ++i){
			scanf("%d", &j);    prime[hash_table[i]].cnt = j;
		}
		int c=0, q, two;	scanf("%d", &q);
		while( q-- ){
            printf("Query %d:\n", ++c);
			scanf("%d %d %d", &n, &t, &two);
			prime[hash_table[0]].cnt = two;
			memcpy(cnt, prime, sizeof(cnt));
			if( backtrace(0,t,n,1-two) )	puts("No Solution.");
   			else{
            	printf("%d", take[t]);
				for(i=t-1; i>0; i--)  printf("+%d", take[i]);
				putchar('\n');
			}
		}	putchar('\n');
	}
	return 0;
}
