#include <stdio.h>

int main()
{
    int v1[5],v2[5];             /*positron = contador de posicoes absoluto*/
    int i=0,contap=0;            /*i = indice/posicao, ultimo indice = posicao - 1*/
    for(i=0; i<5; i++)           /*contap = contador de posicoes quando os valores delas forem iguais*/
    {
        scanf("%d",&v1[i]);
    }
    for(i=0; i<5; i++)
    {
        scanf("%d",&v2[i]);
    }
    for(i=0; i<5; i++)
    {
        if(v1[i] == v2[i])
        {
            contap++;
        }
    }
    //printf("contap = %d",contap);
    if(contap > 0)
    {
        printf("V1 e V2 possuem iguais nas posicoes: ");
        for(i=0; i<5; i++)
        {
            if(v1[i] == v2[i])
            {
                printf("%d",i+1); /*Considerando a contagem de posição e 1 até n*/
                if(i < contap-1) /*Para todos os casos de i menos que o contador de posições*/
                {
                    printf(", ");
                }
                else
                {
                    printf(".");

                }
            }
        }
    }
    else
    {
        printf("Nao existem valores iguais.\n");
    }
    return 0;
}
