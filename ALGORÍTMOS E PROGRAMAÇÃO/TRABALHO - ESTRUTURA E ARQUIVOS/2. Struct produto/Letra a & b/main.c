#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Produto
{
    char nome[30];
    int codigo;
    double preco;
} p;

int main()
{
    setlocale(LC_ALL,"");
    int i=0;
    struct Produto p[10]; /*Letra: a*/
    strcpy(p[0].nome,"Pe de Moleque"); /*Letra: b*/
    p[0].codigo = 13205;
    p[0].preco = 0.20;
    strcpy(p[1].nome,"Cocada Baiana");
    p[1].codigo = 15202;
    p[1].preco = 0.50;
    for(i=0; i<2; i++)
    {
        printf("___\n");
        printf("Nome do produto %d: %s\n",i+1,p[i].nome);
        printf("Codigo: %d\n",p[i].codigo);
        printf("Preço: R$%.2lf\n",p[i].preco);
    }
    for(i=2; i<10; i++)
    {
        printf("\nNome do produto %d: ",i+1); fflush(stdin); scanf("%[^\n]",p[i].nome);
        printf("Código: "); scanf("%d",&p[i].codigo);
        printf("Preço: "); scanf("%lf",&p[i].preco);
    }
    return 0;
}
