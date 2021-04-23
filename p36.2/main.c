#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,t=0;
    int i;
    for(i=0;i<10;i++){
        scanf("%d",&n);
        if(n>t) t=n;
    }
    printf("max=%d\n",t);
    return 0;
}
