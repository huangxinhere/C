#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a[6],i=1,n,j;
    scanf("%d",&n);
    while(1){
        int b=n/pow(10,i-1);
        a[i]=b%10;//invalid operands to binary:double���Ͳ���ʹ��%��������ȡ�����㡣������û��%�������%ֻ��������������
        if(a[i]!=0){
          printf("%d\t",a[i]);
        }else break;
        i++;
    }
    printf("\nthe total is %d\n",i-1);
    for(j=1;j<i;j++) printf("%d",a[j]);
    return 0;
}
