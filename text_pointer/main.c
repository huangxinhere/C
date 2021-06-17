#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1,b=2;
    int *p1=&a,*p2=&b;
    swap(p1,p2);
    printf("%d %d\n",*p1,*p2);
    return 0;
}

void swap(int *t1,int *t2)
{
    int t;
    t=*t1,*t1=*t2,*t2=t;
}
//想交换地址，不可。因为地址传给形参，实际上也没交换成功
