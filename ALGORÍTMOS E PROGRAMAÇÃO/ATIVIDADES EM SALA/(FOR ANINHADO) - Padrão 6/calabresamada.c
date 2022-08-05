#include <stdio.h>

int main()
{
    int i=0,j=0,aux=1,num;
    scanf("%d",&num);
    for(i=1; i<=num; i++)
    {
        for(j=num; j>i; j--)
        {
            printf("a");
        }
        printf("\n");
        aux+=2;
    }
    return 0;
}
