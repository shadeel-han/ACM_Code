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
TRIE trie[100];
char pat[10][15];
int val[31];
long long int matrix[31][100][100], ans[100], cal[100];

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
    
    int i, j, k, m, n, num, len, tmp;
    
    for( i=0,j=1; i<31; ++i,j<<=1 )
        val[i] = j;
    
    while( scanf("%d %d", &num, &len)!=EOF ){
        
        for( i=0; i<num; ++i )
            scanf("%s", pat[i]);
        
        trie_build(num);
        bfs_build_failure(0);
        memset(matrix,0,sizeof(matrix));
        for( i=0; i<ind; ++i ){
            if( trie[i].ac )    continue;
            for( j=0; j<4; ++j ){
                if( !trie[i].go[j] ){
                    tmp = trie[i].fail;
                    while( tmp && !trie[tmp].go[j] )
                        tmp = trie[tmp].fail;
                    tmp = trie[tmp].go[j];
                }
                else    tmp = trie[i].go[j];
                
                if( trie[tmp].ac )  continue;
                ++matrix[0][i][tmp];
            }
        }
        for( i=1; i<31 && val[i]<=len; ++i ){
            tmp = i - 1;
            for( j=0; j<ind; ++j )
                for( k=0; k<ind; ++k ){
                    for( m=0; m<ind; ++m )
                        matrix[i][j][k] += (matrix[tmp][j][m] * matrix[tmp][m][k]);
                    matrix[i][j][k] %= 100000;
                }
        }
        for( j=0; j<ind; ++j ){
            ans[j] = 0;
            cal[j] = 0;
        }
        ans[0] = 1;
        --i;
        while( len ){
            if( val[i] > len ){
                --i;
                continue;
            }
            len -= val[i];
            for( j=0; j<ind; ++j )
                for( k=0; k<ind; ++k )
                    cal[j] += (ans[k] * matrix[i][k][j]);
            for( j=0; j<ind; ++j ){
                ans[j] = cal[j] % 100000;
                cal[j] = 0;
            }
        }
        
        for( i=0,j=0; i<ind; ++i )
            j = (j+ans[i]) % 100000;
        printf("%d\n", j);
    }
    
    return 0;
}
