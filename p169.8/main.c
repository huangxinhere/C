#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][3]={{8,1,6},{3,5,7},{4,9,2}};
    int i,j,m,n,current,flag;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            flag=0;
            current=a[i][j];
            for(m=0;m<3;m++){
                if(a[m][j]<current) break;
                else flag++;
            }
            for(n=0;n<3;n++){
                if(a[i][n]>current) break;
                else flag++;
            }
            if(flag==6) printf("%d ",a[i][j]);
        }
    }
    return 0;
}
