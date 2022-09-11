#include <stdio.h>

int main()
{
    int vector[10];
    int i=0,j=0,duplica=0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&vector[i]);
    }
    for(i=0; i<10; i++)
    {
        for(j=i; j<9; j++) /*O segundo for vai prender determinado número para ver se há um valor duplicado*/
        {
            /*printf("\nControle = %d Vector = %d\n",vector[i],vector[j],j,duplica);*/
            if(vector[i] == vector[j+1])
            {
                duplica++;
                if(duplica > 10) /*caso duplica for maior que 5, valor máximo de duplicados*/
                {
                    duplica = 0;
                }
            }
        }
    }
    printf("O total de valores duplicados: %d",duplica);
    return 0;
}
