#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n%3==0&&n%5==0){
        printf("%d����ͬʱ��3��5����\n",n);
    }else printf("����ͬʱ��3��5����\n");
    return 0;
}
