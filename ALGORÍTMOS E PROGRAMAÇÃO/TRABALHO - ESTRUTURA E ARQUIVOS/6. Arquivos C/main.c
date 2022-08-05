#include <stdio.h>

int main()
{
    int i;
    char string[100],l,n;
    FILE *arquivo = fopen("teste.txt","w");
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!");
    }
    else
    {
        printf("O arquivo foi aberto com sucesso!\n");
        printf("Nome do arquivo: \"teste.txt\"\n");
        printf("Digite a string que deseja salvar: \n");
        scanf("%[^\n]s",string);
        fflush(stdin);
        for(i=0; string[i] != '\0'; i++)
        {
            fputc(string[i],arquivo);
        }
        printf("\nCaractere a ser substituido: ");
        scanf("%c",&l);
        fflush(stdin);
        printf("\nNovo caractere: ");
        scanf("%c",&n);
        fflush(stdin);
        printf("\nNovo texto:\n");
        for(i=0; string[i] != '\0'; i++)
        {
            if(string[i] == l)
            {
                string[i] = n;
            }
            printf("%c",string[i]);
        }
        fclose(arquivo);
        fopen("teste.txt","w");
        fputs(string,arquivo);
    }
    fclose(arquivo);
    return 0;

}
