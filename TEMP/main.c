#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,t;
    n=100;
     while(n<200)
     {
         t=1;
         i=2;
         while(i<n/2)
         {
             if(n%i==0)
             {
                 t=0;
                 break;
             }
             //if(n%i!=0)printf("%d",n);
             i=i+1;
         }
         if(t!=0)printf("%d,",n);
         n=n+1;
     }
    return 0;

}
