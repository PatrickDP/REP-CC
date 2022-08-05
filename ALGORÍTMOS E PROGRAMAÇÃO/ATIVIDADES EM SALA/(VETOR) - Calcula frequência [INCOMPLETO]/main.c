#include <stdio.h>

int main()
{
    int vector[5];
    int i=0,j=0,k=0,frequencia=0;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
    }
    printf("A frequencia de todos os valores do vetor:\n");
    for(i=0; i<5; i++)
    {
        frequencia = 1;
        for(j=i+1; j<5; j++)
        {
            if(vector[i] == vector[j])
            {
                frequencia++;
            }
        }
        printf("%d ocorre %d vezes\n",vector[i],frequencia);
    }
    return 0;
}
