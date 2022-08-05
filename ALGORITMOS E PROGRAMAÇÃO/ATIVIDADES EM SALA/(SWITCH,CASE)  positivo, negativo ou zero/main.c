#include <stdio.h>

int main()
{
    int num;
    scanf("%d",&num);
    switch(num)
    {
    case 0:
        printf("%d e zero\n",num);
        break;
    case 2:
        printf("%d e positivo\n",num);
        break;
    case -2:
        printf("%d e negativo\n",num);
        break;
    default: /*Funciona como um ELSE*/
        printf("%d e positivo\n",num);
    }
    return 0;
}
