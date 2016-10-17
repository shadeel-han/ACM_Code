#include <stdio.h>

int main(){
    int rec[100], nume, demo, count, tmpa, tmpb, i;
    while( scanf("%d %d", &nume, &demo)!=EOF ){
           count = 0;
           i = 0;
           while( demo ){
                  tmpa = nume/demo;
                  rec[count++] = tmpa;
                  tmpb = demo;
                  demo = nume - tmpa*demo;
                  nume = tmpb;
           }
           printf("[%d;%d", rec[0], rec[1]);
           for( i=2; i<count; i++ )
                printf(",%d",rec[i]);
           puts("]");
    }
    return 0;
}
