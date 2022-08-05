#include <stdio.h>
#include <funcoes.h>

int main()
{
    int p,i,maior=0; /*p = numero de posicao*/
    scanf("%d",&p);
    int vetor[p];

    for(i=0; i<p; i++)
    {
        scanf("%d",&vetor[i]);
        maior = encontrarMaxElem(vetor,p);
    }
    printf("Maior: %d",maior);
    return 0;
}
