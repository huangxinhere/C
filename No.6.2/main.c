#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a[100],m,n;
    while(m>=n||m<1||n>10000){
        printf("please input m/n,m<n,m>=1,n<=10000:\n");
        scanf("%d,%d",&m,&n);
    }
    for(a[0]=1,a[1]=1,i=2;i<n;i++){
        a[i]=a[i-1]+a[i-2];
        if(a[i]>=m&&a[i]<=n){
            printf("%d ",a[i]);
        }
    }
    return 0;
}
