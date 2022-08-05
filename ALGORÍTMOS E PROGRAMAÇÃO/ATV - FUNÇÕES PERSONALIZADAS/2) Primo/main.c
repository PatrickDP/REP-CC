#include <stdio.h>
#include <locale.h>
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL,"");
    int x,resultado=0;
    scanf("%d",&x);
    resultado = Primo(x);
    if(resultado == 1)
    {
        printf("É primo.");
    }
    else
    {
        printf("Não é primo.");
    }
    return 0;
}
