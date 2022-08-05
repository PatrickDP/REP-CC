#include <stdio.h>

int main()
{
    int A[10][10],vetor_MAT[100];
    int i=0,j=0,controle=0,indice=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            scanf("%d",&A[i][j]);
            vetor_MAT[indice] = A[i][j];
            indice++;
        }
    }
    /*printf("\n");
    printf("INDICE (MATRIZ P/ VETOR) = %d\n",indice);*/
    for(i=0; i<indice; i++)
    {
        for(j=i; j<indice-1; j++)
        {
            if(vetor_MAT[i] < vetor_MAT[j+1])
            {
                controle = vetor_MAT[j+1];
                vetor_MAT[j+1] = vetor_MAT[i];
                vetor_MAT[i] = controle;
            }
        }
    }
    indice = 0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            A[i][j] = vetor_MAT[indice];
            indice++;
        }
    }
    printf("Maior valor da matriz:\n");
    for(i=0; i<1; i++)
    {
        for(j=0; j<1; j++)
        {
            printf("%d",A[i][j]);
        }
    }
    /*printf("\n");
    printf("INDICE (VETOR P/ MATRIZ) = %d\n",indice);
    printf("\n");*/

    return 0;
}
