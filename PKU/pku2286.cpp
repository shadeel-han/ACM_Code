#include <cstdio>
#include <vector>
#include <queue>
#include <string>

/*
    data struct : hash
    the prime number : 163
    record the number in puzzle identical with the indicated number(1,2,3) as 1, otherwise 0
    seperate 1,2,3 three parts to work
*/

using namespace std;

vector <int> hash[163];
char move[8][7]={{0,2,6,11,15,20,22},{1,3,8,12,17,21,23},{10,9,8,7,6,5,4},{19,18,17,16,15,14,13},
                 {23,21,17,12,8,3,1},{22,20,15,11,6,2,0},{13,14,15,16,17,18,19},{4,5,6,7,8,9,10}};
char com[8] = {6,7,8,11,12,15,16,17};

typedef struct{
    char sta[24];
    int num;
    string str;
}DATA;

void rotate( char in[24] ){
    
    queue<DATA> que;
    DATA st, now;
    char i,j,tmp;
    
    for( i=0; i<24; ++i )
        st.sta[i] = in[i];
    st.num = 0;
    st.str.clear();
    
    que.push(st);
    
    while( !que.empty() ){
        
        st = que.front();
        que.pop();
        
        for( i=0,j=1; i<8 && j; ++i )
            j &= st.sta[com[i]];
        if( i==8 && j )  break;
        
        for( i=0; i<8; ++i ){
            
            for( j=0; j<8; ++j )
                now.sta[j] = st.sta[j];
            
            tmp = now.sta[move[i][0]];
            for( j=1; j<8; ++j )
                now.sta[move[i][j-1]] = now.sta[move[i][j]];
            now.sta[move[i][7]] = tmp;
            
            /*check replucation*/
            
            
            now.num = st.num + 1;
            now.str += ('A'+i);
            
        }
        
        
    }
    
    
    
    
}

int main(){
    
    int i, j ;
    char puzzle[24], input[24];
    
    while( puzzle[0]=getchar() ){
        
        if( puzzle[0]=='0' )
            break;
        
        getchar();
        for( i=1; i<24; ++i ){
            puzzle[i] = getchar();
            getchar();
        }
        
        for( i=0; i<163; ++i )
            hash[i].clear();
        
        for( i=0; i<24; ++i )
            if( puzzle[i]=='1' )    input[i] = 1;
            else                    input[i] = 0;
        rotate(input);
        
        for( i=0; i<24; ++i )
            if( puzzle[i]=='2' )    input[i] = 1;
            else                    input[i] = 0;
        rotate(input);
            
        for( i=0; i<24; ++i )
            if( puzzle[i]=='3' )    input[i] = 1;
            else                    input[i] = 0;
        rotate(input);
        
        
    }
    
    return 0;
}
