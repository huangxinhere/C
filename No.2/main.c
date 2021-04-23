#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f,t;
    scanf("%d,%d,%d,%d,%d,%d",&a,&b,&c,&d,&e,&f);
    if(a>b) t=a,a=b,b=t;
    if(a>c) t=a,a=c,c=t;
    if(a>d) t=a,a=d,d=t;
    if(a>e) t=a,a=e,e=t;
    if(a>f) t=a,a=f,f=t;
    if(b>c) t=b,b=c,c=t;
    if(b>d) t=b,b=d,d=t;
    if(b>e) t=b,b=e,e=t;
    if(b>f) t=b,b=f,f=t;
    if(c>d) t=c,c=d,d=t;
    if(c>e) t=c,c=e,e=t;
    if(c>f) t=c,c=f,f=t;
    if(d>e) t=d,d=e,e=t;
    if(d>f) t=d,d=f,f=t;
    if(e>f) t=e,e=f,f=t;
    printf("%d,%d,%d,%d,%d,%d\n",a,b,c,d,e,f);

    return 0;
}
