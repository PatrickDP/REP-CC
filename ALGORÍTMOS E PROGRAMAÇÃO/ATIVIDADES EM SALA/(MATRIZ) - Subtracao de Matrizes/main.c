#include <stdio.h>

int main()
{
    int a[10][10],b[10][10];
    int i=0, j=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("Matriz A:\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Matriz B:\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("Matriz resultante:\n");
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            a[i][j] = a[i][j] - b[i][j]; /*A matriz a se tornou resultante*/
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
