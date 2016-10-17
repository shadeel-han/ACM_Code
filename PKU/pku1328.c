#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    double s ;
    double e ;
}area;

int cmp ( const void *a , const void *b)
{
    area *m = (area*)a ;
    area *n = (area*)b ;
    if (m->s>n->s)
        return 1 ;
    else if (m->s<n->s) 
        return -1 ;
    if (m->s==n->s)
    {
        if ( m->e<n->e)
            return -1 ;
        else
            return 1 ;
    } 
}

int main ()
{
    int num , dis , i , x , y , cnt , case_cnt=1 , z ;
    double tmp ;
    area data[1001] , temp ;
    while ( scanf("%d %d",&num,&dis)==2 )
    {
        cnt = 0 ; z=0 ;
        if ( num==0 && dis==0 )
            break ;
        for ( i=0 ; i<num ; i++ )
        {
            scanf ("%d %d",&x,&y) ;
            if ( y>dis )
            	z = -1 ;
            tmp = sqrt(dis*dis-y*y) ;
            data[i].s = x - tmp ;
            data[i].e = x + tmp ;
        }
        if (z==-1)
        {
            printf ("Case %d: -1\n",case_cnt++) ;
            continue ;
        }
        data[i].s = 2147483647 ;
        data[i].e = 2147483647 ;
        qsort(data,num,sizeof(area),cmp) ;
        
        if ( num==1 )
        {
            printf ("Case %d: 1\n",case_cnt++) ;
            continue ;
        }
        temp.s = data[0].s ;
        temp.e = data[0].e ;
        for ( i=1 ; i<=num ; i++ )
        {
            if ( temp.e>=data[i].s )
            {
                temp.s = data[i].s ;
                if ( data[i].e<temp.e )
               		temp.e = data[i].e ;
            }
            else
            {
                temp.s = data[i].s ;
                temp.e = data[i].e ;
                cnt++ ;
            }
        }
        printf ("Case %d: %d\n",case_cnt++,cnt) ;
    }
    return 0 ;
}
