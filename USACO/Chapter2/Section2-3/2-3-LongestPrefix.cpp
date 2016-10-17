/*
ID: j9010311
PROG: prefix
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct REC{
    char len;
    char word[10];
};
vector<REC> pr;
char input[200005];
bool used[200005];

bool cmp( REC a, REC b ){
    if( a.len < b.len ) return true;
    else                return false;
}

int main(){
    
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    
    REC tmp;
    int i, j, k, m, limit, start[12];
    char in[2000];
    char *p;
    bool stop;
    
    gets(in);
    while(1){
        
        stop = false;
        pr.clear();
        p = strtok(in," ");
        while( p!=NULL ){
            tmp.len = strlen(p);
            for( i=0; i<tmp.len; ++i )
                tmp.word[i] = *(p+i);
            pr.push_back(tmp);
            p = strtok(NULL," ");
        }
        
        while( gets(in) ){
            if( strlen(in)==1 && in[0]=='.' )   break;
            p = strtok(in," ");
            while( p!=NULL ){
                tmp.len = strlen(p);
                for( i=0; i<tmp.len; ++i )
                    tmp.word[i] = *(p+i);
                pr.push_back(tmp);
                p = strtok(NULL," ");
            }
        }
        sort(pr.begin(),pr.end(),cmp);
        
        memset(start,-1,sizeof(start));
        for( i=0,j=pr.size(); i<j; ++i )
        if( start[pr[i].len]==-1 )
            start[pr[i].len] = i;
        start[11] = j;
        for( i=10; i>0; --i )
        if( start[i]==-1 )
            start[i] = start[i+1];
        
        limit = 1;
        while(1){
            if( gets(in)==NULL ){
                stop = true;
                break;
            }
            for( i=0,j=strlen(in); i<j; ++i )
                if( in[i]==' ' )   break;
            if( i<j )   break;
            
            for( i=0; i<j; ++i,++limit )
                input[limit] = in[i];
        }
        
        memset(used,0,limit+1);
        used[0] = true;
        for( i=0; i<limit; ++i ){
            if( !used[i] )  break;
            for( j=1; j<11; ++j ){
                if( (i+j)>=limit )  break;
                for( k=start[j]; k<start[j+1]; ++k ){
                    for( m=0; m<j; ++m )
                    if( input[i+1+m]!=pr[k].word[m] )
                        break;
                    if( m==j ){
                        for( m=0; m<j; ++m )
                            used[i+1+m] = true;
                        break;
                    }
                }
            }
        }
        printf("%d\n", i-1);
        
        if( stop )  break;
    }
    
    return 0;
}
