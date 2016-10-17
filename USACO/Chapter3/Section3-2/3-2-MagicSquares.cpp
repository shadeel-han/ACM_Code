/*
ID: j9010311
PROG: msquare
LANG: C++
*/

#include <cstdio>
#include <string>
#include <queue>
#include <map>

using namespace std;

map<string,string> rec;
queue<string> que;

int main(){
    
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    
    int i, j;
    string now, cha, tar;
    char tmp;
    
    while( scanf("%c", &tmp)!=EOF ){
        
        tar.clear();
        tar += tmp;
        
        for( i=1; i<8; ++i ){
            getchar();
            tmp = getchar();
            tar += tmp;
        }
        getchar();
        
        now.clear();
        cha.clear();
        rec.clear();
        for( i=1; i<9; ++i ){
            now += ('0'+i);
            cha += ('0'+i);
        }
        while( !que.empty() )   que.pop();
        que.push(now);
        rec[tar] = " ";
        
        if( !tar.compare(now) ){
            puts("0\n");
            continue;
        }
        
        while( !que.empty() ){
            
            now = que.front();
            que.pop();
            
            // operation A
            for( i=0; i<8; ++i )
                cha[0+i] = now[7-i];
            if( !tar.compare(cha) ){
                now = rec[now] + 'A';
                break;
            }
            if( rec.find(cha)==rec.end() ){
                rec[cha] = rec[now] + 'A';
                que.push(cha);
            }
            
            // operation B
            for( i=1; i<4; ++i ){
                cha[i] = now[i-1];
                cha[3+i] = now[4+i];
            }
            cha[0] = now[3];
            cha[7] = now[4];
            if( !tar.compare(cha) ){
                now = rec[now] + 'B';
                break;
            }
            if( rec.find(cha)==rec.end() ){
                rec[cha] = rec[now] + 'B';
                que.push(cha);
            }
            
            // operation C
            cha[0] = now[0];
            cha[3] = now[3];
            cha[4] = now[4];
            cha[7] = now[7];
            cha[1] = now[6];
            cha[2] = now[1];
            cha[5] = now[2];
            cha[6] = now[5];
            if( !tar.compare(cha) ){
                now = rec[now] + 'C';
                break;
            }
            if( rec.find(cha)==rec.end() ){
                rec[cha] = rec[now] + 'C';
                que.push(cha);
            }
            
        }
        
        printf("%d\n%s\n", now.size(), now.c_str());
        
    }
    
    return 0;
}
