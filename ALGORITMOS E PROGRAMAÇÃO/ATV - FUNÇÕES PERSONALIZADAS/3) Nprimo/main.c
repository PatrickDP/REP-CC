#include <stdio.h>
#include <locale.h>
#include "funcoes.h"

int main()
{
    setlocale(LC_ALL,"");
    int x;
    scanf("%d",&x);
    Nprimo(x);
    return 0;
}
