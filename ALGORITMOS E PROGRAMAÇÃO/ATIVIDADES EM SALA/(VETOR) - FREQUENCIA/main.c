#include <stdio.h>

int main()
{
    int vector[5],vt_freq[5];
    int i=0,j=0,conta_freq=1,indice=0;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
        vt_freq[i] = 0;
    }
    printf("A frequencia de todos os valores do vetor:\n");
    for(i=0; i<5; i++)
    {
        for(j=i; j<4; j++)
        {
            //printf("i = %d | j+1 = %d | conta_freq = %d\n",vector[i],vector[j+1],conta_freq);
            if(vector[i] == vector[j+1])
            {
                conta_freq++;
                vt_freq[i] = vector[i];
            }
        }
        for(j=i; j<i+1; j++)
        {
                printf("%d ocorre %d vezes\n",vector[j],conta_freq);
        }
        conta_freq = 1;
    }
    return 0;
}
