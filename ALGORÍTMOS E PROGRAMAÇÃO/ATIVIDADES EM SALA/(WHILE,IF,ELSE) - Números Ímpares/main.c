#include <stdio.h>

int main()
{
    int x,y,i=1;
    scanf("%d%d",&x,&y);
    while(i<x/2)
    {
        if(y%2 == 0)
        {
            y = y + 1;
        }
        if(y%2 != 0)
        {
            printf("%d\n",y);
            y = y + 2;
        }
        i++;
    }
    return 0;
}
