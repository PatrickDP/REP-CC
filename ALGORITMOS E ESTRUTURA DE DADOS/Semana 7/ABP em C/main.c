#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned chave;
    char nome[20];
} Aluno;
void setDum(Aluno a);
void set(Aluno a,unsigned chave, char nome[]);
void imprime();


typedef struct t_Nodo Nodo;
struct Nodo
{
    Nodo* esquerdo;
    Nodo* direito;
    Aluno aluno;
};
typedef struct
{
    Nodo* raiz;
} ABP;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void setDum(Aluno a)
{
    a.chave = 0;
    strcpy(a.nome, "Dummy");
}
void set(Aluno a, unsigned chave, char nome[])
{
    a.chave = chave;
}
