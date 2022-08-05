#include <stdio.h>

int main()
{
    int valor,conta_po=0,i=0;
    float num;
    scanf("%d",&valor);
    while(i<valor)
    {
        scanf("%f",&num);
        if(num > 0)
            conta_po++;
        i++;
    }
    printf("%d valores positivos",conta_po);
    return 0;
}
