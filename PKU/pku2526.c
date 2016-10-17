#include <stdio.h>
#include <math.h>

int main(){
    
    int i, j, num, cas, use[10001];
    double pointx[10001], pointy[10001], x, y, tmpx, tmpy;
    double dis[10001], tmp;
    
    scanf("%d", &cas);
    while( cas-- ){
           scanf("%d", &num);
           x = 0;
           y = 0;
           for( i=0; i<num; i++ ){
                scanf("%lf %lf", &pointx[i], &pointy[i]);
                use[i] = 1;
           }
           for( i=0; i<num; i++ ){
                x += pointx[i];
                y += pointy[i]; 
           }
           x /= num;
           y /= num;
           for( i=0; i<num; i++ ){
                tmpx = x - pointx[i];
                tmpy = y - pointy[i];
                dis[i] = sqrt(tmpx*tmpx+tmpy*tmpy);
           }
           for( i=0; i<num; i++ ){
                if( use[i] ){
                    use[i] = 0;
                    if( dis[i]==0 )
                        continue;
                    for( j=i+1; j<num; j++ )
                         if( dis[i]==dis[j] )
                             break;
                    if( j == num )
                        break;
                    else{
                         use[j]= 0;
                        i=0;
                    }
                }
           }
           if( j==num )
               puts("no");
           else
               puts("yes");
           
    }
    return 0;
}
