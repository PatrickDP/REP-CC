#include <stdio.h>

int main()
{
    int v1[5],v2[5],v3[10];
    int controle=0,indice=5,i=0,j=0;
    for(i=0; i<5; i++)
    {
        scanf("%d",&v1[i]);
    }
    for(i=0; i<5; i++)
    {
        scanf("%d",&v2[i]);
        v3[i] = v1[i];
        v3[indice] = v2[i];
        indice++;
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<9; j++)
        {
            if(v3[j] < v3[j+1])
            {
                controle = v3[j];
                v3[j] = v3[j+1];
                v3[j+1] = controle;
            }
        }
    }
    printf("Os vetores agrupados de ordem decrescente:\n");
    for(i=0; i<10; i++)
    {
        printf("%d   ",v3[i]);
    }
    return 0;
}
