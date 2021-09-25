#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[25]={1,1},i;
    double sum=0;

    febo(a);
    for(i=1;i<=20;i++)
        sum+=a[i+1]/(double)a[i];

    printf("the result is %lf.\n",sum);
    return 0;
}

void febo(int a[])
{
    int i;
    for(i=2;i<25;i++)
        a[i]=a[i-1]+a[i-2];
}

//此题是第71题，创建项目时命名出错
