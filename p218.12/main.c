#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x=1,res;
    int a,b,c,d;
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    printf("%f",func(a,b,c,d,x));

    return 0;
}
void func(int a,int b,int c,int d,float x)
{
    float x_0;
    do
    {
        x_0=x;
        x=x_0-(a*pow(x,3)-b*pow(x,2)+c*x+d)/(3*a*pow(x,2)-2*b*x+c);
    }while(fabs(x_0-x)>=1e-5);

    return x;
}
