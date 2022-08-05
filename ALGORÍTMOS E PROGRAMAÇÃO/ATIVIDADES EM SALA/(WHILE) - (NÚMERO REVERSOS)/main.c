#include <stdio.h>

int main()
{
    int num;
    int i=1,contador=1;
    scanf("%d",&num);
    printf("De %d a %d: %d ",num,i,num);
    while(i<num)
    {
        printf("%d ",num - contador);
        contador++;
        i++;
    }
    return 0;
}
