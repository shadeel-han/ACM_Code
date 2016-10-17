#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF 100000

using namespace std;

typedef struct{
    int dis;
    int mon;
}REC;

typedef struct{
    int to;
    int dis;
    int mon;
}WAY;

vector<WAY> road[101];
REC record[101];

bool non_dijkstra(int start, int end, int money){
    
    queue<WAY> que;
    WAY tmp, tmp2;
    
    record[start].dis = 0;
    tmp.to = start;
    tmp.dis = record[start].dis;
    tmp.mon = record[start].mon;
    
    que.push(tmp);
    while( !que.empty() ){
        
        tmp = que.front();
        que.pop();
        
        int i, limit = road[tmp.to].size();
        for( i=0; i<limit; ++i ){
            
            if( tmp.mon - road[tmp.to][i].mon < 0 ) continue;
            if( tmp.dis + road[tmp.to][i].dis > record[end].dis ) continue;
            
            if( tmp.dis + road[tmp.to][i].dis < record[road[tmp.to][i].to].dis ){
                tmp2.to = road[tmp.to][i].to;
                record[tmp2.to].dis = tmp.dis + road[tmp.to][i].dis;
                tmp2.dis = record[tmp2.to].dis;
                tmp2.mon = tmp.mon - road[tmp.to][i].mon;
                if( record[tmp2.to].mon==money || tmp2.mon > record[tmp2.to].mon )
                    record[tmp2.to].mon = tmp2.mon;
                if( tmp2.to!=end )  que.push(tmp2);
            }
            else if( tmp.mon - road[tmp.to][i].mon > record[road[tmp.to][i].to].mon ){
                tmp2.to = road[tmp.to][i].to;
                tmp2.dis = tmp.dis + road[tmp.to][i].dis;;
                record[tmp2.to].mon = tmp.mon - road[tmp.to][i].mon;
                tmp2.mon = record[tmp2.to].mon;
                if( tmp2.to!=end )  que.push(tmp2);
            }
            else if( road[tmp.to][i].to != end ){
                tmp2.to = road[tmp.to][i].to;
                tmp2.dis = tmp.dis + road[tmp.to][i].dis;;
                tmp2.mon = tmp.mon - road[tmp.to][i].mon;
                que.push(tmp2);
            }
            
        }
        
    }
    
    if( record[end].dis==INF )  return false;
    else                        return true;
}



int main(){
    
    int ver, money, num, i, j;
    WAY read;
    
    while( scanf("%d", &money)!=EOF ){
        
        scanf("%d", &ver);
        scanf("%d", &num);
        
        for( i=1; i<=ver; ++i ){
            road[i].clear();
            record[i].dis = INF;
            record[i].mon = money;
        }
        
        for( i=0; i<num; ++i ){
            scanf("%d %d %d %d", &j, &read.to, &read.dis, &read.mon);
            if( j!=ver && j!=read.to ) road[j].push_back(read);
        }
        
        if( non_dijkstra(1,ver,money) )
            printf("%d\n", record[ver].dis);
        else
            puts("-1");
    }
    
    return 0;
}
