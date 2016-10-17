#include <stdio.h>

typedef struct{
        int from;
        int to;
        }node;

void merge(node a[], int low, int high)
{ 	
	int i, j, k, mid=(low+high)>>1, out=0;
	node b[100002];
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else if( a[i].from > a[j].from )
             b[k]=a[j++];  
        else
            b[k]=a[i++];
	}
	if( out )  /*若out=0,表示是i>mid,表示j未排進b的元素原本就比較大*/
	    for( i,k; i<=mid; i++,k++ )
	         b[k]=a[i];
	for(i=low,k=0; i<=j-1; i++,k++)
       a[i]=b[k]; 
} 

void mergeSort(node a[], int low, int high)
{
     if( high-low>1 ){
         int k=(low+high)>>1;
         mergeSort(a, low, k);
         mergeSort(a, ++k, high);
     }
     merge(a, low, high);
}

int main(){
    int tol, target, count, i, rec[5002], index;
    node work[100002];
    scanf("%d",&tol);
    while( tol-- ){
           scanf("%d",&target);
           count = 0;
           while( scanf("%d %d", &work[count].from, &work[count].to) )
                  if( !work[count].from && !work[count].to )
                      break;
                  else
                      count++;
           if( count )
               mergeSort(work,0,count-1);
           
           rec[0] = 0;  /*注意要檢查起頭有無覆蓋到0*/
           for( i=1; i<count; i++ ){
                if( work[i].from > 0 )
                    break;
                if( work[rec[0]].to < work[i].to )
                     rec[0] = i;
           }
           
           if( work[rec[0]].from>0 )
               puts("0");
           else{
               index = 0;
               while( work[rec[index++]].to<target && i<count ){
                      rec[index] = rec[index-1];
                      for( i; i<count; i++ ){
                           if( work[i].from > work[rec[index-1]].to )
                               break;
                           if( work[rec[index]].to < work[i].to )
                                rec[index] = i;
                      }
                      if( rec[index] == rec[index-1] )
                          break;
               }
               if( work[rec[index-1]].to<target )
                   puts("0");
               else{
                    printf("%d\n", index);
                    for( i=0; i<index; i++ )
                         printf("%d %d\n", work[rec[i]].from, work[rec[i]].to);
               }
           }
           if( tol )
               printf("\n");
    }
    return 0;
}
