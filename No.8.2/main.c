#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20]={0,1},b[20]={0,1};
    int count=2,i,j;
    for(j=0;j<=9;j++){
        for(i=1;i<count;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        count++;
        for(i=1;i<count-1;i++){
            b[i]=a[i]+a[i-1];
        }
        b[count-1]=1;
        for(i=1;i<count;i++){
            a[i]=b[i];
        }
    }

    return 0;
}
