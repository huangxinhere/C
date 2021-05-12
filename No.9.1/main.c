#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[]={128,100,89,81,99,191,85,119,255,200,198,23,21,32,10,49,98,23,123,234,190,99,190,88,68,97,105,64,25,156};
    int b[]={128,100,89,81,99,191,85,119,255,200,198,23,21,32,10,49,98,23,123,234,190,99,190,88,68,97,105,64,25,156};
    int i,j,m=30;

    for(j=0;j<=m-1-2;j++)
        asort(j,a,b);

    for(i=0;i<=m-1;i++)
        printf("%d ",b[i]);

    return 0;
}

void asort(int n,int a[],int b[])
{
    int i,j,tem,c[30]={0},m;
    //copy
    for(i=n;i<=n+2;i++)
        c[i]=a[i];
    //Ã°ÅÝ
    for(i=0;i<=1;i++)
    {
        m=n;
        for(j=0;j<2-i;j++,m++)
            if(c[m]>c[m+1]) tem=c[m],c[m]=c[m+1],c[m+1]=tem;
    }
    //Ìæ»»ÖÐÖµ
    b[n+1]=c[n+1];
}
