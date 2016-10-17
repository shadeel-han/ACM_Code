#include <cstdio>
#include <vector>

using namespace std;

vector<int> child[10001];
int box[10001], ans;

int Input(int n){
	ans = 0;
	bool root[10001]={0};
	for(int i=1; i<=n; ++i){
		int now, ball, m;
		scanf("%d%d", &now, &ball); box[now] = ball;
		scanf("%d", &m);
		child[i].clear();
		for(int j=0; j<m; ++j){
            scanf("%d", &ball);
            child[now].push_back(ball);
            root[ball] = true;
		}
	}
	for(int i=1; i<=n; ++i)
	if( !root[i] )  return i;
}

int DFSTraverse(int r){ // return value>0 means pushing upeards, <0 means downward
	int sum = box[r]-1;
	for(int i=0,j=child[r].size(); i<j; ++i)
		sum += DFSTraverse(child[r][i]);
	ans += (sum>=0)?(sum):(-sum);
	return sum;
}

int main(void){
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while( scanf("%d", &n) && n!=0 ){
		int root = Input(n);
		DFSTraverse(root);
		printf("%d\n", ans);
	}
	return 0;
}
