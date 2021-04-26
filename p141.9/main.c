#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,sum,a[50],count;
    for(i=2;i<=1000;i++){
        sum=0,count=0;
        for(j=1;j<i;j++){
           if(i%j==0) sum+=j,a[count]=j,count++;
        }
        if(sum==i){
           printf("%d its factors are ",sum);
           j=0;
           while(a[j]!=0&&j<count){
              if(j==count-1) printf("%d\n",a[j]),j++;
              else printf("%d,",a[j]),j++;
           }
        }
    }
    return 0;
}
