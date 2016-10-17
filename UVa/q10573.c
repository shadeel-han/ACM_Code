#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    int cas, get;
    double pi=2*acos(0), a, b, ans;
    char in[7], *p;
    
    scanf("%d", &cas);
    getchar();
    while( cas-- ){
           gets(in);
           get = 1;
           p = strtok(in," ");
           a = atof(p);
           p = strtok(NULL," ");
           if( p!=NULL ){
                  get = 0;
                  b = atof(p);
           }
           
           if( get )
               printf("%.4lf\n", a*a*pi/8);
           else
               printf("%.4lf\n", 2*a*b*pi);
    }
    return 0;
}
