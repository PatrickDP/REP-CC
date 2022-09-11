#include <stdio.h>

int main()
{
    int num,contador=0;
    scanf("%d",&num);
    while(num!=0)
    {
        num = num/10;
        contador++;
    }
    printf("Digitos: %d",contador);
    return 0;
}
