#include <stdio.h>

int main()
{
    int vetor[5];
    int i=0,indice=0;
    int number;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vetor[i]);
    }
    scanf("%d",&number);
    for(i=0; i<5; i++)
    {
        if(vetor[i] != number)
        {
            vetor[indice] = vetor[i];
            indice++;
        }
    }
    if(indice > 0 && indice <=4)
    {
        printf("Novo vetor: ");
        for(i=0; i<indice; i++)
        {
            printf("%d ",vetor[i]);
        }
    }
    else if(indice == 0)
    {
        printf("Nenhum valor a exibir.");
    }
    else if(indice > 4)
        printf("Valor nao encontrado.");
    return 0;
}
