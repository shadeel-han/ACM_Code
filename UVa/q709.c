#include <stdio.h>
#include <string.h>

#define MAXN 10001
char in[MAXN*5], *pt[MAXN];
int word_len[MAXN], dp[MAXN], path[MAXN], space[MAXN];

int ComputeBad(int sp, int n){
	int i, j, k, bad = 0;
	if( !n )	bad = (!sp)?(0):(500);
	else for(i=n,k=sp; i; i--){
			j = k/i - 1;
			bad += (j*j);
			k -= (j+1);
	}
	return bad;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, len, i, j, k, m;
	char *p;
	while( scanf("%d\n", &n) && n ){
		len = 0;
		while( gets(in+len) ){
			i = strlen(in+len);
			if( !i )	break;
			else{
				len += i;	in[len++] = ' ';
			}
		}
		/* count words and get pointers */
		p = strtok(in, " ");    len = 0;
		while( p!=NULL ){
			pt[len] = p;  word_len[len++] = strlen(p);
			p = strtok(NULL, " ");
		}
		/* dp solution */
		memset(dp, 127, sizeof(dp));	dp[len] = 0;
		for(i=len-1; i>=0; i--){
			for(j=i,k=word_len[j]; j<len; j++,k+=word_len[j]){
                /* try to put word[i]~word[j] in one line
                	since n<=80, the complexity is only BigO(MAXN*n) */
				if( (k+(j-i))>n ) break;
				m = dp[j+1] + ComputeBad(n-k, j-i);
				if( dp[i] >= m ){
					dp[i] = m;	path[i] = j+1;	space[i] = n-k;
				}
			}
		}
		/* Print Answer */
		for(i=0; i<len; i=path[i]){
			printf("%s", pt[i]);
			for(j=i+1,k=path[i]-i-1,m=space[i]; j<path[i]; j++,k--){
				n = m / k;  m -= n;
				while( --n )    putchar(' ');
				printf(" %s", pt[j]);
			}	putchar('\n');
		}   putchar('\n');
	}
	return 0;
}
