#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct TRIE{
    bool ac;
    int fail;
    int go[4];
};
int ind; // trie node counter
TRIE trie[1000];
char in[1005];
char pat[50][25];
int dp[1000][1000];

int trans( char in ){
    switch(in){
        case 'A':   return 0;
        case 'C':   return 1;
        case 'G':   return 2;
        case 'T':   return 3;
    }
}

void trie_build(int num){
    
    int i, j, k, len, now, tmp;
    
    for( i=0; i<4; ++i )
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
                for( k=0; k<4; ++k )
                    trie[now].go[k] = 0;
            }
        }
        trie[now].ac = true;
    }
}

void bfs_build_failure( int source ){
    
    int i, j, now, tmp;
    queue<int> que;
    for( i=0; i<4; ++i )
        if( trie[source].go[i] )
            que.push(trie[source].go[i]);
    while( !que.empty() ){
        now = que.front();
        que.pop();
        for( i=0; i<4; ++i )
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


int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int i, j, k, num, len, tt, tmp, c=0;
    
    while( scanf("%d", &num) ){
        
        if( !num )  break;
        
        for( i=0; i<num; ++i )
            scanf("%s", pat[i]);
        scanf("%s", in);
        
        trie_build(num);
        bfs_build_failure(0);
        
        len = strlen(in);
        memset(dp,-1,sizeof(dp));
        j = trans(in[0]);
        for( i=0; i<4; ++i )
            if( !trie[trie[0].go[i]].ac ){
                if( i==j )  tt = 0;
                else        tt = 1;
                if( dp[0][trie[0].go[i]]==-1 || dp[0][trie[0].go[i]>tt] )
                    dp[0][trie[0].go[i]] = tt;
            }
        for( i=1; i<len; ++i ){
            num = trans(in[i]);
            for( j=0; j<ind; ++j )
                // if possibly reach this state at ith character
                if( dp[i-1][j]!=-1 ){
                    for( k=0; k<4; ++k ){
                        if( !trie[j].go[k] ){
                            tmp = trie[j].fail;
                            while( tmp && !trie[tmp].go[k] )
                                tmp = trie[tmp].fail;
                            tmp = trie[tmp].go[k];
                        }
                        else    tmp = trie[j].go[k];
                        
                        if( trie[tmp].ac )  continue;
                        if( k==num )    tt = 0;
                        else            tt = 1;
                        if( dp[i][tmp]==-1 || (dp[i][tmp]>dp[i-1][j]+tt) )
                            dp[i][tmp] = dp[i-1][j] + tt;
                    }
                }
        }
        
        for( i=0,j=10000,k=len-1; i<ind; ++i )
            if( dp[k][i]!=-1 && dp[k][i]<j )
                j = dp[k][i];
        if( j==10000 )  printf("Case %d: -1\n", ++c);
        else            printf("Case %d: %d\n", ++c, j);
        
    }
    
    return 0;
}
