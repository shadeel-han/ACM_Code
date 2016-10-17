#include <stdio.h>

typedef struct{
        int from;
        int to;
        }node;
        
node work1[500000];
node work2[500000];

int compare( const void* a, const void* b ){
    node* arg1 = (node*)a;
    node* arg2 = (node*)b;
    if( arg1->from > arg2->from )
        return 1;
    else if( arg1->from < arg2->from )
         return -1;
    else{
         if( arg1->to > arg2->to )
             return 1;
         else if( arg1->to < arg2->to )
              return -1;
         else
             return 0;
    }
}

int main(){
    int num, i, j, t1, t2, tmp1, tmp2;
    while(scanf("%d", &num)){
       if(!num)
          break;
       t1 = 0;
       t2 = 0;
       for( i=0; i<num; i++ ){
            scanf("%d %d", &tmp1, &tmp2);
            if( tmp1 < tmp2 ){
                work1[t1].from = tmp1;
                work1[t1++].to = tmp2;
            }
            else{
                 work2[t2].from = tmp2;
                 work2[t2++].to = tmp1;
            }
       }
       if( t1!=t2 ){
           puts("NO");
           continue;
       }
       qsort(work1, t1, sizeof(node), compare);
       qsort(work2, t1, sizeof(node), compare);
       
       for( i=0; i<t1; i++ )
            if( work1[i].from!=work2[i].from || work1[i].to!=work2[i].to )
                break;
       if( i==t1 )
           puts("YES");
       else
           puts("NO");
    }
    return 0;
}
