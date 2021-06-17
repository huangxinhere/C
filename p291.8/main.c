#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[20]={'\0'};
    char *p,n;
    int i,num=0,Letters=0,letters=0,space=0,others=0;
    gets(a);
    for(p=a;*p!='\0';p++)
    {
        n=*p;
        if(n>='0'&&n<='9') num++;
        else if (n>='A'&&n<='Z') Letters++;
        else if(n>='a'&&n<'z') letters++;
        else if(n==' ') space++;
        else others++;
    }
    printf("num=%d\n Letters=%d\n letters=%d\n space=%d\n others=%d\n",num,Letters,letters,space,others);
    return 0;
}
