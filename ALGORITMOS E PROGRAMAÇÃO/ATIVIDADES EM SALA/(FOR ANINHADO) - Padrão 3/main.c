#include <stdio.h>

int main()
{
    int i=0,j=0,coluna=1,num;
    scanf("%d",&num);
    for(i=1; i<num*2; i++)
    {
        for(j=1; j<=coluna; j++)
        {
            printf("*");
        }
        printf("\n");
        if(num > i)
        {
            coluna++;
        }
        else
            coluna--;
    }
    return 0;
}
