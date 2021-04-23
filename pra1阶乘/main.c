#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    int result;
    int flag=1;
    //scanf("%d,%d",&m,&n);
    while(flag){
            scanf("%d,%d",&m,&n);
        if (m>n||m<0){
            printf("please input again:(0<m<n)\n");
        }
        else break;
    }
    result=multi(n)/(multi(m)*multi(n-m));
    printf("result=%d\n",result);

    return 0;
}
int multi(int n){
    int total=1;
    int i;
    for(i=n;i>=1;i--){
        total = total*i;
    }
    return total;

}
