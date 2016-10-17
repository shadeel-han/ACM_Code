#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct TRIE{
    bool ac;
    int fail;
    int go[50];
};
int ind, alnum; // trie node counter
TRIE trie[500];
char pat[10][55], alpha[50];
char dp[51][500][90]; // the answer need to use BigInteger

char trans( char in ){
    for( char i=0; i<alnum; ++i )
    if( alpha[i]==in )  return i;
}

void trie_build(int num){
    
    int i, j, k, len, now, tmp;
    
    for( i=0; i<alnum; ++i )
        trie[0].go[i] = 0;
    trie[0].ac = false;
    trie[0].fail = 0;
    ind = 1;
    for( i=0; i<num; ++i ){
        len = strlen(pat[i]);
        now = 0;
        for( j=0; j<len; ++j ){
            tmp = trans( pat[i][j] );
            if( trie[now].go[tmp] )   now = trie[now].go[tmp];
            else{
                trie[now].go[tmp] = ind;
                now = ind++;
                trie[now].fail = 0;
                trie[now].ac = false;
                for( k=0; k<alnum; ++k )
                    trie[now].go[k] = 0;
            }
        }
        trie[now].ac = true;
    }
}

void bfs_build_failure(){
    
    int i, j, now, tmp;
    queue<int> que;
    for( i=0; i<alnum; ++i )
        if( trie[0].go[i] )
            que.push(trie[0].go[i]);
    while( !que.empty() ){
        now = que.front();
        que.pop();
        for( i=0; i<alnum; ++i )
            if( trie[now].go[i] ){
                que.push(trie[now].go[i]);
                tmp = trie[now].fail;
                while( tmp && !trie[tmp].go[i] )
                    tmp = trie[tmp].fail;
                trie[trie[now].go[i]].fail = trie[tmp].go[i];
                // for example, AACCT ACC AC should carefully set in the substring situation
                if( trie[trie[tmp].go[i]].ac )  trie[trie[now].go[i]].ac = true;
            }
    }
}

bool test_value( char in[90] ){
    for( int i=0; i<90; ++i )
    if( in[i] )   return true;
    return false;
}

int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int i, j, k, m, num, len, tmp;
    char ans[90];
    
    while( scanf("%d %d %d", &alnum, &len, &num)!=EOF ){
        
        scanf("%s", alpha);
        for( i=0; i<num; ++i )
            scanf("%s", pat[i]);
        
        trie_build(num);
        bfs_build_failure();
        
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        for( i=1; i<=len; ++i )
            for( j=0; j<ind; ++j )
            if( test_value(dp[i-1][j]) ){
                for( k=0; k<alnum; ++k ){
                    if( !trie[j].go[k] ){
                        tmp = trie[j].fail;
                        while( tmp && !trie[tmp].go[k] )
                            tmp = trie[tmp].fail;
                        tmp = trie[tmp].go[k];
                    }
                    else    tmp = trie[j].go[k];
                    
                    if( trie[tmp].ac )  continue;
                    // biginteger addition
                    for( m=0; m<90; ++m ){
                        dp[i][tmp][m] += dp[i-1][j][m];
                        if( dp[i][tmp][m]>9 ){
                            dp[i][tmp][m] -= 10;
                            ++dp[i][tmp][m+1];
                        }
                    }
                    
                }
            }
        
        memset(ans,0,sizeof(ans));
        for( i=0; i<ind; ++i )
            for( j=0; j<90; ++j ){
                ans[j] += dp[len][i][j];
                if( ans[j]>9 ){
                    ans[j] -= 10;
                    ++ans[j+1];
                }
            }
        if( !test_value(ans) )  puts("0");
        else{
            for( i=89; i>=0; --i )
            if( ans[i] )    break;
            for( i; i>=0; --i )
                printf("%c", '0'+ans[i]);
            putchar('\n');
        }
    }
    
    return 0;
}
