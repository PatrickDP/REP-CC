#include <stdio.h>

int main()
{
    int A[10][10];
    int i=0,j=0,soma=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            scanf("%d",&A[i][j]);

        }
    }
    printf("Matriz A:\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("Soma das linhas:\n");
    for(i=0; i<10; i++)
    {
        soma = 0;
        for(j=0; j<10; j++)
        {
            soma+= A[i][j];
        }
        printf("Linha %d: %d",i+1,soma);
        printf("\n");
    }
    return 0;
}
