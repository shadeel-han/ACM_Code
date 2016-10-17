#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
        int score;
        char name;
        }NODE;
NODE node[32], keep[32];
int count;
char target, ans[34];

int cmp( const void* a, const void* b ){
    NODE *arg1 = (NODE*) a;
    NODE *arg2 = (NODE*) b;
    
    if( arg1->score != arg2->score )
        return (arg1->score - arg2->score);
    else{
         if( arg1->name > arg2->name )
             return 1;
         else
             return -1;
    }
}

int cmp2( const void* a, const void* b ){
    NODE *arg1 = (NODE*) a;
    NODE *arg2 = (NODE*) b;
    
    if( arg1->name > arg2->name )
        return 1;
    else
        return -1;
}

void recursive(int total, int start, int end, int flag){  /*flag=1,表示本隊還在node; flag=0,表示本隊不在node*/
     
     NODE a1[16], a2[16], t1[16], t2[16], temp;
     int i, j, k, m, n, half=(total>>1), go, stop;
     
     if( total==2 ){
         if( node[0].name > node[1].name ){
             ans[start] = node[1].name;
             ans[end] = node[0].name;
         }
         else{
              ans[start] = node[0].name;
              ans[end] = node[1].name;
         }
     }
     else{
          for( j=0; j<half; j++ ){
               a1[j] = node[j];
               a2[j] = node[half+j];
          }
          
          for( i=2; i<=half; (i<<=1) ){
               stop = (i>>1);
               for( j=0; j<half; j+=i ){
                    go = j+stop;
                    for( m=0; m<stop; m++ )
                         if( a1[j+m].name!=target )
                             for( k=flag; k<total; k++ )
                                  if( a1[j+m].score==node[k].score ){
                                      for( n=0; n<m; n++ )
                                           if( a1[j+n].name==node[k].name )
                                               break;
                                      if( n==m ){
                                          a1[j+m].name = node[k].name;
                                          break;
                                      }
                                  }
                    for( m=0; m<stop; m++ )
                         if( a1[go+m].name!=target )
                             for( k=flag; k<total; k++ )
                                  if( a1[go+m].score==node[k].score ){
                                      for( n=0; n<m; n++ )
                                           if( a1[go+n].name==node[k].name )
                                               break;
                                      if( n==m ){
                                          a1[go+m].name = node[k].name;
                                          break;
                                      }
                                  }
                    
                    for( k=0; k<half; k+=2 )
                         if( a1[k].name > a1[k+1].name ){
                             temp = a1[k];
                             a1[k] = a1[k+1];
                             a1[k+1] = temp;
                         }
                    
                    for( k=0,m=0; k<stop; k++ ){
                         if( a1[j+k].name < a1[go+k].name )
                             break;
                         if( a1[j+k].name > a1[go+k].name ){
                             m++;
                             break;
                         }
                    }
                    if( m )
                        for( k=0; k<stop; k++ ){
                             temp = a1[j+k];
                             a1[j+k] = a1[go+k];
                             a1[go+k] = temp;
                        }
               }
          }

          for( i=2; i<=half; (i<<=1) ){
               stop = (i>>1);
               for( j=0; j<half; j+=i ){
                    go = j+stop;
                    for( m=0; m<stop; m++ )
                         for( k=flag; k<total; k++ )
                              if( a2[j+m].score==node[k].score ){
                                  for( n=0; n<m; n++ )
                                       if( a2[j+n].name==node[k].name )
                                           break;
                                  if( n==m ){
                                      a2[j+m].name = node[k].name;
                                      break;
                                  }
                              }
                    for( m=0; m<stop; m++ )
                         for( k=flag; k<total; k++ )
                              if( a2[stop+m].score==node[k].score ){
                                  for( n=0; n<m; n++ )
                                       if( a2[stop+n].name==node[k].name )
                                           break;
                                  if( n==m ){
                                      a2[stop+m].name = node[k].name;
                                      break;
                                  }
                              }
                    
                    for( k=0; k<half; k+=2 )
                         if( a2[k].name > a2[k+1].name ){
                             temp = a2[k];
                             a2[k] = a2[k+1];
                             a2[k+1] = temp;
                         }
                    
                    for( k=0,m=0; k<stop; k++ ){
                         if( a2[j+k].name < a2[go+k].name )
                             break;
                         if( a2[j+k].name > a2[go+k].name ){
                             m++;
                             break;
                         }
                    }
                    if( m )
                        for( k=0; k<stop; k++ ){
                             temp = a2[j+k];
                             a2[j+k] = a2[go+k];
                             a2[go+k] = temp;
                        }
               }
          }
          
          for( m=0; m<half; m++ )
               if( a1[m].name!=target )
                   for( k=flag; k<total; k++ )
                        if( a1[m].score==node[k].score ){
                            for( n=0; n<m; n++ )
                                 if( a1[n].name==node[k].name )
                                     break;
                            if( n==m ){
                                a1[m].name = node[k].name;
                                break;
                            }
                        }
          for( k=0; k<half; k+=2 )
               if( a1[k].name > a1[k+1].name ){
                   temp = a1[k];
                   a1[k] = a1[k+1];
                   a1[k+1] = temp;
               }
          
          for( m=0; m<half; m++ )
               for( k=flag; k<total; k++ )
                    if( a2[m].score==node[k].score ){
                        for( n=0; n<m; n++ )
                             if( a2[n].name==node[k].name )
                                 break;
                        if( n==m ){
                            a2[m].name = node[k].name;
                            break;
                        }
                    }
          for( k=0; k<half; k+=2 )
               if( a2[k].name > a2[k+1].name ){
                   temp = a2[k];
                   a2[k] = a2[k+1];
                   a2[k+1] = temp;
               }
          
          /*for( i=0; i<half; i++ )
               printf("%c ", a1[i].name);
          printf("\n");
          for( i=0; i<half; i++ )
               printf("%c ", a2[i].name);
          printf("\n");*/
          
          
          for( i=0,j=1; i<half; i++ ){
               if( a1[i].name < a2[i].name )
                   break;
               if( a1[i].name > a2[i].name ){
                   j = 0;
                   break;
               }
          }
          
          if( j ){
              for( i=0; i<half; i++ )
                   ans[start+i] = a1[i].name;
                      
              for( i=0; i<half; i++ ){
                   for( k=0; k<total; k++ )
                        if( node[k].name==a1[i].name ){
                            node[k].score = 0;
                            break;
                        }
              }
              for( i=0,j=0; j<half; i++ )
                   if( node[i].score )
                       node[j++] = node[i];
                       
              recursive(half,start+half,end,0);
          }
          else{
               for( i=0; i<half; i++ )
                    ans[start+i] = a2[i].name;
                      
               for( i=0; i<half; i++ ){
                    for( k=flag; k<total; k++ )
                         if( node[k].name==a2[i].name ){
                             node[k].score = 0;
                             break;
                         }
               }
               for( i=0,j=0; j<half; i++ )
                    if( node[i].score )
                        node[j++] = node[i];
               
               recursive(half,start+half,end,1);
          }
          
     }
}

int main(){

    NODE temp;
    int i, j, cas, tol;
    char tmp;
    
    scanf("%d", &cas);
    while( cas-- ){
           memset(ans,'\0',sizeof(ans));
           scanf("%d", &tol);
           tol = (1<<tol);
           getchar();
           scanf("%c", &target);
           for( i=0; i<tol; i++ )
                scanf("%d", &node[i].score);
           for( i=0,tmp='A'; i<tol && i<26; i++,tmp++ )
                node[i].name = tmp;
           for( i=26,tmp='a'; i<tol; i++,tmp++ )
                node[i].name = tmp;
           
           for( i=0; i<tol; i++ )
                keep[i] = node[i];
           
           qsort(node,tol,sizeof(NODE),cmp);
           
           /**while( tol>2 ){*/
                  for( i=0; i<tol; i++ )
                       if( node[i].name==target )
                           break;
                  if( i==tol ){
                      qsort(node,tol,sizeof(NODE),cmp2);
                      for( j=0; j<tol; j++ )
                           printf("%c", node[j].name);
                      printf("\n");
                      continue;
                  }
                  if( i ){
                      temp = node[i];
                      for( j=i-1; j>=0; j-- )
                           node[j+1] = node[j];
                      node[0] = temp;
                  }
                  
                  recursive(tol,0,tol-1,1);
           /*}*/
           /*for( i=0; i<tol; i+=2 )
                if( ans[i] > ans[i+1] ){
                    tmp = ans[i+1];
                    ans[i+1] = ans[i];
                    ans[i] = tmp;
                }*/
           puts(ans);
    }
    return 0;
}
