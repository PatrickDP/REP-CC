#include <stdio.h>

int main()
{
    int v1[5],v2[5];
    int i=0,indice=0; /*i é considerado o indice do vetor*/
    int m;
    for(i=0; i<5; i++)
    {
        scanf("%d",&v1[i]);
    }
    scanf("%d",&m);
    for(i=0; i<5; i++)
    {
        if(v1[i] != m)
        {
            v2[indice] = v1[i];
            indice++;
        }
    }
    //printf("Indice: %d",indice);
    if(indice == 0)
    {
        printf("Nenhum valor a exibir.\n");
    }
    else if(indice > 0 && indice <= 4)
    {
        printf("Novo vetor: ");
        for(i=0; i<indice; i++)
        {
            printf("%d ",v2[i]);
        }
    }
    else if(indice > 4)
        printf("Valor nao encontrado.\n");
    return 0;
}
