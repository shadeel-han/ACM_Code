#include <stdio.h>
#include <string.h>

int compare( const void* a, const void* b ){  /*compare function*/
    int i;
    char *one, *two;
    one = *(char**)a;
    two = *(char**)b;
    for( i=0; i<8; i++ ){
         if( one[i]>two[i] )
             return 1;
         else if( one[i]<two[i] )
              return -1;
    }
    return 0;
}

int main(){
    int tol, num, count, i, j, counter, dunum;
    char in[50], record[100001][9]={0}, *pointer[100001], temp, *z;
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d", &num);
           getchar();
           for( i=0; i<num; i++ ){
                gets(in);
                for( count=0,j=0; count<3; j++ )
                     if( in[j]=='-' );
                     else if( in[j]<58 )
                         record[i][count++] = in[j];
                     else if( in[j]>80 ){
                         temp = 50+(in[j]-66)/3;
                         record[i][count++] = temp;
                     }
                     else{
                         temp = 50+(in[j]-65)/3;
                         record[i][count++] = temp;
                     }
                record[i][count++] = '-';
                for( count,j; count<8; j++ )
                     if( in[j]=='-' );
                     else if( in[j]<58 )
                         record[i][count++] = in[j];
                     else if( in[j]>80 ){
                         temp = 50+(in[j]-66)/3;
                         record[i][count++] = temp;
                     }
                     else{
                         temp = 50+(in[j]-65)/3;
                         record[i][count++] = temp;
                     }
                pointer[i] = record[i];
           }
           record[num][0] = 'x';
           pointer[num] = record[num];
           qsort(pointer,num,sizeof(char*),compare);
           counter = 0;
           dunum = 0;
           for( i=1; i<=num; i++ ){
                if( !strcmp( pointer[i-1], pointer[i] ) ){
                    z = pointer[i];
                    counter++;
                }
                else if( counter ){
                     printf("%s %d\n", z, counter+1);
                     dunum++;
                     counter = 0;
                }
           }
           if( !dunum )
               printf("No duplicates.\n");
           if( tol )
               printf("\n");
    }
    return 0;
}
