#include <stdio.h>

char route[10]={0};
int cango[6][6]={0}, now[6]={0}, end[6]={5,3,3,4,2,4}, pass=0;

void progress( int n ){
     
     if( pass==8 ){ /*pass record the number of the passed roads*/
         puts(route);
     }
     if( now[n]<end[n] ){
          int i;
          for( i=1; i<6; i++ )
               if( cango[n][i] ){
                   cango[n][i]--;
                   cango[i][n]--;
                   now[n]++;
                   now[i]++;
                   route[++pass] = i + '0';
                   progress(i);
                   pass--;
                   now[n]--;
                   now[i]--;
                   cango[n][i]++;
                   cango[i][n]++;
               }
     }
}

int main(){
    
    cango[1][2]=1; cango[1][3]=1; cango[1][5]=1;
    cango[2][1]=1; cango[2][3]=1; cango[2][5]=1;
    cango[3][1]=1; cango[3][2]=1; cango[3][4]=1; cango[3][5]=1;
    cango[4][3]=1; cango[4][5]=1;
    cango[5][1]=1; cango[5][2]=1; cango[5][3]=1; cango[5][4]=1;
    route[0] = '1';
    progress(1);
    return 0;
}
