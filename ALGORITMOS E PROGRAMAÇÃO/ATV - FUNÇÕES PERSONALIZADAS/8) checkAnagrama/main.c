#include <stdio.h>
#include <string.h>
#include <locale.h>

int  checkAnagrama(char *str1, char *str2) /*Atividade: (8)*/
{
    int anagrama=2,tam=0,j=1,i;
    tam = strlen(str2); /*Leitura do tamanho da string*/
    for(i=0; i<tam; i++)
    {
        if(str1[i] == str2[tam-j])
        {
            anagrama = 1;
        }
        else
        {
            anagrama = 0;
            break;
        }
        j++;
    }
    return anagrama;
}
int main()
{
    setlocale(LC_ALL,"");
    int resultado=2;
    char str1[50],str2[50];
    scanf("%s%s",str1,str2);
    resultado = checkAnagrama(str1,str2);
    printf("\"%s\" e \"%s\" ",str1,str2);
        if(resultado == 1)
        {
            printf("São anagramas.");
        }
        if(resultado == 0)
        {
            printf("Não são anagramas.");
        }
    return 0;
}
