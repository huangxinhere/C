#include <stdio.h>
#include <stdlib.h>
int i,j;
float total;
int main()
{
    int n;
    int score[2][3]={0};

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&n);
            score[i][j]=n;
        }
    }
    student_average(score);
    sub_average(score);
    max_score(score);
    fang_cha(score);

    return 0;
}

void student_average(int a[][3])
{
    for(i=0;i<2;i++)
    {
        total=0;
        for(j=0;j<3;j++)
        {
            total+=a[i][j];
        }
        printf("student %d 's average is %f\n",i+1,total/3);
    }
}
void sub_average(int a[][3])
{
    for(j=0;j<3;j++)
    {
        total=0;
        for(i=0;i<2;i++)
            total+=a[i][j];
        printf("subject %d 's average is %f\n",j,total/2);
    }

}
void max_score(int a[][3])
{
    int max=0,x,y;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                x=i,y=j;
            }
    printf("the max score is %d,in %d,%d\n",max,x,y);
}
void fang_cha(int a[][3])
{
    float b[2],sum,c=0,d=0;
    for(i=0;i<2;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
            sum+=a[i][j];
        b[i]=sum/3;
    }
    for(i=0;i<2;i++)
        c+=b[i]*b[i],d+=b[i];
    printf("fang_cha is %0.3f\n",c/2-(d/2)*(d/2));

}
