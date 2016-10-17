/*
ID: j9010311
PROG: calfflac
LANG: C++
*/

#include <cstdio>
#include <cctype>

using namespace std;

typedef struct{
    int num;
    char word;
}FILEIN;
FILEIN in[20252], tran[20252];

int main(){
    
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    
    int i, j=0, k, len, maxx, start, end, tmp;

    while( scanf("%c", &in[j].word)!=EOF ){
        in[j].num = j++;
    }
    
    for( i=0,len=0; i<j; ++i )
        if( isalpha(in[i].word) ){
            tran[len] = in[i];
            if( in[i].word < 'a' )
                tran[len].word += ('a'-'A');
            ++len;
        }
    
    for( i=1,maxx=1,start=0,end=0; i<len; ++i ){
        
        /* i-th character as the middle */
        for( j=i-1,k=i+1; j>=0; --j,++k )
            if( tran[j].word!=tran[k].word )
                break;
        tmp = k-j-1;
        if( tmp > maxx ){
            maxx = tmp;
            start = tran[j+1].num;
            end = tran[k-1].num;
        }
        /* i-th and i+1-th character as the middle */
        for( j=i,k=i+1; j>=0; --j,++k )
            if( tran[j].word!=tran[k].word )
                break;
        tmp = k-j-1;
        if( tmp > maxx ){
            maxx = tmp;
            start = tran[j+1].num;
            end = tran[k-1].num;
        }
    }
    
    printf("%d\n", maxx);
    for( i=start; i<=end; ++i )
        printf("%c", in[i].word);
    putchar('\n');
    
    return 0;
}
