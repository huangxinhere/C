#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("ax*2+bx+c=0\n");
    int a,b,c;
    float del,x1,x2;
    scanf("%d,%d,%d",&a,&b,&c);
    del=b*b-4*a*c;
    if(del>=0){
        x1=(-b+sqrt(del))/(2*a);
        x2=(-b-sqrt(del))/(2*a);
        if(x1==x2) printf("有两个相同的实根，x1=%0.1f,x2=%0.1f\n",x1,x2);
        if(x1!=x2) printf("有两个不同的实根，x1=%0.1f,x2=%0.1f\n",x1,x2);
    }

    return 0;
}
