#include <stdio.h>
#include <string.h>

#define MAXN 62501

int sta[MAXN], a[MAXN], b[MAXN];

void Input(int p, int q){   /* change LCS to LIS */
	int i, tmp;
	memset(a, -1, sizeof(a));
	for(i=0; i<=p; i++){
		scanf("%d", &tmp);  a[tmp] = i;
	}
	for(i=0; i<=q; i++){
        scanf("%d", &tmp);  b[i] = a[tmp];
	}
}

int BinarySearch(int start, int end, int val){
	int low=start, up=end, mid;
	while( low!=up ){
        mid = (low+up)>>1;
		if( sta[mid] >= val )	up = mid;
		else                    low = mid + 1;
	}
	return low;
}

int Solve(int q){
	int i, num = 0, pos;
	sta[0] = 0;
	for(i=1; i<q; i++)if( b[i]>0 ){ /* b[i]==-1, b[i] doesn't appear in a */
        if( b[i] > sta[num] ){
			sta[++num] = b[i];
		}else{
            pos = BinarySearch(0, num, b[i]);
            sta[pos] = b[i];
        }
	}
	return (num+2);
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int c=0, cas, n, p, q;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d %d %d", &n, &p, &q);
		Input(p,q);
		printf("Case %d: %d\n", ++c, Solve(q));
	}
	return 0;
}
