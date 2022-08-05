#include <stdio.h>

int main()
{
    int vector[5],vt_frq[5];
    int i=0,j=0,frequencia=0;
    for(i=0; i<5; i++)
    {
        scanf("%d",&vector[i]);
        vt_frq[i] = 1; //Declarando como 1 para não deixar lixo
    }
    printf("A frequencia de todos os valores do vetor:\n");
    for(i=0; i<5; i++)
    {
        frequencia = 1;
        for(j=i+1; j<5; j++)
        {
            /*printf("vector[i] = %d | vector[j} = %d.\n",vector[i],vector[j]);*/
            if(vector[i] == vector[j])
            {
                frequencia++;
                vt_frq[j] = 0;
                printf("vt_frq = %d | j = %d\n",vt_frq[j],j);
            }
        }
        /*printf("vt_frq = %d\n",vt_frq[i]);*/
        if(vt_frq[i] != 0)
        {
            vt_frq[i] = frequencia;
        }
    }
    for(i=0; i<5; i++)
    {
        if(vt_frq[i] != 0)
        {
            printf("%d ocorre %d vezes\n",vector[i],vt_frq[i]);
        }
    }
    return 0;
}
