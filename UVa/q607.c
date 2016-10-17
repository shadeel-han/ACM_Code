#include <stdio.h>
#include <string.h>

#define MAXN 1001
#define INF 2139062143
typedef struct{
	int lecture, minute, dissa;
}DP;

int topic[MAXN], num[MAXN], dp[MAXN][501];
DP st[MAXN][MAXN], need[MAXN];

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, n, L, C, i, j, k, minlec, tmplec, tmpmin, tmpdis;
	memset(dp, 127, sizeof(dp));
	st[0][0].lecture = st[0][0].minute = st[0][0].dissa = 0;
	while( scanf("%d", &n) && n ){
        scanf("%d %d", &L, &C);
        for(i=1,minlec=0,j=0; i<=n; i++){
			scanf("%d", &topic[i]);
			j += topic[i];
			if( j > L ){
				j = topic[i];    minlec++;
			}
        }
        need[n].lecture = 0;    need[n].minute = topic[n];
        for(i=n-1; i; i--){
			need[i].minute = need[i+1].minute + topic[i];
			if( need[i].minute > L ){
                need[i].minute = topic[i];
				need[i].lecture = need[i+1].lecture + 1;
			} else
				need[i].lecture = need[i+1].lecture;
        }
		/* dp solution */
		memset(num, 0, sizeof(num));	num[0] = 1;
		for(i=0; i<n; i++){
			for(j=0; j<num[i]; j++){
				k = st[i][j].lecture + need[i+1].lecture;
				/* this schedule results in more lecture */
				if( (k>minlec) || ((k==minlec)&&(st[i][j].minute+need[i+1].minute>L)) )	continue;
				
				tmpmin = st[i][j].minute + topic[i+1];
				/* try to add topic after all possible consuming time */
				if( tmpmin <= L ){
					tmplec = st[i][j].lecture;	tmpdis = st[i][j].dissa;
					if( dp[tmplec][tmpmin]==INF ){
						st[i+1][num[i+1]].lecture = tmplec;	st[i+1][num[i+1]].minute = tmpmin;
						num[i+1]++;	dp[tmplec][tmpmin] = tmpdis;
					}
					else if( dp[tmplec][tmpmin] > tmpdis )  dp[tmplec][tmpmin] = tmpdis;
				}
				/* start a new lecture at this topic */
                tmpmin = topic[i+1];	tmplec = st[i][j].lecture + 1;
                if( st[i][j].minute==L )    		tmpdis = st[i][j].dissa;
                else if( L-st[i][j].minute<=10 )    tmpdis = st[i][j].dissa - C;
                else	k = L-st[i][j].minute-10,	tmpdis = st[i][j].dissa + k*k;
                if( dp[tmplec][tmpmin]==INF ){
					st[i+1][num[i+1]].lecture = tmplec;	st[i+1][num[i+1]].minute = tmpmin;
					num[i+1]++;	dp[tmplec][tmpmin] = tmpdis;
				}
				else if( dp[tmplec][tmpmin] > tmpdis )  dp[tmplec][tmpmin] = tmpdis;
			}
			for(j=0; j<num[i+1]; j++){
                st[i+1][j].dissa = dp[st[i+1][j].lecture][st[i+1][j].minute];
                dp[st[i+1][j].lecture][st[i+1][j].minute] = INF;
			}
		}
		/* find answer at st[n] */
		for(i=0,j=INF; i<num[n]; i++){
			if( st[n][i].lecture > minlec ) continue;
			if( st[n][i].minute==L )    		tmpdis = st[n][i].dissa;
            else if( L-st[n][i].minute<=10 )    tmpdis = st[n][i].dissa - C;
            else	k = L-st[n][i].minute-10,	tmpdis = st[n][i].dissa + k*k;
			if( j > tmpdis )	j = tmpdis;
		}
		if( c++ ) putchar('\n');
		printf("Case %d:\nMinimum number of lectures: %d\nTotal dissatisfaction index: %d\n", c, minlec+1, j);
	}
	return 0;
}
