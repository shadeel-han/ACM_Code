#include <stdio.h>
#include <string.h>

int main(){
    int len, i, k, one[26]={0}, two[26]={0}, temp;
    char first[101], second[101];
    scanf("%s", first);
    scanf("%s", second);
    len = strlen(first);
    for( i=0; i<len; i++ ){
         one[first[i]-65]++;
         two[second[i]-65]++;
    }
    for( i=1; i<26; i++ ){
      temp = one[i];
      for( k=i-1; k>=0; k-- ){
           if( one[k]>temp )
               one[k+1] = one[k];
           else
               break;
      }
      one[k+1] = temp;
    }
    for( i=1; i<26; i++ ){
      temp = two[i];
      for( k=i-1; k>=0; k-- ){
           if( two[k]>temp )
               two[k+1] = two[k];
           else
               break;
      }
      two[k+1] = temp;
    }
    for( i=0; i<26; i++ )
         if( one[i]!=two[i] )
             break;
    if( i==26 )
        printf("YES");
    else
        printf("NO");

    return 0;
}
