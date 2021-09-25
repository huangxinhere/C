#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,count=0,a[20]={0};
    while(1)
    {
        printf("输入一个大于10的偶数：\n");
        scanf("%d",&n);
        if(n>10&&n%2==0) break;
    }

    for(i=2;i<=n/2;i++)
        if(ifSu(i))
            if(ifSu(n-i))
                a[count]=i,count++;

    for(i=0;i<count;i++)
    {
        printf("%d=%d+%d",n,a[i],n-a[i]);
        printf("\n");
    }

    return 0;
}

int ifSu(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}
