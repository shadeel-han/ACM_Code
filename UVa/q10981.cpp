#include <stdio.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;

int len, ok;
char target;
map<string, int> record;

void back(int n, int num, char rec[101][101] ){
     
     int i, j, tmp;
     string str;
     map<string, int>::iterator	iter;
     
     if( n==len ){
         if( rec[n][0]==target ){
             for( i=0; i<=n; i++ )
                  puts(rec[i]);
             ok = 0;
         }
     }
     else{
          str.clear();
          str.append(rec[n]);
          iter = record.find(str);
          if( iter!=record.end() )
              return ;
          record[str] = 1;
          tmp = n+1;
          for( j=2; j<=num; j++ )
               rec[tmp][j-1] = rec[n][j];
          for( i=0; i<num; i++ ){
               
               if( i ){
                   j = i-1;
                   rec[tmp][j] = rec[n][j];
               }
               
               switch( rec[n][i] ){
                 case 'a':{switch( rec[n][i+1] ){
                              case 'a':rec[tmp][i] = 'b';
                                       break;
                              case 'b':rec[tmp][i] = 'b';
                                       break;
                              case 'c':rec[tmp][i] = 'a';
                           }
                           break; }
                 case 'b':{switch( rec[n][i+1] ){
                              case 'a':rec[tmp][i] = 'c';
                                       break;
                              case 'b':rec[tmp][i] = 'b';
                                       break;
                              case 'c':rec[tmp][i] = 'a';
                           }
                           break; }
                 case 'c':{switch( rec[n][i+1] ){
                              case 'a':rec[tmp][i] = 'a';
                                       break;
                              case 'b':rec[tmp][i] = 'c';
                                       break;
                              case 'c':rec[tmp][i] = 'c';
                           }
                           }
               }
               
               back(tmp, num-1, rec);
               if( !ok )
                   return ;
          }
     }
}


int main(){
    
    int cas, i, j;
    char table[101][101];
    
    scanf("%d", &cas);
    while( cas-- ){
           getchar();
           gets(table[0]);
           target = getchar();
           
           len = strlen(table[0]);
           
           record.clear();
           ok = 1;
           for( i=1; i<len; i++ )
                for( j=0; j<=len; j++ )
                     table[i][j] = '\0';
           len--;
           back(0,len,table);
           if( ok )
               puts("None exist!");
           if( cas )
               putchar('\n');
    }
    
    return 0;
}
