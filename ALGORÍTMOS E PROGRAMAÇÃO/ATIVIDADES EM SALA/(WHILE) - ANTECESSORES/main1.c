#include <stdio.h>

int main()
{
    int m,n,i=0,s=0;
    scanf("%d%d",&m,&n);
    s = m;
    m = m - n;
    while(i<n) /*Não quero que exiba m na saida dos números*/
    {
        printf("%d ",m);
        m++;
        i++;
    }
    i = 0; /*Para zerar o valor final de "i" do primeiro while*/
    while(i<n)
    {
        m++;
        printf("%d ",m);
        i++;
    }
    printf("\n%d",s);
    return 0;
}
/* s = saida de m */
/* n = quant. de numero antecessores/sucessores de m*/
