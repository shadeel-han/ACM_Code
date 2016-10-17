#include <stdio.h>
#include <string.h>

int main(){
    char in[3100], temp, *z;
    int i, index, num, max, maxone, count, use, work[31], sol[60];
    
    while(gets(in)!=NULL){
       index = 0;   /*index夹ボsol竚*/
       count = 1;   /*碭程计竒逼*/
       max = 0;

       z = strtok(in," ");
       work[++max] = atoi(z);
       printf("%s", z);
       z = strtok(NULL," ");
       while(z!=NULL){
          printf(" %s", z);
          work[++max] = atoi(z);
          z = strtok(NULL," ");
       }
       printf("\n");
       num = max;   /*num魁羆计*/
       
       while( max ){ /*max逞緇т程计Ω计*/
          maxone = 0;
          for( i=1; i<=max; i++ )
               if( maxone<work[i] )
                   maxone = work[i];
          if( work[max]==maxone ){ /*程计竒タ絋竚*/
              max--;
              count++;
              continue;
          }
          else{
               for( i=1; i<max; i++ )  /*程计ぃタ絋竚*/
                    if( work[i]==maxone )
                        break;
                        
               if( i==1 ){             /*程计材竚*/
                   use = max;
                   sol[index++] = count++;
                   max--;
               }
               else{                   /*程计ㄤ竚*/
                    use = i;
                    sol[index++] = num+1-i;
               }
               
               for( i=1; i<=(use>>1); i++ ){
                    temp = work[use-i+1];
                    work[use-i+1] = work[i];
                    work[i] = temp;
               }
          }
       }
       if(index)
       for( i=0; i<index; i++ )
            printf("%d ", sol[i]);
       printf("0\n");
    }
    return 0;
}
