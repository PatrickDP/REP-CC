#include <stdio.h>

void inc(int *p)
{
    (*p)++;
    return;
}
int main()
{
    int *p;
    *p = 12;
    inc(p);
    printf("%d",*p); /*erro de compilação*/
    return 0;
}
