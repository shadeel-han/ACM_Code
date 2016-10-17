#include <stdio.h>

int main(){
    char board[8][9];  /*9����],gets�|��촫��r��*/
    int empty, i, j, WKi, WKj, BKi, BKj, count=0, check, tempi, tempj;
    int iKnight[8]={-2,-1,1,2,2,1,-1,-2}, jKnight[8]={1,2,2,1,-1,-2,-2,-1};
    while(1){
       empty = 0;
       check = 0;
       /*Ū���*/
       if( count>0 )
           getchar();
       for( i=0; i<8; i++ )
            gets(board[i]);
       /*��X�¥հ������m*/
       for( i=0; i<8; i++ )
            for( j=0; j<8; j++ ){
                 if( board[i][j]=='k' ){
                     BKi = i;
                     BKj = j;
                     empty = 1;
                 }
                 if( board[i][j]=='K' ){
                     WKi = i;
                     WKj = j;
                 }
            }
       /*�Yempty = 0, ��ܳo�L�ѪŪ�, ����*/
       if( !empty )
           break;
       /*���ˬd�°���O�_�Qcheck*/
       /*1.�ˬd�h�L(pawn)*/
       if( (BKi!=7 && BKj && board[BKi+1][BKj-1]=='P') || (BKi!=7 && BKj!=7 && board[BKi+1][BKj+1]=='P') ){
           printf("Game #%d: black king is in check.\n", ++count);
           continue;
       }
       /*2.�ˬd����(rook)�M�ӦZ(queen)*/
       if( BKi )
           for( i=BKi-1; i>=0; i-- )
                if( board[i][BKj]!='.' ){
                    if( board[i][BKj]=='R' || board[i][BKj]=='Q' )
                        check = 1;
                    break;
                }
       if( !check && BKi!=7 )
           for( i=BKi+1; i<=7; i++ )
                if( board[i][BKj]!='.' ){
                    if( board[i][BKj]=='R' || board[i][BKj]=='Q' )
                        check = 1;
                    break;
                }
       if( !check && BKj )
           for( j=BKj-1; j>=0; j-- )
                if( board[BKi][j]!='.' ){
                    if( board[BKi][j]=='R' || board[BKi][j]=='Q' )
                        check = 1;
                    break;
                }
       if( !check && BKj!=7 )
           for( j=BKj+1; j<=7; j++ )
                if( board[BKi][j]!='.' ){
                    if( board[BKi][j]=='R' || board[BKi][j]=='Q' )
                        check = 1;
                    break;
                }
       /*3.�ˬd�D��(bishop)�M�ӦZ(queen)*/
       if( !check && BKi ){
           if( BKj )
               for( i=BKi-1,j=BKj-1; i>=0&&j>=0; i--,j-- )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='B' || board[i][j]=='Q' )
                            check = 1;
                        break;
                    }
           if( !check && BKj!=7 )
               for( i=BKi-1,j=BKj+1; i>=0&&j<=7; i--,j++ )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='B' || board[i][j]=='Q' )
                            check = 1;
                        break;
                    }
       }
       if( !check && BKi!=7 ){
           if( BKj )
               for( i=BKi+1,j=BKj-1; i<=7&&j>=0; i++,j-- )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='B' || board[i][j]=='Q' )
                            check = 1;
                        break;
                    }
           if( !check && BKj!=7 )
               for( i=BKi+1,j=BKj+1; i<=7&&j<=7; i++,j++ )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='B' || board[i][j]=='Q' )
                            check = 1;
                        break;
                    }
       }
       /*4.�ˬd�M�h(knight)*/
       if( !check )
           for( i=0; i<8; i++ ){
                tempi = BKi + iKnight[i];
                tempj = BKj + jKnight[i];
                if( tempi>=0 && tempi<8 && tempj>=0 && tempj<8 && board[tempi][tempj]=='N' ){
                    check = 1;
                    break;
                }
           }
       /*�°���O�_�Qcheck*/
       if( check==1 ){
           printf("Game #%d: black king is in check.\n", ++count);
           continue;
       }
       
       /*�A�ˬd�հ���O�_�Qcheck*/
       /*1.�ˬd�h�L(pawn)*/
       if( (WKi && WKj && board[WKi-1][WKj-1]=='p') || (WKi && WKj!=7 && board[WKi-1][WKj+1]=='p') ){
           printf("Game #%d: white king is in check.\n", ++count);
           continue;
       }
       /*2.�ˬd����(rook)�ӦZ(queen)*/
       if( WKi )
           for( i=WKi-1; i>=0; i-- )
                if( board[i][WKj]!='.' ){
                    if( board[i][WKj]=='r' || board[i][WKj]=='q' )
                        check = 2;
                    break;
                }
       if( !check && WKi!=7 )
           for( i=WKi+1; i<=7; i++ )
                if( board[i][WKj]!='.' ){
                    if( board[i][WKj]=='r' || board[i][WKj]=='q' )
                        check = 2;
                    break;
                }
       if( !check && WKj )
           for( j=WKj-1; j>=0; j-- )
                if( board[WKi][j]!='.' ){
                    if( board[WKi][j]=='r' || board[WKi][j]=='q' )
                        check = 2;
                    break;
                }
       if( !check && WKj!=7 )
           for( j=WKj+1; j<=7; j++ )
                if( board[WKi][j]!='.' ){
                    if( board[WKi][j]=='r' || board[WKi][j]=='q' )
                        check = 2;
                    break;
                }
       /*3.�ˬd�D��(bishop)�M�ӦZ(queen)*/
       if( !check && WKi ){
           if( WKj )
               for( i=WKi-1,j=WKj-1; i>=0&&j>=0; i--,j-- )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='b' || board[i][j]=='q' )
                            check = 2;
                        break;
                    }
           if( !check && WKj!=7 )
               for( i=WKi-1,j=WKj+1; i>=0&&j<=7; i--,j++ )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='b' || board[i][j]=='q' )
                            check = 2;
                        break;
                    }
       }
       if( !check && WKi!=7 ){
           if( WKj!=0 )
               for( i=WKi+1,j=WKj-1; i<=7&&j>=0; i++,j-- )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='b' || board[i][j]=='q' )
                            check = 2;
                        break;
                    }
           if( !check && WKj!=7 )
               for( i=WKi+1,j=WKj+1; i<=7&&j<=7; i++,j++ )
                    if( board[i][j]!='.' ){
                        if( board[i][j]=='b' || board[i][j]=='q' )
                            check = 2;
                        break;
                    }
       }
       /*4.�ˬd�M�h(knight)*/
       if( !check )
           for( i=0; i<8; i++ ){
                tempi = WKi + iKnight[i];
                tempj = WKj + jKnight[i];
                if( tempi>=0 && tempi<8 && tempj>=0 && tempj<8 && board[tempi][tempj]=='n' ){ 
                    check = 2;
                    break;
                } 
           }
       /*�հ���O�_�Qcheck*/
       if( check==2 )
           printf("Game #%d: white king is in check.\n", ++count);
       else
           printf("Game #%d: no king is in check.\n", ++count);
    }
    return 0;
}
