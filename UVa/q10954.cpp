#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(){
    
    priority_queue< int , vector<int> , greater<int> > PQ;
    int i, num, cost, a, b ;
    char in[30000], *p;
    
    while( scanf("%d", &num) ){
           if( !num )
               return 0;
           getchar();
           gets(in);
           p = strtok(in," ");
           while( p!=NULL ){
                  a = atoi(p);
                  PQ.push(a);
                  p = strtok(NULL," ");
           }
           cost = 0;
           while( --num ){
                a = PQ.top();
                PQ.pop();
                b = PQ.top();
                PQ.pop();
                a += b;
                cost += a;
                PQ.push(a);
           }
           PQ.pop();
           printf("%d\n", cost);
    }
}
