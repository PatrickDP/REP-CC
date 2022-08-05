#include <stdio.h>
#include "funcoes.h"

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("Normal: a = \"%d\" & b = \"%d\"\n",x,y);
    Troca(&x,&y); /*Acessara o endereco com valor contido da variavel*/
    return 0;
}
