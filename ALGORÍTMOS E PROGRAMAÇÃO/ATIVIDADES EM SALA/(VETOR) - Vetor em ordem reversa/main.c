#include <stdio.h>

int main()
{
    int vector[5];
    int i=0,indice=4; /*Vetor de 5 posições, ultimo indice é 4*/
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
    for(i=0; i<5; i++)
    {
        printf("%d ",vector[indice]);
        indice--;
    }
    return 0;
}
