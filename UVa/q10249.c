#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int order;
    }node;

int cmp(const void *a, const void *b)
{
    node *arg1 = (node*) a;
    node *arg2 = (node*) b;
    if( arg1->num>arg2->num )
        return -1;
    else
        return 1; 
}

int main(){
    int teamNum, tableNum, seat[72][102], rec[72], i, j, tmp;
    node team[72], table[52];
    while( scanf("%d %d", &teamNum, &tableNum) ){
        if( !teamNum )
            break;
        for( i=0; i<teamNum; i++ ){
            scanf("%d", &rec[i]);
            team[i].num = rec[i];
            team[i].order = i+1;
        }
        for( i=0; i<tableNum; i++ ){
            scanf("%d", &table[i].num);
            table[i].order = i+1;
        }
        qsort(team,teamNum,sizeof(node),cmp);
        
        if( team[0].num<=tableNum ){  /*程钉ヮ计璶ゑ计ぶ┪单*/
            for( i=0; i<teamNum; i++ ){
                qsort(table,tableNum,sizeof(node),cmp);
                for( j=0; j<team[i].num; j++ ){
                    if( !table[j].num )
                        break;
                    seat[team[i].order][j] = table[j].order;
                    table[j].num--;
                }
                if( j<team[i].num )
                    break;
            }
            if( i<teamNum )
                puts("0");
            else{
                puts("1");
                for( i=1; i<=teamNum; i++ ){
                    tmp = rec[i-1]-1;
                    for( j=0; j<tmp; j++ )
                        printf("%d ", seat[i][j]);
                    printf("%d\n", seat[i][tmp]);
                }
            }
        }
        else  /*程钉ヮ计ゑ计*/ 
            puts("0");
    }
    
    return 0;
}
