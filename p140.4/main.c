#include <stdio.h>
#include <stdlib.h>

int main()
{
    char in;
    int letter=0,space=0,number=0,other=0;
    for( ;in!='\n';){
        in=getchar();
        int a=in;
        if(in>='a'&&in<='z'||in>='A'&&in<='Z') letter++;
        else if(in==' ') space++;
        else if(a<='9'&&a>='0') number++;//�����á��������򲻷��ϣ��������Խ�������ַ�����ת��int
        else other++;
    }
    printf("letters:%d\nspaces:%d\nnumbers:%d\nothers:%d\n",letter,space,number,other);
    return 0;
}
