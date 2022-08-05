#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ENDERECO
{
    char rua[50];
    int numero;
    char complemento[50];
    int cep;
    char bairro[50];
    char cidade[50];
    char estado[50];
    char pais[50];
} ENDERECO;

typedef struct DISCIPLINA
{
    char nome_d[50];
    int carga_horaria;
    char duracao[50];
} DISCIPLINA;

typedef struct D_NASCIMENTO
{
    int dia;
    int mes;
    int ano;
} D_NASCIMENTO;

typedef struct C_PROFESSOR
{
    char nome[50];
    char d_adimissao[50];
    float salario;
    char telefone[50];
    D_NASCIMENTO n;
    DISCIPLINA d[4];
    ENDERECO e;
} C_PROFESSOR;

void ARQUI_P(C_PROFESSOR p[], int qt);

int main()
{
    setlocale(LC_ALL,"");
    int qt,i,j; /*i=para professores,j=para disciplinas*/
    printf("### - REGISTRO - ### \n");
    printf("Digite a quantidade de professores: ");
    scanf("%d",&qt);
    C_PROFESSOR p[qt];
    for(i=0; i<qt; i++)
    {
        printf("\nNome do professor %d: ",i+1);
        fflush(stdin);
        scanf("%[^\n]s",p[i].nome);
        printf("Telefone - formato (DDD)TELFONE: ");
        fflush(stdin);
        scanf("%s",p[i].telefone);
        printf("Data de admissão - formato(DD/MM/AA): ");
        scanf("%s",p[i].d_adimissao);
        fflush(stdin);
        printf("Salário (em R$ 0000.00): ");
        scanf("%f",&p[i].salario);
        fflush(stdin);
        printf("Data de nascimento (dia,mes,ano): ");
        scanf("%d%d%d",&p[i].n.dia,&p[i].n.mes,&p[i].n.ano);
        printf("\n(Endereco)\n");
        printf("Rua: ");
        fflush(stdin);
        scanf("%[^\n]s",p[i].e.rua);
        printf("Número: ");
        fflush(stdin);
        scanf("%d",&p[i].e.numero);
        printf("Complemento: ");
        fflush(stdin);
        scanf("%s",p[i].e.complemento);
        printf("Cep: ");
        scanf("%d",&p[i].e.cep);
        printf("Bairro: ");
        fflush(stdin);
        scanf("%[^\n]s",p[i].e.bairro);
        printf("Cidade: ");
        fflush(stdin);
        scanf("%[^\n]s",p[i].e.cidade);
        printf("Estado: ");
        fflush(stdin);
        scanf("%[^\n]s",p[i].e.estado);
        printf("Pais: ");
        fflush(stdin);
        scanf("%[^\n]s",p[i].e.pais);
        printf("\n(Disciplinas)\n");
        for(j=0; j<4; j++)
        {
            printf("Disciplina %d: ",j+1);
            scanf("%s",p[i].d[j].nome_d);
            fflush(stdin);
            printf("Carga horária (horas): ");
            scanf("%d",&p[i].d[j].carga_horaria);
            printf("Duracao (semestral/anual): ");
            scanf("%s",p[i].d[j].duracao);
            fflush(stdin);
            printf("\n");
        }
    }
    ARQUI_P(p,qt);
    return 0;
}

void ARQUI_P(C_PROFESSOR p[], int qt) /*Numero: 8*/
{
    int i,j;
    FILE *arquivo = fopen("professores.dat","a"); /*criacao*/
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    else
    {
        printf("Arquivo aberto com sucesso!\n");
        fwrite(&p,sizeof(struct C_PROFESSOR),1,arquivo);
        fclose(arquivo);
    }
    fopen("arquivo.dat","r"); /*leitura*/
    if(arquivo != NULL)
    {
        printf("\nArquivo aberto com sucesso para leitura!\n");
        printf("### - RECUPERAÇÃO DE DADOS DA STRUCT - ### \n");
        fread(&p,sizeof(struct C_PROFESSOR),1,arquivo);
        for(i=0; i<qt; i++)
        {
            printf("\nNome do professor: %s\n",p[i].nome);
            printf("Telefone: %s\n",p[i].telefone);
            printf("Data de admissão: %s\n",p[i].d_adimissao);
            printf("Salário: R$ %.2f\n",p[i].salario);
            printf("Data de nascimento: (%d/%d/%d)\n",p[i].n.dia,p[i].n.mes,p[i].n.ano);
            printf("(Endereco, numero, complemento e cep): %s, %d - %s, %d\n",p[i].e.rua,p[i].e.numero,
                   p[i].e.complemento,p[i].e.cep);
            printf("(Bairro, cidade, estado e pais): %s, %s/%s - %s\n",p[i].e.bairro,p[i].e.cidade,p[i].e.estado,
                   p[i].e.pais);
            printf("(DISCIPLINA LECIONADA/CARGA HORÁRIA/DURAÇÃO)\n");
            for(j=0; j<4; j++)
            {
                printf("%s - %dh/%s\n",p[i].d[j].nome_d,p[i].d[j].carga_horaria,p[i].d[j].duracao);
            }
        }
        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
}
