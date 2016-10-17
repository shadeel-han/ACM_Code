/*
ID: j9010311
PROG: clocks
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    char word[9];
    vector<char> pro;
}DIAL;

/* record the appearance of the dial condition */
bool use[1048573];
queue<DIAL> store;

int main(){
    
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    
    DIAL tmp, now;
    bool notfound;
    int i, j, cal;
    int num[10] = {0,4,3,4,3,5,3,4,3,4};
    int move[10][5]={{0},{0,1,3,4,0},{0,1,2,0,0},{1,2,4,5,0},{0,3,6,0,0},{1,3,4,5,7},{2,5,8,0,0},{3,4,6,7,0},{6,7,8,0,0},{4,5,7,8,0}};
    int dou[9]={4,16,64,256,1024,4096,16384,65536,262144};
    /* this method can only use at total less than 1E, the multiple decide on the content of the dial */
    
    while( scanf("%d", &j)!=EOF ){
        
        tmp.pro.clear();
        cal = 0;
        if( j==3 )      tmp.word[0] = 1;
        else if( j==6 ) tmp.word[0] = 2;
        else if( j==9 ) tmp.word[0] = 3;
        else            tmp.word[0] = 0;
        cal += (dou[0]*(int)tmp.word[0]);
        
        for( i=1; i<9; ++i ){
            scanf("%d", &j);
            if( j==3 )      tmp.word[i] = 1;
            else if( j==6 ) tmp.word[i] = 2;
            else if( j==9 ) tmp.word[i] = 3;
            else            tmp.word[i] = 0;
            cal += (dou[i]*(int)tmp.word[i]);
        }
        
        for( i=0; i<9; ++i )
            if( tmp.word[i] )
                break;
        /* if the input all are 12 */
        if( i==9 ){
            putchar('\n');
            continue;
        }
        
        while( !store.empty() ) store.pop();
        memset(use,0,sizeof(use));
        
        store.push(tmp);
        use[cal] = true;
        notfound = true;
        while( notfound ){  //until find the solution
            
            now = store.front();
            store.pop();
            
            for( i=1; i<10; ++i ){
                
                tmp = now;
                for( j=0; j<num[i]; ++j )
                    tmp.word[move[i][j]] = (tmp.word[move[i][j]]+1)%4;
                tmp.pro.push_back(i);
                
                for( j=0; j<9; ++j )
                    if( tmp.word[j] )
                        break;
                if( j==9 ){
                    notfound = false;
                    break;
                }
                else{
                    cal = 0;
                    for( j=0; j<9; ++j )
                        cal += (dou[j]*(int)tmp.word[j]);
                    
                    /* if the condition doesn't appear before, record it and put it into queue */
                    if( !use[cal] ){
                        store.push(tmp);
                        use[cal] = true;
                    }
                }
            }
        }
        
        j = tmp.pro.size();
        printf("%d", (int)tmp.pro[0]);
        for( i=1; i<j; ++i )
            printf(" %d", (int)tmp.pro[i]);
        putchar('\n');
        
    }
    
    return 0;
}
