#pragma once

#include <iostream>
#include "Aluno.hpp"

using namespace std;

class Nodo
{
public:
    Nodo *filhoEsquerda; // Ponteiro para o nodo esquerdo
    Nodo *filhoDireita; // Ponteiro para o nodo direito
    Aluno aluno; // Dados dos alunos

    // Inicializar os ponteiros apontando para NULL;
    Nodo()
    {
        filhoEsquerda = NULL;
        filhoDireita = NULL;
    }
    // Alocação dinâmica do aluno e inicialização
    Nodo(const Aluno& novoAluno)
    {
        filhoEsquerda = NULL;
        filhoDireita = NULL;
        aluno = novoAluno;
    }
    // Imprime, faz a chamada recursiva e, ao final do processo, desempilha
    void preOrdem()
    {
        aluno.imprime();
        if(filhoEsquerda != NULL)
            filhoEsquerda->preOrdem();
        if(filhoDireita != NULL)
            filhoDireita->preOrdem();
    }
    // Faz a chamada recursiva, imprime e, ao final do processo, desempilha
    void posOrdem()
    {
        if(filhoEsquerda != NULL)
            filhoEsquerda->posOrdem();
        if(filhoDireita != NULL)
            filhoDireita->posOrdem();
        aluno.imprime();
    }
    ~Nodo() {}
};
