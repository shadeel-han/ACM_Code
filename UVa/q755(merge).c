#include <stdio.h>
#include <string.h>

void merge(char* a[], int low, int high)
{ 	
	int h, i, j, k, mid=(low+high)>>1, out=0;
	char* b[100001];
	for( k=0,i=low,j=mid+1; ; k++ ){  
		if( i>mid )
		    break;
        else if( j>high ){
             out++;
             break;
        }
        else{
             for( h=0; h<8; h++ ){
                  if( a[i][h]<a[j][h] ){
                      b[k] = a[i++];
                      break;
                  }
                  else if( a[i][h]>a[j][h] ){
                       b[k] = a[j++];
                       break;
                  }
             }
             if( h==8 )
                 b[k] = a[i++];
        }
	}
	if( out )  /*若out=0,表示是i>mid,表示j未排進b的元素原本就比較大*/
	    for( i,k; i<=mid; i++,k++ )
	         b[k]=a[i];
	for(i=low,k=0; i<j; i++,k++)
       a[i]=b[k]; 
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
    int tol, num, count, i, j, counter, dunum;
    char in[50], record[100001][9]={0}, *pointer[100001], temp, *z;
    scanf("%d", &tol);
    while( tol-- ){
           scanf("%d", &num);
           getchar();
           for( i=0; i<num; i++ ){
                gets(in);
                for( count=0,j=0; count<3; j++ )
                     if( in[j]=='-' );
                     else if( in[j]<58 )
                         record[i][count++] = in[j];
                     else if( in[j]>80 ){
                         temp = 50+(in[j]-66)/3;
                         record[i][count++] = temp;
                     }
                     else{
                         temp = 50+(in[j]-65)/3;
                         record[i][count++] = temp;
                     }
                record[i][count++] = '-';
                for( count,j; count<8; j++ )
                     if( in[j]=='-' );
                     else if( in[j]<58 )
                         record[i][count++] = in[j];
                     else if( in[j]>80 ){
                         temp = 50+(in[j]-66)/3;
                         record[i][count++] = temp;
                     }
                     else{
                         temp = 50+(in[j]-65)/3;
                         record[i][count++] = temp;
                     }
                pointer[i] = record[i];
           }
           /*set the ending for output "i<=num"*/
           record[num][0] = 'x';
           pointer[num] = record[num];
           
           mergeSort(pointer,0,num-1);
           counter = 0;
           dunum = 0;  /*number of duplication*/
           for( i=1; i<=num; i++ ){
                if( !strcmp( pointer[i-1], pointer[i] ) ){
                    z = pointer[i];
                    counter++;
                }
                else if( counter ){
                     printf("%s %d\n", z, counter+1);
                     dunum++;
                     counter = 0;
                }
           }
           if( !dunum )
               printf("No duplicates.\n");
           if( tol )
               printf("\n");
    }
    return 0;
}
