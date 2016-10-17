#include <stdio.h>

int main(){
    int i, j, ch[96]={0}, num[96]={0}, freq[96], count, getcount, freq_com, ch_com, ok=1;
    char c;
    while( scanf("%c", &c)!=EOF ){
           if( (c!='\n') && (c!='\r') ){
              ch[c-' ']++;
           }
           else{
                if( ok )
                  ok = 0;
                else
                  printf("\n");
                count = 0;
                for( i=0; i<96; i++ )
                   if( ch[i]!=0 ){
                      count++;
                      }
                for( i=0; i<count; i++ ){
                     /*if( ch[i]==0 ){
                         getcount = i;
                         freq_com = 1001;
                     }
                     else{
                         getcount = i+1;
                         freq_com = ch[i];
                         ch_com = i;
                     }*/
                       getcount = i;
                       if( ch[i]!=0 )
                          getcount++;
                       freq_com = ch[i];
                       ch_com = i;
                   for( j=i+1; j<96; j++ ){
                        if( ch[j] == 0 )
                           continue;
                        else if( ch[j] > freq_com ){
                                if( (++getcount)>=count ){
                                    freq[i] = ch[j];
                                    num[i] = j;
                                    /*printf("%d %d\n", j+32, ch[j]);*/
                                    ch[j] = 0;
                                    break;
                                }
                                else{
                                     freq_com = ch[j];
                                     ch_com = j;
                                }
                        }
                        else if( (++getcount)>=count ){
                             freq[i] = freq_com;
                             num[i] = ch_com;
                             /*printf("%d %d\n", ch_com+32, freq_com);*/
                             ch[ch_com] = 0;
                             break;
                        }
                   }
                }
                for( i=count-1; i>=0; i-- )
                     printf("%d %d\n", num[i]+32, freq[i]);
           }
    }
    return 0;
}
