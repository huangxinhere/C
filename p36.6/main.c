#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,flag;
    for(n=100;n<201;n++){
            flag=0;
            i=n/2;
        while(i>1){
            if(n%i==0){
                flag=1;
                break;
            }
            i--;
        }
        if(flag == 1) printf("%d\n",n);
    }
    return 0;
}
