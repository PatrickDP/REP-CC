#include <stdio.h>

int main()
{
    int num,saida=0,fatorial=1;
    scanf("%d",&num);
    saida = num;
    while(num != 0) /*Quando num for igual a zero, a estrutura encerra*/
    {
        fatorial = fatorial * num;
        num--;
    }
    printf("%d! = %d",saida,fatorial);
    return 0;
}
