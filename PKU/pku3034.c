#include <stdio.h> 

typedef struct{
        int x; 
        int y; 
        int t; 
        }REC; 

int main(){
    
    REC record[1000]; 
    int map[10][40][40], dp[2][40][40];
    int jumpx[6][16], jumpy[6][16], fromx[6][16], fromy[6][16]; 
    int wide, dis, time, num, i, j, k, m, n, p, q, limit, tmpx, tmpy, tarx, tary, tmp;
    int chanx[4]={1,-1,-1,1}, chany[4]={1,-1,1,-1}; 
    
    jumpx[1][0]=0; jumpx[2][0]=1; jumpx[3][0]=4; jumpx[4][0]=8; jumpx[5][0]=15;
    jumpx[2][1]=1; jumpy[2][1]=1; fromx[2][1]=0; fromy[2][1]=0;
    jumpx[3][1]=1; jumpy[3][1]=1; fromx[3][1]=0; fromy[3][1]=0;
    jumpx[3][2]=2; jumpy[3][2]=2; fromx[3][2]=1; fromy[3][2]=1;
    jumpx[3][3]=2; jumpy[3][3]=1; fromx[3][3]=0; fromy[3][3]=0;
    jumpx[3][4]=1; jumpy[3][4]=2; fromx[3][4]=0; fromy[3][4]=0;
    jumpx[4][1]=1; jumpy[4][1]=1; fromx[4][1]=0; fromy[4][1]=0;
    jumpx[4][2]=2; jumpy[4][2]=2; fromx[4][2]=1; fromy[4][2]=1;
    jumpx[4][3]=2; jumpy[4][3]=1; fromx[4][3]=0; fromy[4][3]=0;
    jumpx[4][4]=1; jumpy[4][4]=2; fromx[4][4]=0; fromy[4][4]=0;
    jumpx[4][5]=3; jumpy[4][5]=1; fromx[4][5]=0; fromy[4][5]=0;
    jumpx[4][6]=3; jumpy[4][6]=2; fromx[4][6]=0; fromy[4][6]=0;
    jumpx[4][7]=1; jumpy[4][7]=2; fromx[4][7]=0; fromy[4][7]=0;
    jumpx[4][8]=1; jumpy[4][8]=3; fromx[4][8]=0; fromy[4][8]=0;
    jumpx[5][1]=1; jumpy[5][1]=1; fromx[5][1]=0; fromy[5][1]=0;
    jumpx[5][2]=2; jumpy[5][2]=2; fromx[5][2]=1; fromy[5][2]=1;
    jumpx[5][3]=2; jumpy[5][3]=1; fromx[5][3]=0; fromy[5][3]=0;
    jumpx[5][4]=1; jumpy[5][4]=2; fromx[5][4]=0; fromy[5][4]=0;
    jumpx[5][5]=3; jumpy[5][5]=1; fromx[5][5]=0; fromy[5][5]=0;
    jumpx[5][6]=3; jumpy[5][6]=2; fromx[5][6]=0; fromy[5][6]=0;
    jumpx[5][7]=1; jumpy[5][7]=2; fromx[5][7]=0; fromy[5][7]=0;
    jumpx[5][8]=1; jumpy[5][8]=3; fromx[5][8]=0; fromy[5][8]=0;
    jumpx[5][9]=3; jumpy[5][9]=3; fromx[5][9]=1; fromy[5][9]=1;
    jumpx[5][10]=4; jumpy[5][10]=1; fromx[5][10]=0; fromy[5][10]=0;
    jumpx[5][11]=4; jumpy[5][11]=2; fromx[5][11]=2; fromy[5][11]=1;
    jumpx[5][12]=4; jumpy[5][12]=3; fromx[5][12]=0; fromy[5][12]=0;
    jumpx[5][13]=1; jumpy[5][13]=4; fromx[5][13]=0; fromy[5][13]=0;
    jumpx[5][14]=2; jumpy[5][14]=4; fromx[5][14]=1; fromy[5][14]=2;
    jumpx[5][15]=3; jumpy[5][15]=4; fromx[5][15]=0; fromy[5][15]=0;
    
    while( scanf("%d %d %d", &wide, &dis, &num) ){
           if( !num )
               break; 
           time = 1; 
           for( i=0; i<num; i++ ){ 
                scanf("%d %d %d", &record[i].x, &record[i].y, &record[i].t);
                if( record[i].t > time )
                    time = record[i].t; 
           } 
           limit = wide+(dis<<2);
           for( i=0; i<time; i++ )
                for( j=0; j<limit; j++ )
                     for( k=0; k<limit; k++ )
                          map[i][j][k] = 0; 
           tmp = dis<<1; 
           for( i=0; i<num; i++ )
                map[record[i].t-1][record[i].x+tmp][record[i].y+tmp] = 1; 
           for( i=0; i<limit; i++ )
                for( j=0; j<limit; j++ ){ 
                     dp[0][i][j] = 0;
                     dp[1][i][j] = 0; 
                } 
           wide = dis + (dis>>1); 
           limit -= wide; 
           for( i=0; i<time; i++ ){
                
                for( j=wide; j<limit; j++ )
                     for( k=wide; k<limit; k++ ){ 
                          dp[0][j][k] = dp[1][j][k];
                          dp[1][j][k] = 0; 
                     }
                
                for( j=wide; j<limit; j++ )
                     for( k=wide; k<limit; k++ ){
                          
                          if( map[i][j][k] )
                              tmp = dp[0][j][k]+1;
                          else
                              tmp = dp[0][j][k]; 
                          if( tmp > dp[1][j][k] )
                              dp[1][j][k] = tmp;  
                          
                          for( m=1; m<=jumpx[dis][0]; m++ )
                               for( n=0; n<4; n++ ){
                                    tarx = j+chanx[n]*jumpx[dis][m];  tary = k+chany[n]*jumpy[dis][m]; 
                                    tmp = dp[0][j][k]+map[i][tarx][tary]+map[i][j][k];
                                    if( fromx[dis][m] ){
                                        tmpx = chanx[n]*fromx[dis][m];  tmpy = chany[n]*fromy[dis][m];
                                        if( tarx > j ){ 
                                            for( p=j+tmpx,q=k+tmpy; p<tarx; p+=tmpx,q+=tmpy )
                                                 if( map[i][p][q] )
                                                     tmp++;
                                        } 
                                        else{ 
                                             for( p=j+tmpx,q=k+tmpy; p>tarx; p+=tmpx,q+=tmpy )
                                                 if( map[i][p][q] )
                                                     tmp++;
                                        } 
                                    } 
                                    if( tmp > dp[1][tarx][tary] )
                                        dp[1][tarx][tary] = tmp;
                               }
                               
                          for( m=1; m<=dis; m++ ){
                               tarx = m;
                               tmpx = dp[0][j][k];  tmpy = dp[0][j][k]; 
                               p = dp[0][j][k];  q = dp[0][j][k]; 
                               for( n=0; n<=tarx; n++ ){ 
                                    if( map[i][j+n][k] )
                                        tmpx++;
                                    if( map[i][j][k+n] )
                                        tmpy++; 
                                    if( map[i][j-n][k] )
                                        p++;
                                    if( map[i][j][k-n] )
                                        q++; 
                               }
                               if( tmpx > dp[1][j+m][k] )
                                   dp[1][j+m][k] = tmpx;
                               if( tmpy > dp[1][j][k+m] )
                                   dp[1][j][k+m] = tmpy;
                               if( p > dp[1][j-m][k] )
                                   dp[1][j-m][k] = p;
                               if( q > dp[1][j][k-m] )
                                   dp[1][j][k-m] = q; 
                          } 
                     }
           } 
           tmp = 0; 
           for( i=dis; i<limit; i++ )
                for( j=dis; j<limit; j++ ) 
                     if( dp[1][i][j] > tmp )
                         tmp = dp[1][i][j];
           printf("%d\n", tmp); 
    } 
    return 0; 
}
