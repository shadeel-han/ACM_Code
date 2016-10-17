#include <stdio.h>
#include <string.h>

int main(){
    int i, j, k, row, col, tempx, tempy, count=0, ok=0;
    int x[8]={-1,0,1,1,1,0,-1,-1}, y[8]={-1,-1,-1,0,1,1,1,0};
    char map[102][102];
    int num[102][102]={0};
    while( scanf("%d %d", &row, &col) ){
           getchar();
           if( !row )
               break;
           count++;
           if( !ok ){
               ok++;
               printf("Field #%d:\n", count);
           }
           else
               printf("\nField #%d:\n", count);
           memset(num,0,sizeof(num));
           for( i=1; i<=row; i++ )
                gets(map[i]);
           for( i=1; i<=row; i++ )
           for( j=0; j<col; j++ )
                if( map[i][j]=='*' ){
                    for( k=0; k<8; k++ ){
                         tempx = j+x[k];
                         tempy = i+y[k];
                         if( tempx>-1 )
                             num[tempy][tempx]++;
                    }
                }
           for( i=1; i<=row; i++){
              for( j=0; j<col; j++ )
                   if( map[i][j]!='*' )
                       printf("%d", num[i][j]);
                   else
                       printf("*");
              printf("\n");
           }
    }
    return 0;
}
