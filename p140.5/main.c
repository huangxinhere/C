#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,n,i;
    float current=0;//��powʱfloat�ž�ȷ
    printf("�ֱ���������a��λ��n��\n");
    scanf("%d,%d",&a,&n);
    for(i=0;i<n;i++){
        current+=a*pow(10,i);
        if(i==n-1) printf("%0.0f\n",current);
        else printf("%0.0f+",current);
    }
    return 0;
}
