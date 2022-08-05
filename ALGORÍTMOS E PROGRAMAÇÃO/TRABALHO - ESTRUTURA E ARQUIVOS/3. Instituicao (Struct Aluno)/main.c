#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disciplina
{
    char nome_d[50];
    int notas[10];
    float media[10];
    int status[10];
} disciplina;
typedef struct aluno
{
    int matricula;
    disciplina d[10];
    char nome[50];
    int ano;
    int semestre;
    int periodo;
} aluno;

void CADASTRO(aluno a[]);
void MEDIA(aluno a[], int quant_a, int v[]);
void CONSULTA_N(aluno a[], int quant_a, int v[]);
int CONSULTA_M(aluno a[], int quant_a, int v[]);

int main()
{
    aluno a[10];
    CADASTRO(a);
    return 0;
}
int CONSULTA_M(aluno a[], int quant_a, int v[]) /*letra: d*/
{
    char op;
    int i,j,m_desejada;
    printf("\n### CONSULTA DO ALUNO ATRAVES DA MATRICULA ###\n");
    printf("\nDeseja realizar a consulta? (S/N): ");
    scanf("%s",&op);
    if(op != 'N')
    {
        do
        {
            printf("\nDigite o numero de matricula do(a) aluno(a): ");
            scanf("%d",&m_desejada);
            for(i=0; i<quant_a; i++)
            {
                if(m_desejada == a[i].matricula)
                {
                    printf("\nMatricula(%d) - Aluno(a): %s\n",a[i].matricula,a[i].nome);
                    printf("Perido, semestre e ano: (%d - %d/%d)\n",a[i].periodo,a[i].semestre,a[i].ano);
                    printf("Disciplinas:\n");
                    for(j=0; j<v[i]; j++)
                    {
                        printf("%s - Media: %.2f (STATUS: %d)\n",a[i].d[j].nome_d,a[i].d[j].media[i],a[i].d[j].status[i]);
                    }
                }
            }
            printf("\nDeseja relizar outra consulta? (S/N): ");
            scanf("%s",&op);
        }
        while(op != 'N');
    }
    return a[i].matricula;
}
void CONSULTA_N(aluno a[], int quant_a, int v[]) /*letra: c*/
{
    char op, estudante[50];
    int i,j;
    printf("\n### CONSULTA DO ALUNO PELO NOME ###\n");
    printf("\nDeseja realizar a consulta? (S/N): ");
    scanf("%s",&op);
    if(op != 'N')
    {
        do
        {
            printf("\nDigite o nome do(a) aluno(a): ");
            scanf("%s",estudante);
            fflush(stdin);
            for(i=0; i<quant_a; i++)
            {
                if(strcmp(estudante,a[i].nome) == 0)
                {
                    printf("\nMatricula(%d) - Aluno(a): %s\n",a[i].matricula,a[i].nome);
                    printf("Perido, semestre e ano: (%d - %d/%d)\n",a[i].periodo,a[i].semestre,a[i].ano);
                    printf("(Disciplinas) - ");
                    for(j=0; j<v[i]; j++)
                    {
                        printf("%s - Media: %.2f (STATUS: %d)\n",a[i].d[j].nome_d,a[i].d[j].media[i],a[i].d[j].status[i]);
                    }
                }
            }
            printf("\nDeseja relizar outra consulta? (S/N): ");
            scanf("%s",&op);
        }
        while(op != 'N');
    }
}
void MEDIA(aluno a[], int quant_a, int v[]) /*letra: b*/
{
    int soma;
    char op;
    int i,j,k;
    printf("### CONSULTA DE MEDIA E APROVACAO ###\n");
    for(i=0; i<quant_a; i++)
    {
        for(j=0; j<v[i]; j++)
        {
            soma =0;
            for(k=0; k<10; k++)
            {
                soma+= a[i].d[j].notas[k];
            }
            a[i].d[j].media[i]  = soma/10;
            if(a[i].d[j].media[i] >= 6)
            {
                a[i].d[j].status[i] = 1;
            }
            else
            {
                a[i].d[j].status[i] = 0;
            }
        }

    }
    printf("\nDeseja consultar as notas dos alunos? (S/N): ");
    scanf("%s",&op);
    if(op != 'N')
    {
        for(i=0; i<quant_a; i++)
        {
            /*printf("Quantidade de disciplinas do aluno %s: %d",a[i].nome,v[i]);*/
            printf("__________\nAluno(a): %s\n(Notas)",a[i].nome);
            for(j=0; j<v[i]; j++)
            {
                printf("\n%s - %.2f (MEDIA) / ",a[i].d[j].nome_d,a[i].d[j].media[i]);
                if(a[i].d[j].media[i] >= 6)
                {
                    printf("STATUS %d: APROVADO",a[i].d[j].status[i]);
                }
                else
                {
                    printf("STATUS %d: REPROVADO",a[i].d[j].status[i]);
                }
            }
            printf("\n");
        }
    }
    else
        return;
}
void CADASTRO(aluno a[]) /*letra: a*/
{
    int quant_a=0,quant_d=0; /*quant_a: quant de alunos,quant_d: quant. de disciplinas cursadas*/
    int i,j,k; /*i=pecorre a alunos,j=pecorre por disciplinas,k=pecorre por notas*/
    char op;
    int v[10]; /*vetor que armazena qntd de disciplinas por aluno*/
    printf("### CADASTRO DOS ALUNOS ###\n");
    for(i=0; i<quant_a+1; i++)
    {
        printf("\nDigite o numero de matricula do(a) aluno(a) %d: ",i+1);
        scanf("%d",&a[i].matricula);
        if(a[i].matricula != -1)
        {
            printf("nome do(a) aluno(a): ");
            fflush(stdin);
            scanf("%[^\n]s",a[i].nome);
            printf("Ano atual: ");
            scanf("%d",&a[i].ano);
            printf("Semestre atual: 1o ou 2o? ");
            scanf("%d",&a[i].semestre);
            printf("Periodo em que o aluno se encontra presente: ");
            scanf("%d",&a[i].periodo);
            printf("(DISCIPLINAS)\n");
            quant_d = 0;
            for(j=0; j<quant_d+1; j++)
            {
                printf("Insira o nome da disciplina %d: ",j+1);
                fflush(stdin);
                scanf("%[^\n]s",a[i].d[j].nome_d);
                for(k=0; k<10; k++)
                {
                    printf("NOTA %d: ",k+1);
                    scanf("%d",&a[i].d[j].notas[k]);
                }
                printf("Se deseja inserir mais uma disciplina, digite (S/N): ");
                scanf("%s",&op);
                quant_d++;
                v[i] = quant_d;
                if(op == 'N')
                {
                    break;
                }
            }
            /*printf("Quantidade de disciplinas do aluno %s: %d\n",a[i].nome,v[i]);*/
            quant_a++;
        }
        else
        {
            break;
        }
    }
    /*printf("Total de alunos: %d",quant_a);*/
    MEDIA(a,quant_a,v);
    CONSULTA_M(a,quant_a,v);
    CONSULTA_N(a,quant_a,v);
}
