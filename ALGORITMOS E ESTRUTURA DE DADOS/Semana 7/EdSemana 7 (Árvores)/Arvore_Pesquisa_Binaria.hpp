#pragma once

#include <iostream>
#include "Nodo.hpp"

using namespace std;

class Arvore_Pesquisa_Binaria
{
public:
    Nodo *raiz;

    // Inicializa uma árvore vazia
    Arvore_Pesquisa_Binaria()
    {
        raiz = NULL;
    }
    // Destrutor que chama o método apaga
    ~Arvore_Pesquisa_Binaria()
    {
        if(raiz)
            apaga(raiz);
    }
    // Pecorre do filho(s) a raiz
    void preOrdem()
    {
        if(raiz != NULL)
            raiz->preOrdem(); // Chama o método da classe Nodo
        cout << endl;
    }
    // Pecorre da raiz ao filho(s)
    void posOrdem()
    {
        if(raiz != NULL)
            raiz->posOrdem();
        cout << endl;
    }
    void insere(const Aluno& aluno)
    {
        Nodo* novo_Nodo = new Nodo(aluno);
        Nodo* atualPtr_Nodo = raiz; // Vai pecorrer a árvore

        if(raiz == NULL)
        {
            raiz = novo_Nodo;
            return;
        }
        // Só para quando chegar na folha
        while(true)
        {
            if(novo_Nodo->aluno.chave < atualPtr_Nodo->aluno.chave)
            {
                // Chegamos na folha
                if(atualPtr_Nodo->filhoEsquerda == NULL)
                {
                    atualPtr_Nodo->filhoEsquerda = novo_Nodo;
                    return;
                }
                // Ainda não chegamos na folha
                else
                {
                    atualPtr_Nodo = atualPtr_Nodo->filhoEsquerda;
                }
            }
            if(novo_Nodo->aluno.chave > atualPtr_Nodo->aluno.chave)
            {
                if(atualPtr_Nodo->filhoDireita == NULL)
                {
                    atualPtr_Nodo->filhoDireita = novo_Nodo;
                    return;
                }
                else
                {
                    atualPtr_Nodo = atualPtr_Nodo->filhoDireita;
                }
            }
        }
    }
    Aluno busca(unsigned chave)
    {
        Nodo* atualPtr_Nodo = raiz;

        cout << endl;
        while(atualPtr_Nodo != NULL)
        {
            if(chave == atualPtr_Nodo->aluno.chave)
            {
                cout << "existe: ";
                return atualPtr_Nodo->aluno;
            }
            else
            {
                if(chave < atualPtr_Nodo->aluno.chave)
                {
                     atualPtr_Nodo = atualPtr_Nodo->filhoEsquerda;
                }
                else
                {
                    atualPtr_Nodo = atualPtr_Nodo->filhoDireita;
                }
            }
        }
        cout << "nao existe: ";
        return Aluno();
    }
    /* Faz a chamada recursiva e, ao final da pilha, vai deletando os nodos e desempilha repetidamente.
    * Depois deste processo, a arvore já esvaziou. */
    void apaga(Nodo *ptr_Nodo)
    {
        if(ptr_Nodo->filhoEsquerda != NULL)
            apaga(ptr_Nodo->filhoEsquerda);
        if(ptr_Nodo->filhoDireita != NULL)
            apaga(ptr_Nodo->filhoDireita);
        delete ptr_Nodo;
    }
};

