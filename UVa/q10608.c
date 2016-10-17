#include <stdio.h>
#include <stdlib.h>

int p[30001], rank[30001], group[30001];

void MakeSet(int x)
{
	p[x] = x;
	rank[x] = 0;
	group[x] = 1;
} 

void Link(int x,int y)
{
    if( x!=y ){
        if(rank[x]>rank[y]){
            p[y] = x;
            group[x] += group[y];
        }
        else{
            p[x] = y;
            group[y] += group[x];
            if(rank[x]==rank[y])
                rank[y]++;
        }
    }
}

void Union(int x,int y)
{
    Link(FindSet(x),FindSet(y));
}

int FindSet(int x)
{
    while(x!=p[x])
        x = FindSet(p[x]);
    return x;
}

int cmp(const void* a, const void* b ){
    return (*(int*)a - *(int*)b);
}

int main(){
    int tol, peo, rel, i, a, b;
    scanf("%d", &tol);
    while( tol-- ){
        scanf("%d %d", &peo, &rel);
        for( i=1; i<=peo; i++ )
            MakeSet(i);
        group[0] = 0;
        for( i=0; i<rel; i++ ){
            scanf("%d %d", &a, &b);
            Union(a,b);
        }
        qsort(group,peo+1,sizeof(int),cmp);
        printf("%d\n", group[peo]);
    }
    return 0;
}
