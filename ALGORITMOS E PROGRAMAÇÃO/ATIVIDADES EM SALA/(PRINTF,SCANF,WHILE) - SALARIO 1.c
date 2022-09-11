#include <stdio.h>

int main()
{
    float t,c,sf,tv;
    int op;
    do
    {
        scanf("%f%f",&sf,&tv);
        scanf("%d",&op);
        c = tv * 0.15;
        t = sf + c;
        printf("TOTAL = R$ %.2f \n",t);
    }
    while(op != 0);
    return 0;
}
