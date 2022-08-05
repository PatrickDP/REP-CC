#include <stdio.h>

int main()
{
    int vector[5];
    int i=0,controle=0;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
    }
    printf("Valores do vetor:\n");
    for(i=0; i<5; i++)
    {
        printf("%d ",vector[i]);
    }
    printf("\n");
    vector[4];
    for(i=0; i<5; i++)
    {
        vector[i];
    }
    return 0;
}
