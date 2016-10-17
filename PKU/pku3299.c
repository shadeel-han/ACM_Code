#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char in[30], *z;
    double tem, hum, dew, h, e;
    while( gets(in) ){
        tem = 0;
        hum = 0;
        dew = 0;
        z = strtok(in," ");
        if( z[0]=='E' )
            break;
        else if( z[0]=='T' ){
             z = strtok(NULL," ");
             tem = atof(z);
        }
        else if( z[0]=='H' ){
             z = strtok(NULL," ");
             hum = atof(z);
        }
        else{
             z = strtok(NULL," ");
             dew = atof(z);
        }
        z = strtok(NULL," ");
        if( z[0]=='T' ){
             z = strtok(NULL," ");
             tem = atof(z);
        }
        else if( z[0]=='H' ){
             z = strtok(NULL," ");
             hum = atof(z);
        }
        else{
             z = strtok(NULL," ");
             dew = atof(z);
        }
        if( !dew ){
            h = hum - tem;
            e = h/0.5555 + 10;
            e = log(e/6.11) / 5417.7530 ;
            dew = (1.0/((1.0/273.16)-e))-273.16;
        }
        else{
             e = 5417.7530*((1.0/273.16) - (1.0/(dew+273.16)));
             e = 6.11*exp(e);
             h = 0.5555*(e-10);
             if( !hum )
                 hum = tem+h;
             else
                 tem = hum-h;
        }
        printf("T %.1lf D %.1lf H %.1lf\n", tem, dew, hum);
    }    
    
    return 0;
}
