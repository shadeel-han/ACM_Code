#include <cstdio>
#include <vector>

using namespace std;

typedef struct{
    int num;
    double x1;
    double y1;
    double x2;
    double y2;
}STICK;
vector<STICK> store;

bool compare( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4 ){
    
    double d1 = (x1-x3)*(y4-y3) - (y1-y3)*(x4-x3);
    double d2 = (x2-x3)*(y4-y3) - (y2-y3)*(x4-x3);
    double d3 = (x3-x1)*(y2-y1) - (y3-y1)*(x2-x1);
    double d4 = (x4-x1)*(y2-y1) - (y4-y1)*(x2-x1);
    
    if( (d1*d2<0) && (d3*d4<0) )    return true;
    else                            return false;
}

int main(){
    
    int i, j, num, tmp;
    STICK stick;
    
    while( scanf("%d", &num) ){
        
        if( !num )  break;
        
        store.clear();
        for( i=1; i<=num; ++i ){
            stick.num = i;
            scanf("%lf %lf %lf %lf", &stick.x1, &stick.y1, &stick.x2, &stick.y2);
            tmp = store.size();
            for( j=tmp-1; j>=0; --j ){
                if( compare(store[j].x1, store[j].y1, store[j].x2, store[j].y2, stick.x1, stick.y1, stick.x2, stick.y2 ) )
                    store.erase(store.begin()+j);
            }
            store.push_back(stick);
        }
        
        tmp = store.size();
        j = tmp-1;
        printf("Top sticks:");
        for( i=0; i<tmp; ++i ){
            printf(" %d", store[i].num);
            if( i==j )  printf(".\n");
            else        printf(",");
        }
        
    }
    
    return 0;
}
