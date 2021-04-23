#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{//Vinegar  soy sauce
    char A[10] ,B[10] ,C[10];
    gets(A);
    gets(B);
    strcpy(C,A);
    strcpy(A,B);
    strcpy(B,C);
    printf("A=%s,B=%s\n",A,B);
    return 0;
}
