#include <stdio.h>
#include <string.h>

int main(){
    
    char in[202];
    int cas, num, i, cnt[26];
    
    scanf("%d", &cas);
    getchar();
    while( cas-- ){
           gets(in);
           num = strlen(in);
           for( i=0; i<26; i++ )
                cnt[i] = 0;
           for( i=0; i<num; i++ ){
                if( !isalpha(in[i]) )
                    continue;
                if( in[i]<'a' )
                    cnt[in[i]-'A']++;
                else
                    cnt[in[i]-'a']++;
           }
           for( i=0,num=0; i<26; i++ )
                if( cnt[i]>num )
                    num = cnt[i];
           for( i=0; i<26; i++ )
                if( cnt[i]==num )
                    printf("%c", i+'a');
           putchar('\n');
    }
    return 0;
}
