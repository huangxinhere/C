#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double jiFen(double (*p)(double),double a,double b);
    double func1(double x);
    double func2(double x);
    double func3(double x);

    printf("%lf\n",jiFen(func1,0.0,1.0));
    printf("%lf\n",jiFen(func2,0.0,1.0));
    printf("%lf\n",jiFen(func3,0.0,1.0));

    return 0;
}

double jiFen(double (*p)(double),double a,double b)
{
    double fa,fb,result=0,n;
    int i;

    n=(b-a)/1000.0;//Ã¿Ò»Ð¡¶Î
    for(i=0;i<1000;i++)
    {
       fa=(*p)(a+i*n);
       fb=(*p)(a+(i+1)*n);
       result+=(fa+fb)*n/2.0;
    }

    return result;

}
double func1(double x)
{
    return x*x*x+3*x*x-x+4;
}
double func2(double x)
{
    return x*sqrt(1+cos(2*x));
}
double func3(double x)
{
    return 1/(1+x*x);
}
