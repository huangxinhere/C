#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x=1;
    while(fabs(1.5-x)>=1e-5)
        x=x-(2*pow(x,3)-4*pow(x,2)+3*x-6)/(3*pow(x,2)-8*x+3);
    printf("%f",x);
    return 0;
}
