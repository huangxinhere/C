#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c1,c2;
    c1=getchar();//ֻ�����뵥���ַ������ܽ����������ַ�
    putchar(c1);//���������ٰ�enter���ַ��ŷֱ��͵���ͬ�ı���֮��
    c2=getchar();
    putchar(c2);
    printf("%5c,%c\n",c1,c2);
    //��printf�������ASC��ֵ
    //�ַ���һ�������ͣ����Ͳ�һ�����ַ���
    return 0;
}
