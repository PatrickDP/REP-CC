#include <stdio.h>

int main()
{
    char var;
    do
    {
        scanf("%c ",&var);
        if(var == '$')
        {
            break;
        }
        else
        {
            if(var == 'a')
                printf("Vogal.\n");
            if(var == 'c')
                printf("Consoante.\n");
            else if(var != 'a' && var != 'c')
                printf("Nao e uma letra do alfabeto.\n");
        }
    }
    while(var != '$');
    return 0;

}
