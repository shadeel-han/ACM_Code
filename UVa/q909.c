#include <stdio.h>
#include <string.h>

#define MAXN 10001

char input[MAXN];
int dp[MAXN], path[MAXN];

int RecursiveDP(int start, int end){
	if( dp[start] )		return dp[start];
	if( start==end )	return 0;
	
	int i, j, a, ans=2000, ans_index;
	/* n=0~127 */
	for(i=start, j=0; i<end && j<=127; i++, j++){
		a = j + 2 + RecursiveDP(i+1, end);
		if( a < ans ){
			ans = a;    ans_index = j;
		}
	}
	/* n=129~255 */
	for(i=start+1, j=129; i<end && input[i]==input[start] && j<=255; i++, j++){
		a = 2 + RecursiveDP(i+1, end);
		if( a < ans ){
			ans = a;    ans_index = j;
		}
	}
	path[start] = ans_index;
	return dp[start] = ans;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j, len = 0;
	/*while( scanf("%s", input)!=EOF )*/
	while((input[len] = getchar()) != EOF)  /* this problem's input is odd because some strange ascii codes */
		++len;
	{
		/*len = strlen(input);*/
		memset(dp, 0, sizeof(dp));
		RecursiveDP(0, len);
		i = 0;
		while( i!=len ){
			if( path[i] < 128 ){
				printf("%c", path[i]);
				for(j=0; j<=path[i]; j++)   printf("%c", input[i+j]);
				i += (path[i]+1);
			}else{
                printf("%c%c", path[i], input[i]);
                i += (path[i]-127);
			}
		}
	}
	return 0;
}
