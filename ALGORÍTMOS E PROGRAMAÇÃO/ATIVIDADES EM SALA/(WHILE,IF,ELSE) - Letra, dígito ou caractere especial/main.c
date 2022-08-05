#include <stdio.h>

int main()
{
    char x;
    scanf("%c",&x);
    if(x >= 'A' && x <= 'z') /*Intervalo fechado entre A maisculo até z minúsculo*/
    {
        printf("Letra.\n");
    }
    else
    {
        if(x >= '0' && x <= '9')
            printf("Digito.\n");
        else if((x >= '!' && x<= '/') || (x >= ':' && x <= '@') || (x >= '[' && x <= '`') || (x >= '{' && x <= '~'))
            printf("Caractere especial.\n");
    }
    return 0;
}
