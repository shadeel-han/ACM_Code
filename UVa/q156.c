#include <stdio.h>

int getorder[1002], len[1002];

void merge(char* a[], int low, int high)
{ 	
	int h, i, j, k, mid=(low+high)>>1, out=0, tmp;
	int tmporder[1002], tmplen[1002];
	char* b[1002];
	for ( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else{
             if( len[i]<len[j] ){
                 tmp = len[i];
                 for( h=0; h<tmp; h++ ){
                      if( a[i][h]<a[j][h] ){
                          b[k] = a[i];
                          tmporder[k] = getorder[i];
                          tmplen[k] = len[i++];
                          break;
                      }
                      else if( a[i][h]>a[j][h] ){
                           b[k] = a[j];
                          tmporder[k] = getorder[j];
                          tmplen[k] = len[j++];
                          break;
                      }
                 }
                 if( h==tmp ){
                     b[k] = a[i];
                     tmporder[k] = getorder[i];
                     tmplen[k] = len[i++];
                 }
             }
             else if( len[i]>len[j] ){ 
                 tmp = len[j];
                 for( h=0; h<tmp; h++ ){
                      if( a[i][h]<a[j][h] ){
                          b[k] = a[i];
                          tmporder[k] = getorder[i];
                          tmplen[k] = len[i++];
                          break;
                      }
                      else if( a[i][h]>a[j][h] ){
                           b[k] = a[j];
                          tmporder[k] = getorder[j];
                          tmplen[k] = len[j++];
                          break;
                      }
                 }
                 if( h==tmp ){
                     b[k] = a[j];
                     tmporder[k] = getorder[j];
                     tmplen[k] = len[j++];
                 }
             }
             else{
                  tmp = len[i];
                 for( h=0; h<tmp; h++ ){
                      if( a[i][h]<a[j][h] ){
                          b[k] = a[i];
                          tmporder[k] = getorder[i];
                          tmplen[k] = len[i++];
                          break;
                      }
                      else if( a[i][h]>a[j][h] ){
                           b[k] = a[j];
                          tmporder[k] = getorder[j];
                          tmplen[k] = len[j++];
                          break;
                      }
                 }
                 if( h==tmp ){
                     b[k] = a[i];
                     tmporder[k] = getorder[i];
                     tmplen[k] = len[i++];
                 }
             }
        }
	}
	if( out )  /*若out=0,表示是i>mid,表示j未排進b的元素原本就比較大*/
	    for( i,k; i<=mid; i++,k++ ){
	         b[k] = a[i];
	         tmporder[k] = getorder[i];
	         tmplen[k] = len[i];
        }
	for(i=low,k=0; i<j; i++,k++){
       a[i] = b[k];
       getorder[i] = tmporder[k];
       len[i] = tmplen[k];
    }
} 

void mergeSort(char* a[], int low, int high)
{
     if( high-low>1 ){
         int k=(low+high)>>1;
         mergeSort(a, low, k);
         mergeSort(a, ++k, high);
     }
     merge(a, low, high);
}

int main(){
    char in, temp, orig[1002][21], work[1002][21], *pointer[1002], *not[1002];
    int i, j, k, num=0, order=0, sw=0, yes=0;

    while( in=getchar() ){
           if( isalpha(in) ){
                if( !sw ){
                    len[order++] = num;  /*words put in 1~N*/
                    sw++;
                    num = 0;
                }
               orig[order][num] = in;
               work[order][num++] = in | 0x20;
           }
           else if( in=='#' ){
               work[++order][0] = in;
               num = 0;
               break;
           }
           else
                sw=0;
    }

    /*insertion sort for every word*/
    for( i=1; i<order; i++ ){
         for( j=1; j<len[i]; j++ ){
              temp = work[i][j];
              for( k=j-1; k>=0; k-- ){
                   if( work[i][k]>temp )
                       work[i][k+1] = work[i][k];
                   else
                       break;
              }
              work[i][k+1] = temp;
         }
         /*make pointer point at every word for merge sort*/
         pointer[i] = work[i];
         getorder[i] = i;
    }
    pointer[i] = work[i];
    
    /*merge sort the work array using pointer*/
    mergeSort(pointer,1,order-1);
    
    /*get the relative ananagrams in the text*/
    for( i=2; i<=order; i++ ){
         if( !strcmp(pointer[i-1],pointer[i]) ){
             yes = 1;
         }
         else if( !yes ){
              not[num] = orig[getorder[i-1]];
              len[num++] = len[i-1];
         }
         else
             yes=0;
    }

    /*because of lexicographic order, merge sort the the relative ananagrams*/
    mergeSort(not,0,num-1);
    for( i=0; i<num; i++ )
         printf("%s\n",not[i]);

    return 0;
}
