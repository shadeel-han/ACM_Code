#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct TRIE{
    int ac;
    int fail;
    int go[26];
};
int ind, row, col; // trie node counter
TRIE trie[100000];
char pat[1001][1005], in[1000][1005];
int ansx[1001], ansy[1001], ansd[1001];

char trans( char in ){
    return (in-'A');
}

void trie_build(int num){
    
    int i, j, k, len, now, tmp;
    
    for( i=0; i<26; ++i )
        trie[0].go[i] = 0;
    trie[0].ac = 0;
    trie[0].fail = 0;
    ind = 1;
    for( i=1; i<=num; ++i ){
        len = strlen(pat[i]);
        now = 0;
        for( j=0; j<len; ++j ){
            tmp = trans( pat[i][j] );
            if( trie[now].go[tmp] )   now = trie[now].go[tmp];
            else{
                trie[now].go[tmp] = ind;
                now = ind++;
                trie[now].fail = 0;
                trie[now].ac = 0;
                for( k=0; k<26; ++k )
                    trie[now].go[k] = 0;
            }
        }
        trie[now].ac = i;
    }
}

void bfs_build_failure( int source ){
    
    int i, j, now, tmp;
    queue<int> que;
    for( i=0; i<26; ++i )
        if( trie[source].go[i] )
            que.push(trie[source].go[i]);
    while( !que.empty() ){
        now = que.front();
        que.pop();
        for( i=0; i<26; ++i )
            if( trie[now].go[i] ){
                que.push(trie[now].go[i]);
                tmp = trie[now].fail;
                while( tmp && !trie[tmp].go[i] )
                    tmp = trie[tmp].fail;
                trie[trie[now].go[i]].fail = trie[tmp].go[i];
                // for example, AACCT ACC AC should carefully set in the substring situation
                if( trie[trie[tmp].go[i]].ac && !trie[trie[now].go[i]].ac )
                    trie[trie[now].go[i]].ac = trie[trie[tmp].go[i]].ac;
            }
    }
}

void search( int startx, int starty ){
    
    int y[8]={0,1,1,1,0,-1,-1,-1}, x[8]={-1,-1,0,1,1,1,0,-1};
    int i, j, k, now, tmp, indx, indy;
    
    for( k=0; k<8; ++k ){
        now = 0;
        indx = startx;
        indy = starty;
        do{
            i = trans(in[indx][indy]);
            if( !trie[now].go[i] ){
                while( now && !trie[now].go[i] )
                    now = trie[now].fail;
            }
            now = trie[now].go[i];
            indx += x[k];
            indy += y[k];
            
            if( trie[now].ac ) {
                tmp = now;
                while( tmp ){
                    // find the indicating word
                    if( trie[tmp].ac ){
                        j = strlen(pat[trie[tmp].ac]);
                        ansx[trie[tmp].ac] = indx - j*x[k];
                        ansy[trie[tmp].ac] = indy - j*y[k];
                        ansd[trie[tmp].ac] = k;
                        trie[tmp].ac = 0;
                    }
                    tmp = trie[tmp].fail;
                }
            }
        }while( indx<row && indy<col && indx>=0 && indy>=0 );
    }
    
}

int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int i, j, k, m, n, num, len, tmp;
    
    while( scanf("%d %d %d", &row, &col, &num)!=EOF ){
        
        for( i=0; i<row; ++i )
            scanf("%s", in[i]);
        for( i=1; i<=num; ++i )
            scanf("%s", pat[i]);
        
        trie_build(num);
        bfs_build_failure(0);
        
        // search from the border of  the puzzle
        for( i=0; i<col; ++i ){
            search(0,i);
            search(row-1,i);
        }
        for( i=1; i<row-1; ++i ){
            search(i,0);
            search(i,col-1);
        }
        
        for( i=1; i<=num; ++i )
            printf("%d %d %c\n", ansx[i], ansy[i], 'A'+ansd[i]);
        
    }
    
    return 0;
}
