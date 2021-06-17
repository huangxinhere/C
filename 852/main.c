#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4]={0,2,1,0};
    printf("%d\n",peakIndexInMountainArray(a,4));
    return 0;
}
int peakIndexInMountainArray(int* arr, int arrSize){
    int i,max=arr[0],pos;
    for(i=1;i<arrSize;i++){
        if(arr[i]>max)
        {
            max=arr[i];
            pos=i;
        }
    }
    return pos;
}
