#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num;
    int a[7],Num;
    int i,j,k;
    int t;
    printf("Please input a number:\n");
    scanf("%f",&num);

    for(i=0;i<7;i++){
        Num=num;
        a[i]=Num;
        printf("a[%d] = %d ",i,a[i]);
        num=num-Num;
        num=num*10;
    }
    for(j=0;j<7;j++){
        for(k=j+1;k<7;k++){
            if(a[j]>a[k]){
                t=a[j],a[j]=a[k],a[k]=t;
            }
        }
    }
    num=0;
    for(i=0;i<7;i++){
        num=num+a[i]*pow(0.1,i);
    }
    printf("num=%f\n",num);
    return 0;
}
