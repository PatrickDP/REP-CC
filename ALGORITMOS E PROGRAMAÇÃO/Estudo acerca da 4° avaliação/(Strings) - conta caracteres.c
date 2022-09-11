#include <stdio.h>
#include <string.h>

int main()
{
    char s[80],l;
    int t=0,i,c=0;  /*l: letra a ser procurada*/
    scanf("%c",&l); /*c: contador de letras*/
    scanf("%s",s); /*não utilize s[80], somente para declarar o tamanho como lá em cima*/
    t = strlen(s);
    //printf("Tamanho = %d\n",t);
    for(i=0; i<t; i++)
    {
        if(l == s[i])
        {
            c++;
        }
    }
    if(c != 0)
    {
        printf("Existem %d caracteres na string \"%s\".",c,s);
    }
    else
        printf("Nao existe.");
    return 0;
}
