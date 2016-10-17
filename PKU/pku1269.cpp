#include <cstdio>

using namespace std;

int main(){
    
    int i, j, cas;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int d1;  /* p1p3 . p4p3 */
    int d2;  /* p2p3 . p4p3 */
    int d3;  /* p3p1 . p2p1 */
    int d4;  /* p4p1 . p2p1 */
    int d5, d6;
    int ax, ay, ac;
    int bx, by, bc;
    double aa, bb, cc;
    
    scanf("%d", &cas);
    puts("INTERSECTING LINES OUTPUT");
    while( cas-- ){
        
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        d1 = (x1-x3)*(y4-y3) - (y1-y3)*(x4-x3);
        d2 = (x2-x3)*(y4-y3) - (y2-y3)*(x4-x3);
        d3 = (x3-x1)*(y2-y1) - (y3-y1)*(x2-x1);
        d4 = (x4-x1)*(y2-y1) - (y4-y1)*(x2-x1);
        d5 = d1*d2;
        d6 = d3*d4;
        
        if( !d5 && !d6 )
            puts("LINE");
        else{
            d5 = (x2-x1)*(y4-y3);
            d6 = (y2-y1)*(x4-x3);
            if( d5-d6==0 )  puts("NONE");
            else{
                ax = y2-y1;
                ay = x1-x2;
                ac = ax*x1 + ay*y1;
                bx = y4-y3;
                by = x3-x4;
                bc = bx*x3 + by*y3;
                
                aa = (double)(ax*by - bx*ay);
                bb = (double)(ac*by - bc*ay);
                cc = (double)(ax*bc - bx*ac);
                
                printf("POINT %.2lf %.2lf\n", bb/aa, cc/aa);
            }
        }
    }
    puts("END OF OUTPUT");
    return 0;
}
