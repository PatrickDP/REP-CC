#include <stdio.h>

int main()
{
    int i=0,j=0,coluna=1,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=coluna; j++)
        {
         printf("*");
        }
        printf("\n");
        coluna+= 2;
    }
    return 0;
}
