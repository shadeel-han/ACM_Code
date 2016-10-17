#include <stdio.h>

long long int count;

void merge(int a[], int low, int high)
{ 	
	int b[1000], i, j, k, mid=(low+high)>>1, out=0;
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else if( a[i]<=a[j] )  /*此題元素大小有可能一樣, 因為次數要最少, 所以等於的情況不增加count*/
             b[k]=a[i++];  
        else{
            b[k]=a[j++];
            count += (mid-i+1);
        }
	}
	if( out )  /*若out=0,表示是i>mid,表示j未排進b的元素原本就比較大*/
	    for( i,k; i<=mid; i++,k++ )
	         b[k]=a[i];
	for(i=low,k=0; i<=j-1; i++,k++)
       a[i]=b[k]; 
} 

void mergeSort(int a[], int low, int high)
{
     if( high-low>1 ){
         int k=(low+high)>>1;
         mergeSort(a, low, k);
         mergeSort(a, ++k, high);
     }
     merge(a, low, high);
}


int main(){
    int tol, num, i, j, ar[1000];
    scanf("%d", &tol);
    for( j=1; j<=tol; j++ ){
           count = 0;
           scanf("%d", &num);
           for( i=0; i<num; i++ )
                scanf("%d", &ar[i]);
           mergeSort(ar,0,num-1);
           printf("Scenario #%d:\n", j);
           printf("%d\n\n", count);
    }
    return 0;
}
