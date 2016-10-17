#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define MAXN 25

struct OP{
	int index_a, index_b, op;
	OP(){};
	OP(int a, int b):index_a(a), index_b(b){};
};

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
OP path[MAXN][MAXN];

int ComputeMax(int lena, int lenb, int sta, int stb){
	int cnt=0, add=(lena>lenb)?(lena-lenb):(lenb-lena);
	for(int i=sta,j=stb; i<lena && j<lenb; i++,j++)
	if( a[i]!=b[i] )	cnt++;
	return cnt+add;
}

int ComputeSkip(int lena, int lenb, int sta, int stb){
	int cnt = 0;
	for(int i=sta,j=stb; i<lena && j<lenb; i++,j++)
	if( a[i]==b[j] )    cnt++;
	else                break;
	return cnt;
}

void SolveDP(int lena, int lenb, int maxt){
	int dx[4]={0,1,1,0}, dy[4]={0,1,0,1}/*, inque[MAXN][MAXN]={{0}}*/;
	queue<OP> que;	que.push(OP(0,0));
	for(int i=0; i<=lena; i++)for(int j=0; j<=lenb; j++)    dp[i][j] = maxt;
	dp[0][0] = 0;
    while( !que.empty() ){
		OP now = que.front();   que.pop();  int skip = 0;
		//inque[now.index_a][now.index_b] = 0;
		if( now.index_a>lena || now.index_b>lenb )    continue;
		if( a[now.index_a]==b[now.index_b] ){
            skip = ComputeSkip(lena, lenb, now.index_a, now.index_b);
			dx[0] = skip;   dy[0] = skip;
		}
		for(int i=(skip)?(0):(1); i<=3; i++){
            /* i=0, skip to next mutually different characters */
            /* i=1, change a[index_a] to b[index_b] */
			/* i=2, delete a[index_a] */
			/* i=3, insert b[index_b] to a[index_a] */
			OP tmp(now.index_a+dx[i], now.index_b+dy[i]);
			int tmpd = (i)?(dp[now.index_a][now.index_b]+1):(dp[now.index_a][now.index_b]);
			if( dp[tmp.index_a][tmp.index_b] > tmpd ){
                dp[tmp.index_a][tmp.index_b] = tmpd;
                //printf("%d %d %d\n", tmp.index_a,tmp.index_b,tmpd);
				path[tmp.index_a][tmp.index_b] = now;
				path[tmp.index_a][tmp.index_b].op = (i)?(i):(-skip);
				que.push(tmp);
                /*if( !inque[tmp.index_a][tmp.index_b] ){
					que.push(tmp);  inque[tmp.index_a][tmp.index_b] = 1;
                }*/
			}
		}
    }
}

int PrintAns(int lena, int lenb){   /* return number of deletion */
	if( (lena+lenb) ){
		int op = path[lena][lenb].op, del;
		if( op < 0 )		del = PrintAns(lena+op, lenb+op);
		else if( op==1 )    del = PrintAns(lena-1, lenb-1);
		else if( op==2 )    del = PrintAns(lena-1, lenb);
		else				del = PrintAns(lena, lenb-1);
		/*printf(" %d %d %d\n", lena, lenb, op);*/
		if( op==1 )         printf("C%c%02d", b[lenb-1], lena-del);
		else if( op==2 )    {printf("D%c%02d", a[lena-1], lena-del); del++;}
		else if( op==3 )    {printf("I%c%02d", b[lenb-1], lena+1-del); del--;}
		return del;
	}
	else return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int lena, lenb, maxt;
	while( scanf("%s", a) && a[0]!='#' ){
		scanf("%s", b);
		lena = strlen(a);   lenb = strlen(b);
		maxt = ComputeMax(lena,lenb,0,0);
		SolveDP(lena, lenb, maxt+1);
		PrintAns(lena, lenb);   puts("E");
		/*for(int i=0; i<=lena; i++){
			for(int j=0; j<=lenb; j++)  printf("%3d", dp[i][j]);
			putchar('\n');
		}*/
	}
	return 0;
}
