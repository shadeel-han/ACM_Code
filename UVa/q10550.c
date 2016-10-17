#include <stdio.h>

int main(){
    int first, second, third, fourth, /*one, two, three,*/ check;
    while(scanf("%d %d %d %d", &first, &second, &third, &fourth)){
        if( !first && !second && !third && !fourth )
            break;
        check = 0;
        /*if( first>=second )
            one = first - second;
        else
            one = 40 + first - second;
        if( second>=third )
            two = 40 + third - second;
        else
            two = third - second;
        if( third>=fourth )
            three = third - fourth;
        else
            three = 40 + third - fourth;
        printf("%d\n", (one+two+three+120)*9);*/
        
        if( first<second )
            check++;
        if( second>=third )
            check++;
        if( third<fourth )
            check++;
        printf("%d\n", (first+((third-second)<<1)-fourth+(3+check)*40)*9);
    }
    return 0;
}
