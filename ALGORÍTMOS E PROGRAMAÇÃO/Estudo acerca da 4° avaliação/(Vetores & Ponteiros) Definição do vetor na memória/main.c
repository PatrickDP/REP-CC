#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,*v;
    v = malloc( 100 * sizeof (int));
    for (i = 0; i < 100; ++i)
    {
        v[i]=i;
        printf(" %d ",*(v+i)); //manuseando vetor com ponteiros
    }
    return 0;
}
