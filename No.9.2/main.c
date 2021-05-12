#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[200]={0},b[200]={0},temp1[200]={0},temp2[200]={0},result[200]={0},lena,lenb,max;
    int i,count=0;
    char a1[200],b1[200];
    gets(a1);
    gets(b1);
    lena=strlen(a1),lenb=strlen(b1);
    max=lena>lenb?lena:lenb;

    for(i=0;i<lena;i++)
       a[i]=a1[i]-48;
    for(i=0;i<lenb;i++)
       b[i]=b1[i]-48;
    for(i=0;i<max;i++)
    {
        temp1[i]=a[lena-1-i];
        temp2[i]=b[lenb-1-i];
    }
    for(i=0;i<max;i++)
    {
       result[i]=temp1[i]+temp2[i]+count;
       if(result[i]>=10)
       {
           result[i]=result[i]%10;
           count=1;
           if(result[i+1]==0) result[i+1]=1;
       }else count=0;
    }

    if(result[max]!=0) printf("%d",result[max]);
    for(i=max-1;i>=0;i--)
        printf("%d",result[i]);

    return 0;
}
