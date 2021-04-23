#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float h,sum;
    int i;
    printf("Please input the height:\n");
    scanf("%f",&h);
    printf("Please input the times:\n");
    scanf("%d",&n);
    sum=h;
    for(i=0;i<n;i++){
        sum=sum+h;
        h=h/2;
    }
    printf("sum=%0.1f,height=%0.1f \n",sum,h);
    return 0;
}
