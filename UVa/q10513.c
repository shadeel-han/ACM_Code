#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 18

char word[SIZE][SIZE], w[SIZE];
char bang_seq[SIZE][33000][SIZE];   /*the number of bang_seq of length 15 is 32516*/
int seq_num[SIZE]={0};
long long int tol;

void WordInput(int n){
	int i, j, k;
	memset(word, 0, sizeof(word));	char tmp[SIZE];
	for(i=0; i<n; i++){
		scanf("%s", tmp);
		if( tmp[0]=='?' ){
            memset(word[i], 1, sizeof(word[i]));
			tol *= n;
		}
		else{
            for(j=0,k=strlen(tmp); j<k; j++)
			if(isupper(tmp[j]))	word[i][tmp[j]-'A'] = 1;
			tol *= k;
		}
	}
}

void backtrace(int index, int end, int m, int m_add, int m_sub){
	if( index==end ){
		memcpy(bang_seq[end][seq_num[end]], w, sizeof(w));
		seq_num[end]++;	return;
	}

	int i, j;
	for(i=0; i<end; i++){
		w[index] = i;
		/* rule 1 */
		if( m & (1<<w[index]) )	continue;
		/* rule 2 */
		if( m_add & (1<<(w[index]+index)) )		continue;
		if( m_sub & (1<<(15+w[index]-index)) )	continue;
		/* rule 3 */
		if( index>=1 && abs(w[index-1]-w[index])==2 )	continue;
		/* rule 4 */
		if( index>=2 && abs(w[index-2]-w[index])==1 )	continue;
		backtrace(index+1, end, m|(1<<w[index]), m_add|(1<<(w[index]+index)), m_sub|(1<<(15+w[index]-index)));
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, c=0, i, j;
	for(i=1; i<16; i++)	backtrace(0,i,0,0,0);
	while( scanf("%d", &n) && n ){
		tol = 1;
		WordInput(n);
		for(i=0; i<seq_num[n]; i++){
			for(j=0; j<n; j++)
			if( !word[j][bang_seq[n][i][j]] )	break;
			if( j==n )   tol--;
		}
		printf("Case %d: %lld\n", ++c, tol);
	}
	return 0;
}
