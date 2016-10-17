#include <stdio.h>

int p[50001], rank[50001];

void MakeSet(int x)
{
	p[x] = x;
	rank[x] = 0;
} 

void Link(int x,int y)
{
    if(rank[x]>rank[y])
        p[y] = x;
    else{
        p[x] = y;
        if(rank[x]==rank[y])
            rank[y]++;
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

int main(){
    int peo, rel, i, a, b, count=0;
    while( scanf("%d %d", &peo, &rel) ){
        if( !peo )
            break;
        for( i=1; i<=peo; i++ )
            MakeSet(i);
        for( i=0; i<rel; i++ ){
            scanf("%d %d", &a, &b);
            Union(a,b);
        }
        a = 0;
        for( i=1; i<=peo; i++ )
            if( i==p[i] )
                a++;
        printf("Case %d: %d\n", ++count, a);
    }
    return 0;
}
