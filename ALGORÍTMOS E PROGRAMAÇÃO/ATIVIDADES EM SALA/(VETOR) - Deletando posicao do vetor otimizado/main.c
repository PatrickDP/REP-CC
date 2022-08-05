#include <stdio.h>

int main()
{
    int vector[5];
    int i=0,controle=0;
    int x;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
    }
    scanf("%d",&x);
    for(i=0; i<5; i++)
    {
        if(vector[i] != x)
        {
            vector[controle] = vector[i];
            controle++;
        }
    }
    for(i=0; i<controle; i++)
    {
        printf("%d ",vector[i]);
    }

    return 0;
}
