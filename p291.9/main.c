#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int *p,t,i,j;
    for(i=0;i<3;i++)
    {
        for(j=i;j<3;j++)
        {
            t=*(a[i]+j),
            *(a[i]+j)=*(a[j]+i),
            *(a[j]+i)=t;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}
