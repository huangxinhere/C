#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float mid,high=10,low=-10,result;
    while(1){
        mid=(high+low)/2.0;
        result=2*pow(mid,3)-4*pow(mid,2)+3*mid-6;
        if(fabs(result)<1e-5){
            printf("the root = %f\n",mid);
            break;
        }
        else if(result>0)
            high=mid;
        else
            low=mid;
    }
    printf("the result is %f\n",result);
    return 0;
}
