#include <stdio.h>
#include <string.h>

char* word[27000];

int compare( const void* a, const void* b ){  /*compare function*/
    int i, alen, blen;
    char *one, *two;
    one = *(char**)a;
    two = *(char**)b;
    alen = strlen(one);
    blen = strlen(two);
    if( alen>blen ){
        for( i=0 ; i<blen; i++ ){
             if( one[i]>two[i] )
                 return 1;
             else if( one[i]<two[i] )
                  return -1;
        }
        return 1;
    }
    else if( alen<blen ){
         for( i=0 ; i<alen; i++ ){
             if( one[i]>two[i] )
                 return 1;
             else if( one[i]<two[i] )
                  return -1;
        }
        return -1;
    }
    else{
         for( i=0 ; i<alen; i++ ){
             if( one[i]>two[i] )
                 return 1;
             else if( one[i]<two[i] )
                  return -1;
        }
        return 0;
    }
}

int main(){
    char in[200], *z, temp[5001][200];
    int count=0, len, i, j, tmp=0;
    while( gets(in)!=NULL ){
           len = strlen(in);
           for( i=0; i<len; i++ )
                if( isalpha(in[i]) )     /*the character is an alphabat, alway do lowercasenize before store*/
                    temp[tmp][i] = in[i] | 0x20;
                else
                    temp[tmp][i] = ' ';  /*the character is not an alphabat, store a space*/
           for( z=strtok(temp[tmp]," "); z; z=strtok(NULL," ") )
                word[count++] = z;
           tmp++;
    }
    qsort(word, count, sizeof(char*), compare);
    for( i=0; i<count-1 ;i++ )
         if( strcmp(word[i],word[i+1]) )
             printf("%s\n", word[i]);
    printf("%s\n", word[i]);
    return 0;
}
