#include <stdio.h>

int main()
{
    int i=1,j=1,n;  /*i = LINHAS QUE � DADA PELA IMPRESS�O '\n' A CADA LA�O DE j*/
    scanf("%d",&n); /*j = SER� O N�MERO DE COLUNAS, IMPRIMIDO EM SEQUENCIA N ASTERISCOS*/
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
