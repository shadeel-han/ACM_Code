#include <cstdio>
#include <string>
#include <map>

using namespace std;
#define MAXN 101

map<string,int> hash_to_num;
map<int,string> hash_to_word;
int hash_num, word_num[2], text[2][MAXN], dp[MAXN][MAXN]={0};
int pi[MAXN][MAXN]; // for direction, 0:up, 1:left, 2:up-left

bool Input(void){
    char in[35];
    if( scanf("%s", in)==EOF )  return false;
    word_num[0] = word_num[1] = 0;	hash_num = 0;
    hash_to_word.clear();   hash_to_num.clear();
	do{
		string str(in);
		if( hash_to_num.find(str)==hash_to_num.end() ){
            hash_to_num[str] = ++hash_num;
            hash_to_word[hash_num] = str;
		}
		text[0][++word_num[0]] = hash_to_num[str];
		scanf("%s", in);
	}while( in[0]!='#' );
	scanf("%s", in);
	do{
		string str(in);
		if( hash_to_num.find(str)==hash_to_num.end() ){
            hash_to_num[str] = ++hash_num;
            hash_to_word[hash_num] = str;
		}
		text[1][++word_num[1]] = hash_to_num[str];
		scanf("%s", in);
	}while( in[0]!='#' );
	return true;
}

void PrintAns(int a, int b){
	if( a && b ){
		if( pi[a][b]==0 )   	PrintAns(a-1,b);
		else if( pi[a][b]==1 )  PrintAns(a,b-1);
		else{
            PrintAns(a-1,b-1);
            if( dp[a][b]==1 )	printf("%s", hash_to_word[text[0][a]].c_str());
            else                printf(" %s", hash_to_word[text[0][a]].c_str());
		}
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	while( Input() ){
        //memset(dp, 0, sizeof(dp));
		for(int i=1; i<=word_num[0]; i++)for(int j=1; j<=word_num[1]; j++){
			if( text[0][i]==text[1][j] )		dp[i][j] = dp[i-1][j-1] + 1, pi[i][j] = 2;
			else if( dp[i-1][j] > dp[i][j-1] )	dp[i][j] = dp[i-1][j], pi[i][j] = 0;
			else                                dp[i][j] = dp[i][j-1], pi[i][j] = 1;
		}
		PrintAns(word_num[0], word_num[1]); putchar('\n');
	}
	return 0;
}
