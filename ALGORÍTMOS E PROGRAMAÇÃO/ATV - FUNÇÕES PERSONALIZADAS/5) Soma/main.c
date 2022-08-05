#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    int x,y,resultado=0;
    scanf("%d%d",&x,&y);
    resultado = Soma(x,y);
    printf("Soma = %d",resultado);
    return 0;
}
