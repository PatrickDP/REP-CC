#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(m == 0)
    {
        printf("Divisao por zero\n");
    }
    else
        printf("%.2f\n",(float)n/m);
    return 0;
}
