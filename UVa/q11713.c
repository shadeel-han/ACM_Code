#include <stdio.h>
#include <stdlib.h>

int main(){
    char name1[21], name2[21];
    int i, j, one, two, num, judge;
    
    scanf("%d", &num);
    getchar();
    for(i=0; i<num; i++){
       one = 0;
       two = 0;
       judge = 1;
       while( (scanf("%c", &name1[one])) &&  name1[one++]!='\n');
       while( (scanf("%c", &name2[two])) &&  name2[two++]!='\n');
       if( one != two ){
           printf("No\n");
           continue;
       }
       
       for( j=0; j<one-1; j++ ){
            if( name1[j]=='a' || name1[j]=='e' || name1[j]=='i' || name1[j]=='o' ||name1[j]=='u' ){
                if( name2[j]=='a' || name2[j]=='e' || name2[j]=='i' || name2[j]=='o' ||name2[j]=='u' )
                    ;
                else{
                     judge = 0;
                     break;
                }
            }
            else if( name1[j]==name2[j] ){
                 ;
            }
            else{
                 judge = 0;
                 break;
            }
       }
       if( judge )
           printf("Yes\n");
       else
           printf("No\n");
    }
    return 0;
}
