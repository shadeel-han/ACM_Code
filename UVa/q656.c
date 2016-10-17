#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int y[10], stack[10][15], op[10], ans;
char output[45];

void NumInput(int n){
	int i;
    for(i=0; i<n; ++i)  scanf("%d", &stack[i][0]);
    for(i=0; i<n; ++i)  scanf("%d", &y[i]);
}

void OutputOp(int i){
	switch( i ){
		case 1: sprintf(output, "%s ADD", output);	break;
		case 2: sprintf(output, "%s DIV", output);  break;
		case 3: sprintf(output, "%s DUP", output);  break;
		case 4: sprintf(output, "%s MUL", output);  break;
		case 5: sprintf(output, "%s SUB", output);  break;
	}
}

void backtrace(int index, int top, int n){
	int i;
	for(i=0; i<n; ++i)
	if( stack[i][0]!=y[i] )  break;

	if( i==n ){
		if( !index ){
			ans = 0;    sprintf(output, " Empty sequence");
		} else if( ans > index ){
			ans = index;	memset(output, 0, sizeof(output));
			for(i=0; i<index; i++)	OutputOp(op[i]);
		}
		return ;
	} else if( index==10 || index==ans )
	    return ;

	int a[10], b[10], c[10], dt=top-1, it=top+1, ii=index+1;
	for(i=0; i<n; ++i){
		a[i] = stack[i][top];
		c[i] = stack[i][it];
		if( top )	b[i] = stack[i][dt];
	}
	
	if( top ){
		/* ADD */
		for(i=0; i<n; ++i){
            stack[i][dt] = a[i] + b[i];
            if( abs(stack[i][dt])>30000 )   break;
		}
		if( i==n ){
            op[index] = 1;	backtrace(ii, dt, n);
		}
		/* DIV */
		for(i=0; i<n; ++i)
		if( !a[i] ) break;
		else		stack[i][dt] = b[i] / a[i];
		if( i==n ){
            op[index] = 2;	backtrace(ii, dt, n);
		}
		for(i=0; i<n; ++i)	stack[i][dt] = b[i];/* recovery */
	}
	/* DUP */
	for(i=0; i<n; ++i)  stack[i][it] = a[i];
	op[index] = 3;	backtrace(ii, it, n);
	for(i=0; i<n; ++i)  stack[i][it] = c[i];    /* recovery */
	if( top ){
        /* MUL */
		for(i=0; i<n; ++i){
            stack[i][dt] = a[i] * b[i];
            if( abs(stack[i][dt])>30000 )   break;
		}
		if( i==n ){
            op[index] = 4;	backtrace(ii, dt, n);
		}
		/* SUB */
		for(i=0; i<n; ++i){
            stack[i][dt] = b[i] - a[i];
            if( abs(stack[i][dt])>30000 )   break;
		}
		if( i==n ){
            op[index] = 5;	backtrace(ii, dt, n);
		}
		for(i=0; i<n; ++i)	stack[i][dt] = b[i];/* recovery */
	}
}

int main(void){
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, i, c=0;

	while( scanf("%d", &n) && n ){
  		NumInput(n);
  		printf("Program %d\n", ++c);
  		ans = 11;
  		backtrace(0,0,n);
  		if( ans==11 )	puts("Impossible");
  		else            puts(output+1);
  		putchar('\n');
	}

	return 0;
}
