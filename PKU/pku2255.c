#include <stdio.h>
#include <string.h>

char preorder[26], inorder[26], postorder[26];

void find_post( int low, int high, int forthshift, int backshift ){
     if( high>low ){
         int i;
         for( i=low; i<=high; i++ )
              if( inorder[i]==preorder[low+forthshift] ){
                  postorder[high-backshift] = inorder[i];
                  break;
              }
         if( i-low>=1 )
             find_post(low,i-1,forthshift+1,backshift);
         if( high-i>=1 )
             find_post(i+1,high,forthshift,backshift+1);
     }
     else
         postorder[low-backshift] = inorder[low];
}

int main(){
    int len, inindex, preindex, postindex;
    while( scanf("%s %s", preorder, inorder)!=EOF ){
           len = strlen(preorder);
           find_post(0,len-1,0,0);
           postorder[len] = '\0';
           printf("%s\n",postorder);
    }  
    return 0;
}
