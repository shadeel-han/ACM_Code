#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 18

char word[SIZE][SIZE], w[SIZE];
int mask[SIZE], MASK;
long long int cnt[SIZE], ans;

void WordInput(int n){
	int i, j, k;
	memset(mask, 0, sizeof(mask));  MASK = (1<<n)-1;
	/*memset(dp_mask, 0, sizeof(dp_mask));*/
	for(i=0; i<n; i++){
		scanf("%s", word[i]);
		if( word[i][0]=='?' ){
			for(j=0; j<n; j++)	word[i][j] = j;
			word[i][n] = -1;	cnt[i] = n; mask[i] = MASK;
		}
		else{
            for(j=0,k=strlen(word[i]); j<k; j++)if(isupper(word[i][j])){
				word[i][j] -= 'A';  mask[i] |= (1<<word[i][j]);
            }
			word[i][k] = -1;	cnt[i] = k;
		}
	}
	for(i=n-2; i>=0; i--){
		cnt[i] *= cnt[i+1]; mask[i] |= mask[i+1];
	}
}

void backtrace(int index, int end, int m, int m_add, int m_sub){
	if( index==end ){
		ans++;	return;
	}
	if( (m|mask[index])!=MASK )  return;
	
	int i, j, k, tmp[SIZE];
	for(i=0; word[index][i]>(-1); i++){
		w[index] = word[index][i];
		/* rule 1 */
		if( m & (1<<w[index]) )	continue;
		/* rule 2 */
		if( m_add & (1<<(w[index]+index)) )		continue;
		if( m_sub & (1<<(15+w[index]-index)) )	continue;
		/* rule 3 */
		if( index>=1 && abs(w[index-1]-w[index])==2 ){
            continue;
		}
		/* rule 4 */
		if( index>=2 && abs(w[index-2]-w[index])==1 ){
            continue;
		}
		backtrace(index+1, end, m|(1<<w[index]), m_add|(1<<(w[index]+index)), m_sub|(1<<(15+w[index]-index)));
		/*memcpy(dp_mask, tmp, sizeof(tmp));*/
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, c=0, i;
	while( scanf("%d", &n) && n ){
		WordInput(n);
		ans = 0;
		backtrace(0,n,0,0,0);
		printf("Case %d: %I64d\n", ++c, cnt[0]-ans);
	}
	return 0;
}
