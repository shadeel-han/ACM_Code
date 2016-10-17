#include <stdio.h>
#include <string.h>

typedef struct{
        int x;
        int y;
        int num;
        }coordinate;

coordinate stack[101];
int staindex;  /*index of stack*/

void push( coordinate item )   /*push of stack*/
{
     stack[++staindex] = item;
}

coordinate pop()               /*pop of stack*/
{
     return stack[staindex--]; 
}

int main(){
    char in[10000], *z;
    int board[101][101]={0}, dirx[4]={0,1,0,-1}, diry[4]={1,0,-1,0}, recx[100], recy[100]; /*recx.recy record the starting point of every number*/
    int inx, iny, num, i, j, count;  /*count = the number of found according number*/
    coordinate position; /*use for stack if finding the according number*/
    
    while( scanf("%d", &num) ){
           if( !num )
               break;
           getchar();
           if( num==1 ){
               puts("good");
               continue;
           }
           for( i=1; i<num; i++ ){
                gets(in);
                count = 0;
                for( z=strtok(in," "); z; z=strtok(NULL," ") ){
                     inx = atoi(z);
                     z=strtok(NULL," ");
                     iny = atoi(z);
                     board[inx][iny] = i;  /*set the board*/
                }
                recx[i] = inx;  /*record the starting point of 1~num-1*/
                recy[i] = iny;
           }
           
           for( i=1; i<=num; i++ )
                for( j=1; j<=num; j++ )
                     if( !board[i][j] ){
                         board[i][j] = num;  /*record the num-th starting point*/
                         recx[num] = i;
                         recy[num] = j;
                     }
           
           for( i=1; i<=num; i++ ){
                stack[1].x = recx[i];
                stack[1].y = recy[i];
                stack[1].num = 0;
                count = 0;
                staindex = 1;
                while( staindex ){
                       position = pop();
                       for( j=position.num; j<4; j++ ){
                            inx = position.x+dirx[j];
                            iny = position.y+diry[j];
                            if( board[inx][iny]==i ){
                                board[inx][iny] = 0;
                                position.num = j+1;
                                push(position);
                                count++;
                                position.x = inx;
                                position.y = iny;
                                j = -1;
                            }
                       }
                }
                if( count!=num ){  /*the wrong condition*/
                    for( inx=1; inx<=num; inx++ )
                         for( iny=1; iny<=num; iny++ )  /*clear the board*/
                              board[inx][iny] = 0;
                    break;
                }
           }
           if( i>num )
               puts("good");
           else
               puts("wrong");
                         
    }
    return 0;
}
