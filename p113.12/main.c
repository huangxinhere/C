#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    scanf("%f,%f",&x,&y);
    if((x-2)*(x-2)+(y-2)*(y-2)<=1||(x+2)*(x+2)+(y-2)*(y-2)<=1||(x+2)*(x+2)+(y+2)*(y+2)<=1||(x-2)*(x-2)+(y+2)*(y+2)<=1||
       x==2&&y==2||x==2&&y==-2||x==-2&&y==2||x==-2&&y==-2){
        printf("hight=%d\n",10);
    }else{
        printf("hight=%d\n",0);
    }
    return 0;
}
