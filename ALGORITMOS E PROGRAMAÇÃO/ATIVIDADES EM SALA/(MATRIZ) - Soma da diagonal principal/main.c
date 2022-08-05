#include <stdio.h>

int main()
{
    int A[10][10],DIG[10]; /*DIG = receberá os valroes da diagonal principal*/
    int i=0,j=0,d=0,soma=0; /*d = diagonal principal*/
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            scanf("%d",&A[i][j]);
        }
        DIG[i] = 0;
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(A[i][j] == A[i][d])
            {
                DIG[i] = A[i][j];
            }
        }
        soma+=DIG[i];
        d++;
    }
    printf("Soma da diagonal da matriz: \n%d\n",soma);
    return 0;
}
