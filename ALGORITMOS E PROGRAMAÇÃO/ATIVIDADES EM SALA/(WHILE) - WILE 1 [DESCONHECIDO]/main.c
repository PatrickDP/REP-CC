#include <stdio.h>

int main()
{
    int n,aux=0;
    scanf("%d",&n);
    aux = n;
    while(n <= aux*2) {
          printf("%d ",n);
          n = n + 1;
    }
    return 0;
}

