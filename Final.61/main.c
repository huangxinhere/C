#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",func(n));
    return 0;
}
int func(int n)
{
    if(n==1)
        return 1;
    else
        return n*func(n-1);
}

//�����ǵ�71�⣬������Ŀʱ��������
