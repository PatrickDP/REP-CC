#include <stdio.h>

int main()
{
    int A[10][10];
    int i=0,j=0,controle=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Maior de cada linha:\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<9; j++) //Bubble sort para ordenação de matrizes, mas em cada linha e não na matriz inteira
        {
            if(A[i][j] > A[i][j+1])
            {
                controle = A[i][j+1];
                A[i][j+1] = A[i][j];
                A[i][j] = controle;
            }
        }
        printf("Linha %d: %d\n",i+1,A[i][j]);
    }
    return 0;
}
