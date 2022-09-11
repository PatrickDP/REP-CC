#include <stdio.h>

int main()
{
    int i=0,vector[5];
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
    }
    printf("Valores armazenados no vetor:\n");
    for(i=0; i<5; i++)
    {
        printf("%d ",vector[i]);
    }
    printf("\nValores armazenados no vetor em ordem reversa:\n");
    for(i=4; i!=-1; i--) /*i = 4 indica o último índice do vetor*/
    {
        printf("%d ",vector[i]);
    }
    return 0;
}
