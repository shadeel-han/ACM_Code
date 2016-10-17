#include <stdio.h>
#include <string.h>

char* word[50];

int compare( const void* a, const void* b ){  /*compare function*/
    int i, j, alen, blen, temp;
    char *one, *two;
    one = *(char**)a;
    two = *(char**)b;
    alen = strlen(one);
    blen = strlen(two);
    if( alen>blen ){                          /*special case  1 10 101 1010 10101 101010  and  99 999 9999 9990 99990*/
        for( i=0 ; i<blen; i++ ){
             if( one[i]>two[i] )
                 return -1;
             else if( one[i]<two[i] )
                  return 1;
        }
        for( i ; i<alen ; i++ ){
             temp = i%blen;
             if( two[temp]>one[i] )
                 return 1;
             else if( two[temp]<one[i] )
                  return -1;
        }
        if( two[i%blen]>one[0] )
            return 1;
        else if( two[i%blen]<one[0] )
             return -1;
        return 0;
    }
    else if(alen<blen){
         for( i=0 ; i<alen; i++ ){
             if( one[i]>two[i] )
                 return -1;
             else if( one[i]<two[i] )
                  return 1;
        }
        for( i ; i<blen; i++ ){
             temp = i%alen;
             if( one[temp]>two[i] )
                 return -1;
             else if( one[temp]<two[i] )
                  return 1;
        }
        if( one[i%alen]>two[0] )
            return -1;
        else if( one[i%alen]<two[0] )
             return 1;
        return 0;
    }
    else{
         for( i=0 ; i<alen; i++ ){
             if( one[i]>two[i] )
                 return -1;
             else if( one[i]<two[i] )
                  return 1;
        }
        return 0;
    }
    /*if( alen<blen )
        for( i ; i<blen+1 ; i++ ){
             tempa = i%alen;
             tempb = i%blen;
             if( one[tempa]>two[tempb] )
                 return -1;
             else if( one[tempa]<two[tempb] )
                  return 1;
        }
    else if( alen>blen )
         for( i ; i<alen+1 ; i++ ){
              tempa = i%alen;
             tempb = i%blen;
             if( two[tempb]>one[tempa] )
                 return 1;
             else if( two[tempb]<one[tempa] )
                  return -1;
        }
    return 0;*/
}

int main(){
    int num, i;
    char in[2000], *z;
    while(scanf("%d", &num)){
       if( !num )
           break;
       getchar();
       gets(in);
       for( i=0,z=strtok(in," "); z; z=strtok(NULL," "),i++ )
            word[i] = z;
       qsort(word, num, sizeof(char*), compare);
       for( i=0; i<num ;i++ )
            printf("%s", word[i]);
       printf("\n");
    }
    return 0;
}
