#include <stdio.h>

int minVetor(int *v, int t, int *pointer)
{
    int i;
    *pointer = 1;
    for(i=0; i<t; i++)
    {
        if(v[i] < *pointer)
        {
            *pointer = v[i];
        }
    }
    return *pointer;
}
int main()
{
    int arr[10],tamanho=10;
    int i,p;
    for(i=0; i<tamanho; i++)
    {
        scanf("%d",&arr[i]);
        minVetor(arr,tamanho,&p);
    }
    printf("Menor valor : %d\n",p);
    return 0;
}
