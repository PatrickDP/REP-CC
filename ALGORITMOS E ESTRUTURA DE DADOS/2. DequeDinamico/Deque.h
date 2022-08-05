#include <iostream>

#include "Cliente.h"
#include "Nodo.h"

using namespace std;

class Deque
{
public:
    Nodo* inicio;
    Nodo* fim;

    Deque()
    {
        inicio = NULL;
        fim = NULL;
    }
    void insereInicio(const Cliente& cliente)
    {
        Nodo* novo_Nodo = NULL;
        Nodo* atual_Nodo = inicio;

        novo_Nodo = new Nodo(cliente);
        if(novo_Nodo == NULL)
        {
            cout << "ERRO: Falta memoria!" << endl;
            return;
        }
        if(inicio == NULL)
        {
            inicio = fim = novo_Nodo;
        }
        else
        {
            novo_Nodo->prox = atual_Nodo;
            atual_Nodo->ant = novo_Nodo;
            inicio = novo_Nodo;
        }
    }
    void insereFim(const Cliente& cliente)
    {
        Nodo* novo_Nodo = NULL;
        Nodo* atual_Nodo = fim;

        novo_Nodo = new Nodo(cliente);
        if(novo_Nodo == NULL)
        {
            cout << "ERRO: Falta memoria!" << endl;
            return;
        }
        if(inicio == NULL)
        {
            inicio = fim = novo_Nodo;
        }
        else
        {
            novo_Nodo->ant = atual_Nodo;
            atual_Nodo->prox = novo_Nodo;
            fim = novo_Nodo;
        }
    }
    Cliente pegaInicio()
    {
        Nodo* atual_Nodo = inicio;
        if(inicio == NULL)
        {
            return Cliente();
        }
        if(inicio == fim)
        {
            inicio = fim = NULL;
            delete atual_Nodo;
        }
        else
        {
            inicio = atual_Nodo->prox;
            delete atual_Nodo;
            inicio->ant = NULL;
        }
        return atual_Nodo->novo_Cliente;
    }
    Cliente pegaFim()
    {
        Nodo* atual_Nodo = fim;

        if(inicio == NULL)
        {
            return Cliente();
        }
        if(inicio == fim)
        {
            inicio = fim = NULL;
            delete atual_Nodo;
        }
        else
        {
            fim = atual_Nodo->ant;
            delete atual_Nodo;
            fim->prox = NULL;
        }
        return atual_Nodo->novo_Cliente;
    }
    void imprime()
    {
        Nodo* pecorreIni = inicio;
        Nodo* pecorreFim = fim;

        //if(inicio == NULL && fim == NULL)
        //{
            //cout << "ERRO: Deque vazio" << endl;
            //return;
        //}
        //else
        //{
            while(pecorreIni)
            {
                pecorreIni->novo_Cliente.imprimeCliente();
                pecorreIni = pecorreIni->prox;
            }
            cout << endl;
            while(pecorreFim)
            {
                pecorreFim->novo_Cliente.imprimeCliente();
                pecorreFim = pecorreFim->ant;
            }
            cout << endl;
        //}
    }
    ~Deque()
    {
        Nodo* pecorreIni = inicio;

        while(inicio)
        {
            pecorreIni = inicio->prox;
            delete inicio;
            inicio = pecorreIni;
        }
        fim = NULL;
    }
};
