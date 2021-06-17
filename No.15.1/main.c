#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *month[12]={"January","February","March","April","May","June",
        "July","August","September","October","November","December"};
    char *year[5]={"Two Thousand"};
    //第几
    char *day[31]={"First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Ninth","Tenth",
                   "Eleventh","Twelfth","Thirteenth","Fourteenth","Fifteenth","Sixteenth","Seventeenth","Eighteenth","Nineteenth","Twentieth",
                   "Twenty-first","Twenty-second","Twenty-third","Twenty-fourth","Twenty-fifth","Twenty-sixth","Twenty-seventh","Twenty-eighth",
                   "Twenty-ninth","Thirtieth","Thirtieth-first"};
    //不是序数
    char *year2[]={"one","two","three","four","fine","six","seven","eight","nine"};
    char *year1[]={"Twenty-","Thirty-","Forty-","Fifty-","Sixty-","Seventy-","Eighty-","Ninety-"};
    char *str[]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    char str3[99][14]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen",'\0'};

    int y,m,d,y1,y2,i,j,count=19;//第19个元素是20
    for(i=0;i<8;i++,count++)
    {
        strcpy(str3[count],str[i]);
        for(j=0;j<9;j++)
        {
            count++;
            strcpy(str3[count],year1[i]);
            strcat(str3[count],year2[j]);
        }
    }
    scanf("%d.%d.%d",&y,&m,&d);
    y2=y%100;
    y1=(y-y2)/100;
    if(y1==20)
        printf("%s %s, %s %s\n",month[m-1],day[d-1],year[0],str3[y2-1]);
    else printf("%s %s, %s %s\n",month[m-1],day[d-1],str3[y1-1],str3[y2-1]);
    return 0;
}
