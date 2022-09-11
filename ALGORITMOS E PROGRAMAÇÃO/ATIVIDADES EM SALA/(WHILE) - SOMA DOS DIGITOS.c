#include <stdio.h>

int main()
{
    int num,soma=0;
    scanf("%d",&num);
    while(num!=0)
    {
        soma+=num%10;
        num = num/10;
    }
    printf("Soma: %d",soma);
    return 0;
}
