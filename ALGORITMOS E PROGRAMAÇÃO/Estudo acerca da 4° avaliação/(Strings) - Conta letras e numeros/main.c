#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int size=0,i,l=0,n=0;
    scanf("%s",str);
    size = strlen(str);
    for(i=0; i<size; i++)
    {
        if(str[i] != '-')
        {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        //if(isalpha(str[i]))
        {
            l++;
        }
        else
            n++;
        }
    }
    printf("Letras = %d\nNumeros = %d",l,n);
    return 0;
}
