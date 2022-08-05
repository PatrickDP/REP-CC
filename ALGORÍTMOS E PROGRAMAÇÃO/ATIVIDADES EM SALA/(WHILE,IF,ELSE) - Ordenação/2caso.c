#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && b>c)
    {
        printf("%d %d %d\n",a,b,c);
    }
    else
        printf("%d %d %d\n",c,b,a);

    if(b>c && c>a)
    {
        printf("%d %d %d\n",b,c,a);
    }
    else
        printf("%d %d %d\n",a,c,b);

    if(c>a && a>b)
    {
        printf("%d %d %d\n",c,a,b);
    }
    else
        printf("%d %d %d\n",b,a,c);

    return 0;
}
