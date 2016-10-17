#include <stdio.h>

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int cas, c=0, s, i, nice;
	int ansf, anse, ansd, sc, tmpf, tmpsc;
	scanf("%d", &cas);
	while( cas-- ){
		scanf("%d", &s);
		tmpsc = -1;  sc = 0;
		for(i=1; i<s; i++){
            scanf("%d", &nice);
			if( tmpsc<0 )	tmpsc = 0, tmpf = i;
			tmpsc += nice;
			if( tmpsc > sc ){
				sc = tmpsc; ansf = tmpf;    anse = i; ansd = i-tmpf;
			}else if( (tmpsc==sc) && ((i-tmpf)>ansd) ){
                ansf = tmpf;    anse = i;	ansd = i-tmpf;
			}
		}
		if( sc )    printf("The nicest part of route %d is between stops %d and %d\n", ++c, ansf, anse+1);
		else        printf("Route %d has no nice parts\n", ++c);
	}
	return 0;
}
