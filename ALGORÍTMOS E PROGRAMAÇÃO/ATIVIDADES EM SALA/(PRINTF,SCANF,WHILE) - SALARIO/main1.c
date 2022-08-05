#include <stdio.h>

int main()
{
    float t,sf,tv;
    int op;
    while(op != 0)
    {
        scanf("%f%f%d",&sf,&tv,&op);
        t = sf + (tv * 0.15);
        printf("TOTAL = R$ %.2f \n",t);
    }
    return 0;
}
