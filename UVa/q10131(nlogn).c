#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int wei, iq, ind;
}ELE;

#define MAXN 1001
ELE ele[MAXN];
int path[MAXN], sta[MAXN];

int compare(const void* a, const void* b){
	ELE aa = *(ELE*)a, bb = *(ELE*)b;
	if( aa.wei != bb.wei )  return (aa.wei-bb.wei);
	else                    return (aa.iq-bb.iq);
}

int BinarySearch(int start, int end, int val){
	int low=start, up=end, mid;
	while( low!=up ){
        mid = (low+up)>>1;
		if( ele[sta[mid]].iq <= val )	up = mid;
		else                    		low = mid + 1;
	}
	return low;
}

void PrintAns(int n){
	if( n ){
        PrintAns(path[n]);
        printf("%d\n", ele[n].ind);
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n=1, i, num=0, pos;
	ele[0].wei = 0;	ele[0].iq = 10001;	sta[0] = 0;
	while( scanf("%d %d", &ele[n].wei, &ele[n].iq)!=EOF )
        ele[n].ind = n, n++;
	qsort(ele, n, sizeof(ELE), compare);

	for(i=1; i<n; i++){
		if( ele[i].iq < ele[sta[num]].iq ){
			pos = num;	sta[++num] = i;
		}else{
            pos = BinarySearch(0, num, ele[i].iq);
            sta[pos--] = i;
        }
        path[i] = sta[pos];
	}
	printf("%d\n", num);
	PrintAns(sta[num]);
	
	return 0;
}
