#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n,result;
    scanf("%lf",&n);
    while(n<=0||n>=1000){
        printf("please input a number between 0,1000:\n");
        scanf("%lf",&n);
    }
    printf("result = %0.0f\n",result = sqrt(n));
    return 0;
}
