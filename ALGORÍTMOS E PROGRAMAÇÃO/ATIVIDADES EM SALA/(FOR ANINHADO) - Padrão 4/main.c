#include <stdio.h>

int main()
{
    int i=1,j=1,n;
    scanf("%d",&n);
    for(i=1; i<n*2; i++)
    {
        for(j=1; j<i+1; j++)
        {
            printf("*");
            if(i > n)
            {
                for(j=n*2; j>i+1; j--)
                {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
