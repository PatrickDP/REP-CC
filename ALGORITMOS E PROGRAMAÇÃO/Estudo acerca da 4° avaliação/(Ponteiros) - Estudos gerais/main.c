#include <stdio.h>

int main()
{
    int *pti, i=10;
    pti = &i;
    printf("pti: %d & i: %d\n",*pti,i);
    *pti = 9; /*cuidado com pti = 9*/
    printf("pti: %d & i: %d\n",*pti,i);
    printf("pti: %d & i: %d\n",pti,&i); /*acessando o endereço*/
    return 0;
}
