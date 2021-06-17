#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year=2021,month=5,day=26,days=0,first,d,i,j,n;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    printf("%d年的元旦为星期%d\n",year,date(year));
    first=date(year);
    switch(month)
    {
        case 1: days=day;break;
        case 2: days=31+day;break;
        case 3: days=31+28+day;break;
        case 4: days=31+28+31+day;break;
        case 5: days=31+28+31+30+day;break;
        case 6: days=31+28+31+30+31+day;break;
        case 7: days=31+28+31+30+31+30+day;break;
        case 8: days=31+28+31+30+31+30+31+day;break;
        case 9: days=31+28+31+30+31+30+31+30+day;break;
        case 10:days=31+28+31+30+31+30+31+30+31+day;break;
        case 11:days=31+28+31+30+31+30+31+30+31+30+day;break;
        case 12:days=31+28+31+30+31+30+31+30+31+30+31+day;break;
    }
    if(run(year)&&month>2)
        days++;
    printf("%d 年 %d 月 %d 日共 %d 天\n",year,month,day,days);
    if((first+days%7-1)<7)
        d=first+days%7-1;
    else
    {
        if((first+days%7-1)%7!=0)
            d=(first-1+days%7)%7;
        else
            d=7;
    }
    printf("该年的星期%d\n",d);

    for(i=0;i<12;i++)
    {
        printf("Num %d 月\n",i+1);
        printf("日\t一\t二\t三\t四\t五\t六\n");
        n=1;
        for(j=0;;j++)
        {
            if(j<first)
                printf("\t");
            else
            {
                printf("%d\t",n);
                n++,first++;
                if(first>6)
                    first=0,printf("\n");
                if(n>a[i])
                    break;
            }
        }
        printf("\n");
        printf("\n");

    }

    return 0;
}

int run(int year)
{
    if(year%100!=0&&year%4==0 || year%400==0)
        return 1;
    else
        return 0;
}
int date(int year)
{
    int date=1,i;
    for(i=1900;i<year;i++)
    {
        if(run(i))
            date+=2;
        else
            date++;
    }
    if(date>7)
        if(date%7!=0)
            return date=date%7;
        else
            return date=7;
    else
        return date;

}
