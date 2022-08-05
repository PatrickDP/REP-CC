#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void CONSULTA(C_PROFESSOR p[],int qt);
void CONSULTA_CH(C_PROFESSOR p[], int qt);
void CONSULTA_A(C_PROFESSOR p[], int qt);

int main() /*Letra: a*/
{
    setlocale(LC_ALL,"");
    int qt,i,j; /*i=para professores,j=para disciplinas*/
    printf("### - REGISTRO - ### \n");
    printf("Digite a quantidade de professores: ");
    scanf("%d",&qt);
    C_PROFESSOR p[qt];
    for(i=0; i<qt; i++)
    {
        printf("\nNome do professor %d: ",i+1); fflush(stdin); scanf("%[^\n]s",p[i].nome);
        printf("Telefone - formato (DDD)TELFONE: "); fflush(stdin); scanf("%s",p[i].telefone);
        printf("Data de admissão - formato(DD/MM/AA): "); scanf("%s",p[i].d_adimissao); fflush(stdin);
        printf("Salário (em R$ 0000.00): "); scanf("%f",&p[i].salario); fflush(stdin);
        printf("Data de nascimento (dia,mes,ano): "); scanf("%d%d%d",&p[i].n.dia,&p[i].n.mes,&p[i].n.ano);
        printf("\n(Endereco)\n");
        printf("Rua: "); fflush(stdin); scanf("%[^\n]s",p[i].e.rua);
        printf("Número: "); fflush(stdin); scanf("%d",&p[i].e.numero);
        printf("Complemento: "); fflush(stdin); scanf("%s",p[i].e.complemento);
        printf("Cep: "); scanf("%d",&p[i].e.cep);
        printf("Bairro: "); fflush(stdin); scanf("%[^\n]s",p[i].e.bairro);
        printf("Cidade: "); fflush(stdin); scanf("%[^\n]s",p[i].e.cidade);
        printf("Estado: "); fflush(stdin);scanf("%[^\n]s",p[i].e.estado);
        printf("Pais: "); fflush(stdin); scanf("%[^\n]s",p[i].e.pais);
        printf("\n(Disciplinas)\n");
        for(j=0; j<4; j++)
        {
            printf("Disciplina %d: ",j+1); scanf("%s",p[i].d[j].nome_d); fflush(stdin);
            printf("Carga horária (horas): "); scanf("%d",&p[i].d[j].carga_horaria);
            printf("Duracao (semestral/anual): "); scanf("%s",p[i].d[j].duracao); fflush(stdin);
            printf("\n");
        }
    }
    CONSULTA(p,qt);
    CONSULTA_CH(p,qt);
    CONSULTA_A(p,qt);
    return 0;
}

void CONSULTA_A(C_PROFESSOR p[], int qt)  /*Letra: d*/
{
    char op;
    int i=0,p_mes;
    printf("\n### CONSULTA DE ANIVERSARIANTES POR MES ### \n");
    printf("Deseja realizar a consulta, (s)/(n)? "); scanf("%s",&op);
    if(op == 's')
    {
        printf("Para realizar a consulta de aniversariantes de um determinado mes, digite:\n");
        printf("01 = JANEIRO, 02 = FEVEREIRO, 03 = MARÇO, 04 = ABRIL\n05 = MAIO, 06 = JUNHO, 07 = JULHO, 08 = AGOSTO\nSETEMBRO = 09, OUTUBRO = 10, NOVEMBRO = 11, DEZEMBRO = 12\n");
        scanf("%d",&p_mes);
        for(i=0; i<qt; i++)
        {
            if(p_mes == p[i].n.mes)
            {
                printf("___________________\nO professor %s é aniversariante do mes \"%d\" \n",p[i].nome,p[i].n.mes);
            }
        }
    }
    else
        return;
    }
void CONSULTA_CH(C_PROFESSOR p[], int qt) /*Letra: c*/
{
    char op;
    int i=0,j=0;
    int ch[qt]; /*somatorio das cargas horarias das disciplinas*/
    printf("\n### ANALISE DE CARGA HORARIA ###\n");
    printf("Deseja realizar a consulta, (s)/(n)? "); scanf("%s",&op);
    if(op == 's')
    {
        for(i=0; i<qt; i++)
        {
            ch[i] = 0;
            for(j=0; j<4; j++)
            {
                ch[i]+= p[i].d[j].carga_horaria;
            }
            if(ch[i] >= 16)
            {
                printf("___________________\nProfessor: %s\nCarga horária total das disciplinas: %dh (Maior ou igual a 16h)\n",p[i].nome,ch[i]);
            }
        }
    }
    else
        return;
}
void CONSULTA(C_PROFESSOR p[],int qt) /*Letra: b*/
{
    char consulta[50],op;
    int i=0,j=0;
    printf("\n### CONSULTAR PROFESSOR ###\n");
    printf("Deseja realizar a consulta, (s)/(n)? "); scanf("%s",&op);
    if(op == 's')
    {
        printf("Digite o nome do professor realizado para consultar seus dados: "); scanf("%s",consulta);
        for(i=0; i<qt; i++)
        {
            if(strcmp(consulta,p[i].nome) == 0)
            {
                printf("\n(Dados do professor)\n___________________\n");
                printf("Nome: %s\n",p[i].nome);
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
            else
            {
                printf("O professor que deseja buscar não consta como cadastrado no sistema.\n");
            }
        }
    }
    else
        return;
}
