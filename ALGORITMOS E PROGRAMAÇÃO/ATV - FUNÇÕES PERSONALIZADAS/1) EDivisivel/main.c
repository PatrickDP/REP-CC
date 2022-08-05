#include <stdio.h>
#include <locale.h>
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL,"");
    int x,y,resultado=0;
    scanf("%d%d",&x,&y);
    resultado = Edivisivel(x,y);
    {
        if(resultado == 1)
        {
            printf("É divisivel.");
        }
        else if(resultado == 0)
            printf("Nao é divisível.");
    }
    return 0;
}
