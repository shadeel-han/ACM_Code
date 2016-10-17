#include <stdio.h>
#include <math.h>

typedef struct{
        double corx;
        double cory;
        }node;
        
double shortest;

void merge(node a[], int low, int high)
{ 	
	int i, j, k, mid=(low+high)>>1, out=0;
	node b[10000];
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else if( a[i].corx < a[j].corx )
             b[k] = a[i++];
        else
            b[k]=a[j++];
	}
	if( out )
	    for( i,k; i<=mid; i++,k++ )
	         b[k]=a[i];
	for(i=low,k=0; i<=j-1; i++,k++)
       a[i]=b[k]; 
} 

void divDistance(node a[], int low, int high){
     double disx, disy, dis;
     if( high-low>1 ){
         int k=(low+high)>>1;
         divDistance(a, low, k);
         divDistance(a, k+1, high);
         
         int leftN, rightN, i, j;
         double left=a[k].corx-shortest, right=a[k].corx+shortest;
         for( i=1; k-i>=low ; i++ )
              if( a[k-i].corx<=left )
                  break;
         leftN = i;
         for( i=1; k+i<=high; i++ )
              if( a[k+i].corx>=right )
                  break;
         rightN = i;
         
         int tmpi, tmpj;
         for( i=0; i<leftN; i++ ){
              for( j=1; j<rightN; j++ ){
                   tmpi = k-i;
                   tmpj = k+j;
                   disx = a[tmpj].corx - a[tmpi].corx;
                   if( disx >= shortest  )
                       break;
                   disy = a[tmpj].cory - a[tmpi].cory;
                   dis = sqrt(disx*disx+disy*disy);
                   if( dis<shortest )
                       shortest = dis;
              }
         }
         
     }
     else if( high!=low ){
         disx = a[high].corx - a[low].corx;
         if( disx < shortest ){
             disy = a[high].cory - a[low].cory;
             dis = sqrt(disx*disx+disy*disy);
             if( dis<shortest )
                 shortest = dis;
         }
     }
}

void mergeSort(node a[], int low, int high){
     if( high-low>1 ){
         int k=(low+high)>>1;
         mergeSort(a, low, k);
         mergeSort(a, k+1, high);
     }
     if( high!=low )
         merge(a, low, high);
}

int main(){
    int num, i;
    node work[10000];
    while(scanf("%d", &num)){
       if(!num)
          break;
       for( i=0; i<num; i++ )
            scanf("%lf %lf", &work[i].corx, &work[i].cory);
       mergeSort(work,0,--num);
       shortest = 10000;
       divDistance(work,0,num);
       if( shortest==10000 )
           puts("INFINITY");
       else
           printf("%.4lf\n", shortest);
    }
    return 0;
}
