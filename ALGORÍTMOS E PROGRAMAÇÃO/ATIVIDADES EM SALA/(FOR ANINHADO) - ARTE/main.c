#include <stdio.h>

int main()
{
    int i=1,j=1,n;  /*i = LINHAS QUE É DADA PELA IMPRESSÃO '\n' A CADA LAÇO DE j*/
    scanf("%d",&n); /*j = SERÁ O NÚMERO DE COLUNAS, IMPRIMIDO EM SEQUENCIA N ASTERISCOS*/
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==1 || j==1 || i==n || j==n)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
