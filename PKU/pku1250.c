#include <stdio.h>

int main(){
    int bed, i, count, who;
    char cust[54];
    int rec[26];
    
    while( scanf("%d", &bed) ){
       if( !bed )
           break;
       else{
            memset(cust, '\0', 54);
            memset(rec, 0, sizeof(rec));
            scanf(" %s", cust);
       }
       count = 0;
       i = 0;
       while( cust[i]!='\0' ){
              who = cust[i++]-65;
              if( rec[who]==1 )
                   bed++;
              else if( !bed && !rec[who] ){
                  count++;
                  rec[who] = -1;
              }
              else if( bed && !rec[who] ){
                   bed--;
                   rec[who] = 1;
              }
       }
       if( !count )
           printf("All customers tanned successfully.\n"); 
       else
           printf("%d customer(s) walked away.\n", count);
    }
    return 0;
}
