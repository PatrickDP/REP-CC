#include <stdio.h>

int main()
{
    char string;
    int l=0,n=0,m=0;
    FILE *ARQUIVO = fopen("teste.txt","r");
    if(ARQUIVO != NULL)
    {
        printf("O arquivo foi aberto com sucesso!\n");
    }
    else
        printf("Erro ao abrir o arquivo!");
    printf("Nome do arquivo: \"teste.txt\"\n");
    printf("Texto do arquivo:\n");
    do
    {
        string = getc(ARQUIVO);
        printf("%c",string);
        if((string >= 'A' && string <= 'Z') || (string >= 'a' && string <= 'z'))
        {
            l++;
        }
        if(string >= '0' && string <= '9')
        {
            n++;
        }
        if((string >= ' ' && string <= '/'))
        {
            m++;
        }
    }
    while(string != EOF);
    printf("\n");
    printf("Letras no arquivo teste.txt sao : %d\n",l);
    printf("Numeros no arquivo teste.txt sao : %d\n",n);
    printf("Outros caracteres no arquivo teste.txt sao : %d",m);
    fclose(ARQUIVO);
    return 0;
}
