#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define PI acos(-1.0)

typedef struct{
    int x;
    int y;
}NODE;
NODE node[1000], base;
    vector<NODE> vec;

bool cmp( NODE a, NODE b ){
    
    if( a.x==base.x && a.y==base.y )   return true;
    if( b.x==base.x && b.y==base.y )   return false;
    
    NODE one, two;
    one.x = a.x - base.x;
    one.y = a.y - base.y;
    two.x = b.x - base.x;
    two.y = b.y - base.y;
    
    if( one.x*two.y - one.y*two.x > 0 ) return true;
    else if( one.x*two.y - one.y*two.x == 0 ){
        int tmpax, tmpay, tmpbx, tmpby;
        tmpax = one.x - base.x;
        tmpay = one.y - base.y;
        tmpbx = two.x - base.x;
        tmpby = two.y - base.y;
        
        if( (tmpax*tmpax+tmpay*tmpay) < (tmpbx*tmpbx+tmpby*tmpby) ) return true;
        else                                                        return false;
    }
    else                                return false;
}

int main(){
    
    int i, j, num, ele, dd;
    double dis, tmpx, tmpy;
    
    while( scanf("%d %d", &num, &dd)!=EOF ){
        
        vec.clear();
        base.x = 10001;
        base.y = 10001;
        for( i=0; i<num; ++i ){
            scanf("%d %d", &node[i].x, &node[i].y);
            if( node[i].y < base.y )    base = node[i];
            else if( node[i].y == base.y ){
                if( node[i].x < base.x ) base = node[i];
            }
        }
        
        sort(node, node+num, cmp);
        
        vec.push_back(node[0]);
        vec.push_back(node[1]);
        vec.push_back(node[2]);
        
        for( i=3,ele=2; i<num; ++i ){
            while( vec.size()>=3 && ((vec[ele].x-vec[ele-1].x)*(node[i].y-vec[ele-1].y)-(vec[ele].y-vec[ele-1].y)*(node[i].x-vec[ele-1].x)<=0) ){
                --ele;
                vec.pop_back();
            }
            vec.push_back(node[i]);
            ++ele;
        }
        
        for( i=1,dis=0; i<=ele; ++i ){
            tmpx = (double)(vec[i].x - vec[i-1].x);
            tmpy = (double)(vec[i].y - vec[i-1].y);
            dis += sqrt(tmpx*tmpx + tmpy*tmpy);
        }
        tmpx = (double)(vec[ele].x - vec[0].x);
        tmpy = (double)(vec[ele].y - vec[0].y);
        dis += sqrt(tmpx*tmpx + tmpy*tmpy);
        
        dis += ( PI * 2.0 * (double)dd );
        
        printf("%.0lf\n", dis );
        
    }
    
    return 0;
}
