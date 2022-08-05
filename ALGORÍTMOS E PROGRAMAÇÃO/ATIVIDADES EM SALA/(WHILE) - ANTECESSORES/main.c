#include <stdio.h>

int main()
{
    int m,n;
    int i=0,ant=0,suc=0;
    scanf("%d%d",&m,&n);
    ant = m - n;
    suc = m;
    while(i<n) /*Não quero que exiba m na saida dos números*/
    {
        printf("%d ",ant);
        ant++;
        i++;
    }
    i = 0; /*Para zerar o valor final de "i" do primeiro while*/
    while(i<n)
    {
        suc++;
        printf("%d ",suc);
        i++;
    }
    printf("\n%d",m);
    return 0;
}
/*ant = variavel de numeros antecessores de m*/
/*suc = variavel de numeros sucessores de m*/
/*n = quant de numero de antecessores/sucessores de m*/
