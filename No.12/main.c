#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year=2021,month=3,day=17,days=0,mon,date;
    mon=monday(year);
    switch(month)
    {
        case 1:  days=day;break;
        case 2:  days=31+day;break;
        case 3:  days=31+28+day;break;
        case 4:  days=31+28+31+day;break;
        case 5:  days=31+28+31+30+day;break;
        case 6:  days=31+28+31+30+31+day;break;
        case 7:  days=31+28+31+30+31+30+day;break;
        case 8:  days=31+28+31+30+31+30+31+day;break;
        case 9:  days=31+28+31+30+31+30+31+30+day;break;
        case 10: days=31+28+31+30+31+30+31+30+31+day;break;
        case 11: days=31+28+31+30+31+30+31+30+31+30+day;break;
        case 12: days=31+28+31+30+31+30+31+30+31+30+31+day;break;
    }
    if(ifRun(year))
        days+=1;
    printf("¹²%dÌì\n",days);
    if((days-1)+mon>7)
    {
        if(((days-1)+mon)%7!=0)//5+3
            date=((days-1)+mon)%7;
        else
            date=7;
    }
    else
        date=(days-1)+mon;
    printf("ĞÇÆÚ%d\n",date);



    return 0;
}
int ifRun(int year)
{
    if(year%100!=0&&year%4==0 || year%400==0)
        return 1;
    else
        return 0;
}
int monday(int n)
{
    int date=1,i;
    for(i=1901;i<=n;i++)
    {
        if(ifRun(i))
            date+=2;
        else
            date+=1;
    }
    if(date>7)
        date=date%7;
        if(date==0)
            return 7;
    else
        return date;
}

