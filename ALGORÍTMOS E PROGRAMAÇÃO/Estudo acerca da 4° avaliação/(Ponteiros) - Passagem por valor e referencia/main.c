#include <stdio.h>
/*void troca_valor(int x, int y) //passagem por valor
{
    int temp=0;
    temp = x;
    x = y;
    y = temp;
    printf("Troca valor = %d & %d\n",x,y);
}*/
void troca_referencia(int *p, int *q) //passagem por referencia
{
    int temp=0;
    temp = *p;
    *p = *q;
    *q = temp;
    printf("Troca referencia = %d & %d\n",*p,*q);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Normal = %d & %d\n",a,b);
    /*troca_valor(a,b);*/
    troca_referencia(&a,&b);
    printf("Normal alterado = %d & %d\n",a,b);
    return 0;
}
