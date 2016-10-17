/*
ID: j9010311
PROG: namenum
LANG: C++
*/

#include <cstdio>
#include <cstring>

char dic[5000][15];

using namespace std;

typedef struct{
    bool end;
    int way[26];
}TRIE;
TRIE trie[60000];
char in[14], ans[14]={0};
char word[10][4] = {{0},{0},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
int valid, limit;

bool initial_trie( int index ){
    trie[index].end = false;
    for( int i=0; i<26; ++i )
        trie[index].way[i] = 0;
}

void backtrack( int n, int index ){
    
    if( n == limit ){
        if( trie[index].end ){
            printf("%s\n", ans);
            ++valid;
        }
    }
    else{
        
        int i, get=in[n]-'0';
        for( i=0; i<3; ++i ){
            if( trie[index].way[word[get][i]-'A'] ){
                ans[n] = word[get][i];
                backtrack(n+1,trie[index].way[word[get][i]-'A']);
            }
        }
        ans[n] = 0;
        
    }
    
}

int main(){
    
    int i=0, j, k, num=1, len;
    
    FILE *fp = fopen("dict.txt","r");
    initial_trie(0);
    while( fscanf(fp, "%s", &dic[i])!=EOF ){
        len = strlen(dic[i]);
        for( j=0,k=0; k<len; ++k ){
            if( trie[j].way[dic[i][k]-'A'] )    j = trie[j].way[dic[i][k]-'A'];
            else{
                initial_trie(num);
                trie[j].way[dic[i][k]-'A'] = num;
                j = num++;
            }
        }
        trie[j].end = true;
        ++i;
    }
    fclose(fp);
    
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    
    while( scanf("%s", in)!=EOF ){
        
        len = strlen(in);
        
        for( i=0,j=0; i<len; ++i )
            if( in[i]=='0' || in[i]=='1' )
                ++j;
        if( j ){
            puts("NONE");
            continue;
        }
        
        limit = len;
        valid = 0;
        backtrack(0,0);
        if( !valid )
            puts("NONE");
        
    }
    
    return 0;
}
