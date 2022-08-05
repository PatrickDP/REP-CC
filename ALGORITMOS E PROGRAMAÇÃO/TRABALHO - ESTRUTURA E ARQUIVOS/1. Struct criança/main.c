#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data
{
    char dia[50];
    char mes[50];
    char ano[50];
} d;
typedef struct end
{
    char rua[50];
    int numero;
    char complemento[50];
    char bairro[50];
    int cep;
    char cidade[50];
    char estado[50];
    char pais[50];
    int telefone[5];
} e;
typedef struct crianca
{
    char nome[50];
    char mae[50];
    char sexo[50];
    struct data d;
    struct end e;
} c;

int main()
{
    int qt=1,j=0,i;
    char opcao;
    struct crianca c[10];
    for(i=0; i<qt; i++)
    {
        printf("Cadastro da crianca %d: \nNOME: ",i+1);
        scanf("%s",c[i].nome);
        printf("NOME DA MAE:\n");
        scanf("%s",c[i].mae);
        printf("Para o \"SEXO\" digite: (M) para Masculino/ (F) para Feminino\n");
        scanf("%s",c[i].sexo);
        printf("DIA/MES/ANO de nascimento (Com quebra de linha):\n");
        scanf("%s%s%s",c[i].d.dia,c[i].d.mes,c[i].d.ano);
        printf("Endereco:\n");
        printf("RUA/NUMERO/COMPLEMENTO/BAIRRO (Com quebra de linha):\n");
        scanf("%s",c[i].e.rua);
        fflush(stdin);
        scanf("%d",&c[i].e.numero);
        scanf("%s",c[i].e.complemento);
        fflush(stdin);
        scanf("%s",c[i].e.bairro);
        fflush(stdin);
        printf("CEP/CIDADE/ESTADO/PAIS (Com quebra de linha):\n");
        scanf("%d",&c[i].e.cep);
        scanf("%s",c[i].e.cidade);
        fflush(stdin);
        scanf("%s",c[i].e.estado);
        fflush(stdin);
        scanf("%s",c[i].e.pais);
        fflush(stdin);
        do
        {
            printf("DDD e TELFONE %d (Juntos): ",j+1);
            scanf("%d",&c[i].e.telefone[j]);
            printf("Deseja inserir mais telefones? Digite \"S\" para SIM e \"N\" para NAO\n");
            scanf("%s",&opcao);
            j++;
        }
        while(opcao != 'N');
        printf("Deseja realizar outro cadastro:? Digite \"1\" para SIM e \"0\" para NAO\n");
        scanf("%s",&opcao);
        if(opcao == '0')
        {
            break;
        }
        else if(opcao == '1')
        {
            qt++;
            printf("\n");
        }
        j = 0;
    }
    int MENU;
    char consulta[100];
    printf("\n");
    printf("### MENU DE CONSULTAS ###\n");
    printf("Digite:\n");
    printf("(1) Para consultar criancas de determinados bairros\n");
    printf("(2) Para consultar criancas que nasceram em determinado mes\n");
    printf("(3) Para consultar criancas de determinado sexo\n");
    scanf("%d",&MENU);
    switch(MENU)
    {
    case 1:
        printf("Digite o bairro que deseja consultar:\n");
        scanf("%s",consulta);
        for(i=0; i<qt; i++)
        {
            if(strcmp(consulta,c[i].e.bairro) == 0)
            {
                printf("[%s eh do bairro \"%s\"] \n",c[i].nome,c[i].e.bairro);
            }
        }
        break;
    case 2:
        printf("Digite o mes que deseja consultar:\n");
        scanf("%s",consulta);
        for(i=0; i<qt; i++)
        {
                if(strcmp(consulta,c[i].d.mes) == 0)
                {
                    printf("[%s eh do mes \"%s\"] \n",c[i].nome,c[i].d.mes);
                }
        }
        break;
    case 3:
        printf("Para realizar a consulta desejada, digite o sexo da crianca (M/N):\n");
        scanf("%s",consulta);
        for(i=0; i<qt; i++)
        {
            if(strcmp(consulta,c[i].sexo) == 0)
            {
                printf("[%s eh do sexo \"%s\"] \n",c[i].nome,c[i].sexo);
            }
        }
        break;
    }
    return 0;
}
