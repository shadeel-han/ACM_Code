#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct COOR{
	int a, b;
	COOR() {};
	COOR(int a, int b):a(a),b(b) {};
	COOR operator+(const COOR& x){
		return COOR(a+x.a, b+x.b);
	}
};

COOR dp[1001][1001];

COOR traverse(int ca, int cb, int n){
	queue<COOR> que;
	
	que.push(COOR(0,0));
	while( !que.empty() ){
		COOR now = que.front(); que.pop();
		for(int i=0; i<6; ++i){
			COOR tmp = now;
			switch(i){
				case 0:	// fill ca
				    if( now.a < ca )	tmp.a = ca;
					break;
				case 1: // fill cb
				    if( now.b < cb )	tmp.b = cb;
					break;
                case 2: // empty ca
                    if( now.a ) tmp.a = 0;
					break;
                case 3: // empty cb
                	if( now.b ) tmp.b = 0;
					break;
                case 4: // pour a to b
                    if( now.a && now.b < cb ){
						if( (cb-now.b) > now.a ){
							tmp.a = 0;	tmp.b += now.a;
						} else{
							tmp.a -= (cb-now.b);	tmp.b = cb;
						}
					}
					break;
                case 5: // pour b to a
                    if( now.b && now.a < ca ){
						if( (ca-now.a) > now.b ){
							tmp.b = 0;	tmp.a += now.b;
						} else{
							tmp.b -= (ca-now.a);	tmp.a = ca;
						}
					}
					break;
			}
			if( dp[tmp.a][tmp.b].a == -1 ){
                dp[tmp.a][tmp.b] = now;
				que.push(tmp);
			}
			if( tmp.a==n || tmp.b==n )  return tmp;
		}
	}
}

void PrintAns(COOR get){
	if( !get.a && !get.b )  return ;
	COOR pre = dp[get.a][get.b];
	PrintAns(pre);
	if( get.a == pre.a ){
		if( get.b < pre.b ) puts("empty B");
		else                puts("fill B");
	}else if( get.b == pre.b ){
		if( get.a < pre.a ) puts("empty A");
		else                puts("fill A");
	}else if( get.a > pre.a )   puts("pour B A");
	else                        puts("pour A B");
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int ca, cb, n;
	while( scanf("%d %d %d", &ca, &cb, &n)!=EOF ){
		memset(dp,-1,sizeof(dp));
		COOR get = traverse(ca,cb,n);
		PrintAns(get);
		puts("success");
	}
	return 0;
}
