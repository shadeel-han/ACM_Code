#include <stdio.h>
#include <string.h>

int main(){
    char in[3100], temp, *z;
    int i, index, num, max, maxone, count, use, work[31], sol[60];
    
    while(gets(in)!=NULL){
       index = 0;   /*index�Х�sol��m*/
       count = 1;   /*�X�ӳ̤j���Ƥw�g�Ʀn*/
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
       num = max;   /*num�����`��*/
       
       while( max ){ /*max�Ѿl��̤j�ƪ�����*/
          maxone = 0;
          for( i=1; i<=max; i++ )
               if( maxone<work[i] )
                   maxone = work[i];
          if( work[max]==maxone ){ /*�̤j�Ƥw�g�b���T��m�W*/
              max--;
              count++;
              continue;
          }
          else{
               for( i=1; i<max; i++ )  /*�̤j�Ƥ��b���T��m�W*/
                    if( work[i]==maxone )
                        break;
                        
               if( i==1 ){             /*�̤j�Ʀb�Ĥ@�Ӧ�m*/
                   use = max;
                   sol[index++] = count++;
                   max--;
               }
               else{                   /*�̤j�Ʀb��L��m*/
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
