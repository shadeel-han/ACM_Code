#include <stdio.h>

typedef struct{
        int from;
        int to;
        }node;
        
node work1[500000], work2[500000];

void merge(node a[], int low, int high)
{ 	
	int i, j, k, mid=(low+high)>>1, out=0;
	node b[500000];
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else if( a[i].from > a[j].from )
             b[k]=a[j++];  
        else if( a[i].from < a[j].from )
            b[k]=a[i++];
        else{
             if( a[i].to <= a[j].to )
                 b[k]=a[i++];
             else
                 b[k]=a[j++]; 
        }
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
       mergeSort(work1,0,t1-1);
       mergeSort(work2,0,t1-1);
       
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
