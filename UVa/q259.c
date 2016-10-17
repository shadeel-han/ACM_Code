#include <stdio.h>
#include <string.h>

char applist[26][15], app_num, com[11];

char backtrack(char index, char start, char end, char remain){
	if( index==app_num ){
		puts(com);
		return 1;
	}
	char i, ok;
	for(i=start; i<end; ++i){
		/* not take */
		if( (end-i) > remain ){
            ok = backtrack(index, i+1, end, remain);
			if( ok )	return 1;
		}
		/* take */
		if( com[applist[index][i]-'0']=='_' ){
            com[applist[index][i]-'0'] = applist[index][0];
            if( remain > 1 )
				ok = backtrack(index, i+1, end, remain-1);
			else
				ok = backtrack(index+1, 3, (char)(strlen(applist[index+1])-1), applist[index+1][1]-'0');
            com[applist[index][i]-'0'] = '_';
            if( ok )    return 1;
		}
	}
	return 0;
}

int main(void){
    /*freopen("in.txt", "r", stdin);*/
	/*freopen("out.txt", "w", stdout);*/
	char i;
	memset(com, '_', sizeof(com));  com[10] = 0;
	while( gets(applist[0]) ){
        app_num = 1;
        while( gets(applist[app_num])!=NULL && strlen(applist[app_num]) )	++app_num;
        int tol = 0;
        for(i=0; i<app_num; ++i)    tol += (int)(applist[i][1]-'0');
        if( tol>10 || !backtrack(0,3,(char)(strlen(applist[0])-1),applist[0][1]-'0') )	puts("!");
	}
	
	return 0;
}
