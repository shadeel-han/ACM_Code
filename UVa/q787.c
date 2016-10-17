#include <stdio.h>
#include <string.h>

#define MAXN 101
#define BASE 100000LL

typedef struct{
	int sign, pnum, p[MAXN];
}BIGNUM;

int num[MAXN], cnt;
BIGNUM maxx, comp;

void Product(int num){
    if( !num ){
        comp.sign = 0;  return;
	}

	int i;	long long int carry=0, pr, in=(num>0)?(num):(-num);
	for(i=0; i<=comp.pnum; i++){
		pr = ((long long int)comp.p[i])*in + carry;
		carry = pr / BASE;  comp.p[i] = pr % BASE;
	}
	if( carry ) comp.p[++comp.pnum] = carry;
	comp.sign = (num*comp.sign>0)?(1):(-1);
}

void CompareBig(void){
	if( comp.sign > maxx.sign )	maxx = comp;
	else if( comp.sign == maxx.sign ){  int i;
		if( comp.sign==1 ){
			if( comp.pnum > maxx.pnum ) maxx = comp;
			else if( comp.pnum == maxx.pnum ){
				for(i=comp.pnum; i>-1; i--)
				if( comp.p[i] != maxx.p[i] )	break;
				if( i>-1 && comp.p[i]>maxx.p[i] )	maxx = comp;
			}
		}else if( comp.sign==-1 ){
            if( comp.pnum < maxx.pnum ) maxx = comp;
			else if( comp.pnum == maxx.pnum ){
				for(i=comp.pnum; i>-1; i--)
				if( comp.p[i] != maxx.p[i] )	break;
				if( i>-1 && comp.p[i]<maxx.p[i] )	maxx = comp;
			}
		}
	}
}

int main(void){
    /*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int i, j;
	while( scanf("%d", &num[0])!=EOF ){
		if( num[0]!=-999999 )	cnt = 1;
		else                    continue;
		while( scanf("%d", &num[cnt]) )
		if( num[cnt]!=-999999 )	++cnt;
		else                    break;
		
		maxx.sign = -1;  maxx.pnum = 0;	maxx.p[0] = 999999;
		for(i=0; i<cnt; i++){
			comp.sign = 1;  comp.pnum = 0;	comp.p[0] = 1;
			for(j=i; j<cnt; j++){
				Product(num[j]);	CompareBig();
				if( !comp.sign )    break;
			}
		}
		
		if( !maxx.sign )    puts("0");
		else{
			if( maxx.sign==-1 ) putchar('-');
			printf("%d", maxx.p[maxx.pnum]);
			for(i=maxx.pnum-1; i>=0; i--)   printf("%05d", maxx.p[i]);
			putchar('\n');
		}
	}
	
	return 0;
}
