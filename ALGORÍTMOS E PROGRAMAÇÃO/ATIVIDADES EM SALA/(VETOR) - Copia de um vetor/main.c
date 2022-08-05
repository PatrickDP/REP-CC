#include <stdio.h>

int main()
{
    int A[10],S[10];
    int i=0,indice=0;
    int X;
    for(i=0 ; i<10; i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&X);
    for(i=0; i<10; i++)
    {
        if(A[i] > X)
        {
            S[indice] = A[i]; /*Indice irá descrever N posições do vetor*/
            indice++;
        }
    }
    if(indice > 0)
    {
        printf("Novo vetor:\n");
        for(i=0; i<indice; i++)
        {
            printf("%d ",S[i]); /*O vetor exibe o valor conforme i*/
        }
    }
    printf("\n");
    return 0;
}
