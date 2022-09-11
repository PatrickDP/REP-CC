#include <stdio.h>

int main()
{
    int i=0,j=0,es=0,controle=1,coluna=1,n;
    scanf("%d",&n);
    for(i=1; i<n*2; i++)
    {
        for(es=n; es>controle; es--)
        {
            printf(" ");
        }
        for(j=1; j<=coluna; j++)
        {
            if(j == 1 || j == coluna)
            {
                printf("*");
            }
            else
                printf(" ");
        }
        if(i<n)
        {
            controle++;
            coluna+=2;
        }
        else if(i>n || i==n)
        {
            controle--;
            coluna-=2;
        }
        printf("\n");
    }

    return 0;
}
