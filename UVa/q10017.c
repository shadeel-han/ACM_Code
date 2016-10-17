#include <stdio.h>

int main(){
    char word[10]={'0','1','2','3','4','5','6','7','8','9'}, step[4][900]={0};
    int num, stepnum, counter=0, count[4], i, j, temp, now, choose, in, out, even;
    while( scanf("%d %d", &num, &stepnum) ){
           if( !num )
               break;
           memset(count,0,sizeof(count));
           if( num>=200 ){
               temp = (num%100)/10;
               for( i=num%10; i>=0; i-- ){
                    step[1][count[1]++] = '2';
                    step[1][count[1]++] = word[temp];
                    step[1][count[1]++] = word[i];
                    step[1][count[1]++] = ' ';
               }
               for( i=temp-1; i>=0; i-- )
                    for( j=9; j>=0; j-- ){
                         step[1][count[1]++] = '2';
                         step[1][count[1]++] = word[i];
                         step[1][count[1]++] = word[j];
                         step[1][count[1]++] = ' ';
                    }
               for( i=9; i>=0; i-- )
                    for( j=9; j>=0; j-- ){
                         step[1][count[1]++] = '1';
                         step[1][count[1]++] = word[i];
                         step[1][count[1]++] = word[j];
                         step[1][count[1]++] = ' ';
                    }
               for( i=9; i>0; i-- )
                    for( j=9; j>=0; j-- ){
                         step[1][count[1]++] = word[i];
                         step[1][count[1]++] = word[j];
                         step[1][count[1]++] = ' ';
                    }
               for( j=9; j>1; j-- ){
                    step[1][count[1]++] = word[j];
                    step[1][count[1]++] = ' ';
               }
               step[1][count[1]++] = '1';
           }
           else if( num>=100 ){
               temp = (num%100)/10;
               for( i=num%10; i>=0; i-- ){
                    step[1][count[1]++] = '1';
                    step[1][count[1]++] = word[temp];
                    step[1][count[1]++] = word[i];
                    step[1][count[1]++] = ' ';
               }
               for( i=temp-1; i>=0; i-- )
                    for( j=9; j>=0; j-- ){
                         step[1][count[1]++] = '1';
                         step[1][count[1]++] = word[i];
                         step[1][count[1]++] = word[j];
                         step[1][count[1]++] = ' ';
                    }
               for( i=9; i>0; i-- )
                    for( j=9; j>=0; j-- ){
                         step[1][count[1]++] = word[i];
                         step[1][count[1]++] = word[j];
                         step[1][count[1]++] = ' ';
                    }
               for( j=9; j>1; j-- ){
                    step[1][count[1]++] = word[j];
                    step[1][count[1]++] = ' ';
               }
               step[1][count[1]++] = '1';
           }
           else if( num>=10 ){
                temp = num/10;
                for( i=num%10; i>=0; i-- ){
                    step[1][count[1]++] = word[temp];
                    step[1][count[1]++] = word[i];
                    step[1][count[1]++] = ' ';
               }
               for( i=temp-1; i>0; i-- )
                    for( j=9; j>=0; j-- ){
                         step[1][count[1]++] = word[i];
                         step[1][count[1]++] = word[j];
                         step[1][count[1]++] = ' ';
                    }
               for( j=9; j>1; j-- ){
                    step[1][count[1]++] = word[j];
                    step[1][count[1]++] = ' ';
               }
               step[1][count[1]++] = '1';
           }
           else{
                for( j=num; j>1; j-- ){
                    step[1][count[1]++] = word[j];
                    step[1][count[1]++] = ' ';
                }
                step[1][count[1]++] = '1';
           }
           step[1][count[1]] = '\0';
           printf("Problem #%d\n\n", ++counter);
           printf("A=>   %s\n", step[1]);
           puts("B=>");
           printf("C=>\n\n");
           step[1][count[1]++] = ' ';
           even = num%2-1;
           for( i=1; i<=stepnum; i++ ){
                temp = i;
                now = 1;
                while( !(temp%2) ){
                       temp >>= 1;
                       now++;        /*now is the moving number*/
                }
                choose = now%2+even;
                /*decide which array is in or out*/
                if( temp%3==2 ){
                    in = 1;
                    if( choose )
                        out = 2;
                    else
                        out = 3;
                }
                else if( temp%3==1 ){
                     if( choose )
                         in = 3;
                     else
                          in = 2;
                     out = 1;
                }
                else{
                     if( choose ){
                         in = 2;
                         out = 3;
                     }
                     else{
                          in = 3;
                          out = 2;
                     }
                }
                if( now<10 ){
                    /*put the number into in-array*/
                    step[in][count[in]++] = word[now];
                    step[in][count[in]++] = ' ';
                    /*take the number out out-array*/
                    count[out] -= 2;
                }
                else{
                     /*put the number into in-array*/
                     step[in][count[in]++] = '1';
                     step[in][count[in]++] = word[now-10];
                     step[in][count[in]++] = ' ';
                    /*take the number out out-array*/
                    count[out] -= 3;
                }
                /*output the three arrays*/
                if( count[1] ){
                    step[1][--count[1]] = '\0';
                    printf("A=>   %s\n", step[1]);
                    step[1][count[1]++] = ' ';
                }
                else
                    puts("A=>");
                if( count[2] ){
                    step[2][--count[2]] = '\0';
                    printf("B=>   %s\n", step[2]);
                    step[2][count[2]++] = ' ';
                }
                else
                    puts("B=>");
                if( count[3] ){
                    step[3][--count[3]] = '\0';
                    printf("C=>   %s\n\n", step[3]);
                    step[3][count[3]++] = ' ';
                }
                else
                    printf("C=>\n\n");
           }
    }
    return 0;
}
