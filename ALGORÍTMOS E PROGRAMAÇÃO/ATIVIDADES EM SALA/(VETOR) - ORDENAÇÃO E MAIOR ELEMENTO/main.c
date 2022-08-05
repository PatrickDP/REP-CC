#include <stdio.h>

int main()
{
    int vector[5];
    int i=0,j=0,controle=0;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
    }
    printf("Ordenacao em ordem decrescente:\n");
    for(i=0; i<5; i++)
    {
        for(j=i+1; j<4; j++)
        {
            if(vector[i] < vector[j+1])
            {
                controle = vector[j+1];
                vector[j+1] = vector[i];
                vector[i] = controle;
            }
        }
        printf("%d ",vector[i]);
    }
    printf("\n");
    for(i=0; i<1; i++)
    {
            printf("Maior valor : %d\n",vector[i]);
    }
    return 0;
}
