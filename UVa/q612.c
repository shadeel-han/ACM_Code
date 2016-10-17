#include <stdio.h>
#include <string.h>

int num, order[101];

void merge(int a[], int low, int high)
{ 	
	int i, j, k, mid=(low+high)>>1, out=0;
	int b[101], tmporder[101];
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else if( a[i]>a[j] ){
             b[k] = a[j];
             tmporder[k] = order[j++];
        }
        else{
            b[k] = a[i];
            tmporder[k] = order[i++];
        }
	}
	if( out )  /*若out=0,表示是i>mid,表示j未排進b的元素原本就比較大*/
	    for( i,k; i<=mid; i++,k++ ){
	         b[k] = a[i];
	         tmporder[k] = order[i];
        }
	for(i=low,k=0; i<=j-1; i++,k++){
       a[i] = b[k];
       order[i] = tmporder[k];
    }
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
    int tol, len, inv[101], i, j, wordnum[4];
    char work[101][51];
    scanf("%d", &tol);
    while(tol--){
       scanf("%d %d", &len, &num);
       getchar();
       for( i=0; i<num; i++ ){
            gets(work[i]);
            order[i] = i;
       }
       memset(inv,0,sizeof(inv));
       for( i=0; i<num; i++ ){
            memset(wordnum,0,sizeof(wordnum));
            for( j=len-1; j>=0; j-- )
                 switch(work[i][j]){
                    case 'A': wordnum[0]++;
                              break;
                    case 'C': wordnum[1]++;
                              inv[i] += wordnum[0];
                              break;
                    case 'G': wordnum[2]++;
                              inv[i] += (wordnum[0]+wordnum[1]);
                              break;
                    case 'T': wordnum[3]++;
                              inv[i] += (wordnum[0]+wordnum[1]+wordnum[2]);
                 }
       }
       mergeSort(inv,0,num-1);
       for( i=0; i<num; i++ )
            printf("%s\n", work[order[i]]);
       if( tol )
           printf("\n");
    }
    return 0;
}
