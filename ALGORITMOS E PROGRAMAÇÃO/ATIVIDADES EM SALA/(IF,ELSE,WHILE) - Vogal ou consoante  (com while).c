#include <stdio.h>

int main()
{
    char var;
    while(var != '$')
    {
        scanf("%c ",&var); /*Espaçar os caracteres*/
        if(var == '$')
        {
            return 0;
        }
        else
        {
            if(var == 'a')
                printf("Vogal.\n");
            if(var == 'c')
                printf("Consoante.\n");
            else
                if(var != 'a' && var != 'c')
                printf("Nao e uma letra do alfabeto.\n");
        }
    }
    return 0;
}
