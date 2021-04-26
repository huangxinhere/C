#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,result=1,result1;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        for(j=1,result1=1;j<=i;j++) result1*=j;
        result+=result1;
    }
    printf("%d\n",result);
    return 0;
}
