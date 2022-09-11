#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ano=0,dias=0,num; /* Dias fornecidos */
    scanf("%d",&num);
    ano = num/365;
    dias = num - (365 * ano);
    printf("%d ano(s) e %d dia(s)",ano,dias);
    return 0;
}
