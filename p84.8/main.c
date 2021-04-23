#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c1,c2;
    c1=getchar();//只能输入单个字符，不能将整数换成字符
    putchar(c1);//连续输入再按enter键字符才分别送到不同的变量之中
    c2=getchar();
    putchar(c2);
    printf("%5c,%c\n",c1,c2);
    //用printf函数输出ASCⅡ值
    //字符型一定是整型，整型不一定是字符型
    return 0;
}
