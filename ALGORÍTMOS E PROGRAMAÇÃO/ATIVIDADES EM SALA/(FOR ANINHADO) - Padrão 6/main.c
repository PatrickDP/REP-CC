#include <stdio.h>

int main()
{
    int i=0,j=0,es=0,coluna=1,num; /*es = variavel que conta espaços*/
    scanf("%d",&num);              /*coluna = variavel que controla n quantidade colunas consecutivas*/
    for(i=1; i<=num; i++)
    {
        for(es=num; es!=i; es--)
        {
            printf(" ");
        }
        for(j=1; j<=coluna; j++)
        {
            if(i==num || j==1 || j==coluna)
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
        coluna+= 2;
    }
    return 0;
}
