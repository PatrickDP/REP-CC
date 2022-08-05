#include <stdio.h>

int main()
{
    int num;
    scanf("%d",&num);
    switch(num)
    {
    case 0:
        if(num != 0)
        printf("Case 0:\n");
    case 1:
        if(num != 0 && num != 1)
        printf("Case 1:\n");
    case 2:
        if(num != 1 && num != 2)
        printf("Case 2:\n");
    case 3:
        if(num != 2 && num != 3)
        printf("Case 3:\n");
    default:
        printf("Default:\n");
        break;
    }
    return 0;
}
