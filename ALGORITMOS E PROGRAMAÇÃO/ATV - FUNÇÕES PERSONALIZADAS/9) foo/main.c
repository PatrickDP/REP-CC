#include<stdio.h>
void foo(int v[])
{
    v[0]=1;
}
void bar(int x)
{
    x=1;
}

int main()
{
    int a[5]= {0,0,0,0,0};
    int b=20;
    foo(a);
    printf("%d\n", a[0]);
    bar(b);
    printf("%d\n", b);
    return 0;
}
