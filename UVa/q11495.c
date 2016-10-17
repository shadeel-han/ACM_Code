#include <stdio.h>
#include <string.h>

int work[100001], count;

void merge(int a[], int low, int high)
{ 	
	int b[100001], i, j, k, mid=(low+high)>>1, out=0;
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else if( a[i]<a[j] )  /*���D�����j�p�����@��,�ҥH���S���S�������S���Y*/
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
   char in[588893], *z;
   while(scanf("%d ", &num)){
      if( !num )
          break;
      else{
           gets(in);
           count = 0;
           for( i=0,z=strtok(in," "); z; z=strtok(NULL," "),i++ )
                work[i] = atoi(z);
           mergeSort(work,0,num-1);
      }
      if( count%2 )
          puts("Marcelo");
      else
          puts("Carlos");
   }      
   return 0;
}
