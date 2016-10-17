#include <stdio.h>
#include <string.h>

int dp[65536];
char rule[8][6];

int hash_value(char in[], int n){
	int i, j, k;
	for(i=0,j=1<<(n-1),k=0; i<n; i++,j>>=1)
	if( in[i]=='b' )	k += j;
	return k;
}

void change(char in[], int n){
	char tmp[20], a, b, c;	memcpy(tmp, in, 20);
	int i, j;
	for(i=0; i<n; i++){
		if(i<2)	a = tmp[i+n-2];
		else	a = tmp[i-2];
		b = tmp[i];
		if(i==n-1)	c = tmp[0];
		else		c = tmp[i+1];
		for(j=0; j<8; j++)
		if( a==rule[j][0] && b==rule[j][1] && c==rule[j][2] ){
			in[i] = rule[j][3];	break;
		}
	}
}

void hash_answer(int s, int n){
	char ans[40]={0};	int i, j, k, index = 0, hv = s;
	for(i=0,j=1<<(n-1); i<n; i++,j>>=1)
	if( s >= j )	ans[i] = ans[i+n] = 'b', s -=j;
	else			ans[i] = ans[i+n] = 'a';

	for(i=1; i<n; i++){
		for(j=0,k=1<<(n-1),s=0; j<n; j++,k>>=1)
		if( ans[i+j]=='b' )	s += k;
		if( s < hv )		hv = s, index = i;
	}
	for(j=0; j<n; j++)	putchar(ans[index+j]);
	putchar('\n');
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	
	int n, s, i, j, k;
	char in[20];
	while( scanf("%d", &n)!=EOF ){
		scanf("%s", in);
		for(i=0; i<8; i++)	scanf("%s", rule[i]);
		scanf("%d", &s);
		memset(dp, -1, sizeof(dp));	j = 0;
		k = hash_value(in,n);	dp[k] = 0;
		while( j++ < s ){
			change(in,n);
			k = hash_value(in,n);
			if( dp[k]!=-1 )	break;
			else			dp[k] = j;
		}
		if( j > s )	i = k;
		else{
			i = j - dp[k];
			j = dp[k] + (s-dp[k])%i;
			for(i=0; i<65536; i++)	if( dp[i]==j )	break;
		}
		hash_answer(i,n);
	}
	return 0;
}

