#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct TRIE{
    bool ac;
    int fail;
    int back;
    int go[52];
};
int ind=1;
TRIE trie[200000];
char in[100002];
char pat[1000][1002];

char trans( char in ){
    if( in<'a' )    return (in-'A');
    else            return (in-'a'+26);
}

void trie_build(int num){
    
    int i, j, k, len, now, tmp;
    
    trie[0].back = 0;
    for( i=0; i<52; ++i )
        trie[0].go[i] = 0;
    trie[0].ac = false;
    
    for( i=0; i<num; ++i ){
        len = strlen(pat[i]);
        now = 0;
        for( j=0; j<len; ++j ){
            tmp = trans( pat[i][j] );
            if( trie[now].go[tmp] )   now = trie[now].go[tmp];
            else{
                trie[now].go[tmp] = ind;
                trie[ind].back = now;
                now = ind++;
                trie[now].fail = 0;
                trie[now].ac = false;
                for( k=0; k<52; ++k )
                    trie[now].go[k] = 0;
            }
        }
        trie[now].ac = true;
    }
}

void bfs_build_failure( int source ){
    
    int i, j, now, tmp;
    queue<int> que;
    for( i=0; i<52; ++i )
        if( trie[source].go[i] ){
            que.push(trie[source].go[i]);
            trie[trie[source].go[i]].fail = 0;
        }
    while( !que.empty() ){
        now = que.front();
        que.pop();
        for( i=0; i<52; ++i )
            if( trie[now].go[i] ){
                que.push(trie[now].go[i]);
                tmp = trie[now].fail;
                while( tmp && !trie[tmp].go[i] )
                    tmp = trie[tmp].fail;
                if( trie[tmp].go[i] )   trie[trie[now].go[i]].fail = trie[tmp].go[i];
                else                    trie[trie[now].go[i]].fail = 0;
            }
    }
}

void match( int len ){
    
    int i, now=0, index=0, tmp;
    do{
        i = trans(in[index]);
        if( trie[now].go[i] ){
            ++index;
            now = trie[now].go[i];
        }
        else    now = trie[now].fail;
        
        if( trie[now].ac ) {
            trie[now].ac = false;
            tmp = now;
            while( tmp ){
                tmp = trie[tmp].fail;
                trie[tmp].ac = false;
            }
        }
        
    }while( now && index<len );
    
}

bool search( int source, int num, int len ){
    
    int i, now=source, index=0;
    while( index<len ){
        i = trans(pat[num][index]);
        now = trie[now].go[i];
        ++index;
    }
    return trie[now].ac;
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int i, j, cas, num;
    
    scanf("%d", &cas);
    while( cas-- ){
        scanf("%s", in);
        scanf("%d", &num);
        for( i=0; i<num; ++i )
            scanf("%s", pat[i]);
            
        trie_build(num);
        bfs_build_failure(0);
        
        match(strlen(in));
        
        for( i=0; i<num; ++i )
        if( !search(0,i,strlen(pat[i])) )   puts("y");
        else                                puts("n");
        
    }
    
    return 0;
}
