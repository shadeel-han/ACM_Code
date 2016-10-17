#include <stdio.h>

int work[1000];
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
        else if( a[i]<=a[j] )  /*���D�����j�p���i��@��, �]�����ƭn�̤�, �ҥH���󪺱��p���W�[count*/
             b[k]=a[i++];  
        else{
            b[k]=a[j++];
            count += (mid-i+1);
        }
	}
	if( out )  /*�Yout=0,��ܬOi>mid,���j���ƶib�������쥻�N����j*/
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
   int num, i;
   while(scanf("%d", &num)!=EOF){
       for( i=0; i<num; i++ )
            scanf("%d", &work[i]);
       count = 0;
       mergeSort(work,0,num-1);
      printf("Minimum exchange operations : %lld\n", count);
   }      
   return 0;
}
