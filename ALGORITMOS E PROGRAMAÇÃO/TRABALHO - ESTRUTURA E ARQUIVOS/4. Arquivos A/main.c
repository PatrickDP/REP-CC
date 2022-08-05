#include <stdio.h>

int main()
{
    char string;
    int quebra=0;
    FILE *arquivo = fopen("teste.txt","r");
    if(arquivo == NULL)
    {
        printf("Erro ao tentar abrir o arquivo!");
        return 0;
    }
    else
    {
        printf("O arquivo foi aberto com sucesso!\n");
    }

    printf("Nome do arquivo: teste.txt\n");
    printf("Texto do arquivo:\n");
    do
    {
        string = getc(arquivo); /*Lendo caracteres*/
        printf("%c",string);
        if(string == '\n')
        {
            quebra++;
        }
    }
    while(string != EOF);
    printf("\nO arquivo \"teste.txt\" tem: %d linhas",quebra);
    fclose(arquivo);
    return 0;
}
