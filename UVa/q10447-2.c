#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXX (300/2+1)

typedef struct{
	int num, cnt;    char str[5];
} PRIME;
PRIME prime[MAXX];
int prime_num=1, take[MAXX], B=0;
int walk[13][MAXX][801];    /*-1:not visited, <=(-2):invalid, >=0:valid and used number*/
/*int mem[13][MAXX][801]={0};*/

int backtrace(int index, int t, int rmd, int two_used){
	/*int m = mem[t][index][rmd];*/

    if( rmd<0 )	return -1;
    /*if( m!=B )	mem[t][index][rmd] = B;*/
    if( walk[t][index][rmd]<(-1) )	return -2;
	/* 2 is used, and remaining chosen number and rmd are not both odd/even */
	if( two_used && (t&1)!=(rmd&1) )return -1;

	if( !t ){
		int r = (rmd)?(-2):(0);		return walk[t][index][rmd] = r;
	} else if( index==prime_num )   return -1;

	int i=(walk[t][index][rmd]==-1)?(prime[index].cnt):(walk[t][index][rmd]);
	for(i=(i>t)?(t):(i); i>=0; i--){
        if( backtrace(index+1, t-i, rmd-i*prime[index].num, two_used||(prime[i].num==2))>=0 ){
			take[index]= i;
			return walk[t][index][rmd] = i;
        }
	}

	return walk[t][index][rmd] = -2;
}

int compare( const void* a, const void* b ){
	PRIME aa=*(PRIME*)a, bb=*(PRIME*)b;
	return strcmp(aa.str, bb.str);
	/* sorting lexicographically small to big */
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, n, t, b, hash_table[MAXX];
	char notprime[MAXX]={0}, output[65];
	prime[0].num = 2;   sprintf(prime[0].str, "%d", 2); prime[0].cnt = 0;
	for(i=1; i<MAXX; i++)if( !notprime[i] ){
        n = (i<<1) + 1;
		for(j=i+n; j<MAXX; j+=n)	notprime[j] = 1;
		prime[prime_num].num = n;   prime[prime_num].cnt = prime_num;
		sprintf(prime[prime_num].str, "%d", n); prime_num++;
    }
    qsort(prime, prime_num, sizeof(PRIME), compare);
	for(i=0; i<prime_num; ++i)  hash_table[prime[i].cnt] = i;
	/*memset(walk, -1, sizeof(walk));*/

	scanf("%d", &b);
	while( b-- ){
		printf("Block %d:\n", ++B);
		for(i=1; i<=61; ++i){
			scanf("%d", &j);    prime[hash_table[i]].cnt = j;
		}
		memset(walk, -1, sizeof(walk));
		int c=0, q, two;	scanf("%d", &q);
		while( q-- ){
            printf("Query %d:\n", ++c);
			scanf("%d %d %d", &n, &t, &two);
			prime[hash_table[0]].cnt = two;
			if( backtrace(0,t,n,1-two)<=(-1) )	puts("No Solution.");
			else{
				output[0] = 0;
				for(i=0,j=t; (i<prime_num)&&j; i++){
					j -= take[i];
                	while( take[i]-- )  sprintf(output, "%s+%d", output, prime[i].num);
				}
				puts(output+1);
			}
		}	putchar('\n');
	}
	return 0;
}
