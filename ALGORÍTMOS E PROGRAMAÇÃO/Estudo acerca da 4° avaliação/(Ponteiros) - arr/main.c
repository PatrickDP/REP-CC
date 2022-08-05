#include <stdio.h>
#include <stdlib.h>

int main()
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0]; //aponta para a primeira posição do vetor*/
    float *ptr2 = ptr1 + 2; //somando a primeira posição + 2 = (terceira posicao) 13.5;

    printf("%f\n", *ptr2); //valor da terceira posicao;
    printf("%d\n", ptr2-ptr1); //subtracao da 3 posicao com a primeira (2 - 0) = 2
    return 0;
}
