#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    int x,y,resultado=0;
    scanf("%d%d",&x,&y);
    resultado = Maior(x,y);
    printf("Maior: %d",resultado);
    return 0;
}
