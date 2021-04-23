#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n%3==0&&n%5==0){
        printf("%d可以同时被3和5整除\n",n);
    }else printf("不可同时被3和5整除\n");
    return 0;
}
