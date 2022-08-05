#pragma once

#include <iostream>
#include "nodo.hpp"

using namespace std;

class ListaEnc
{
public:
    Nodo *inicio;

    ListaEnc() { inicio = NULL; }
    ~ListaEnc()
    {
        Nodo *aux = inicio;

        while(inicio)
        {
            aux = aux->prox;
            cout << "\n\t~ " << inicio->dadosCliente.chave;
            delete inicio;
            inicio = aux;
        }
    }
    void insereLista(const Cliente& cliente, unsigned &l)
    {
        Nodo *novoNodo = new Nodo(cliente);
        Nodo *atualNodo = inicio;

        if(!inicio)
        {
            l++;
            inicio = novoNodo;
            return;
        }
        else
        {
            novoNodo->prox = inicio;
            inicio = novoNodo;
            l++;
            return;
        }
    }
    // Insere no final
    /*void insereLista(const Cliente& cliente, unsigned &l)
    {
        Nodo *novoNodo = new Nodo(cliente);
        Nodo *atualNodo = inicio;

        if(!inicio)
        {
            l++;
            inicio = novoNodo;
            return;
        }
        else
        {
            while(atualNodo)
            {
                if(!atualNodo->prox)
                    break;
                atualNodo = atualNodo->prox;
            }
            l++;
            atualNodo->prox = novoNodo;
            return;
        }
    }*/
    void imprimeLista(unsigned i, unsigned &e)
    {
        Nodo *aux = inicio;
        unsigned j = 0;

        do
        {
            if(!inicio)
                continue;
            cout << "i = " << i << " - j = " << j << " : ";
            aux->dadosCliente.imprime(e);
            aux = aux->prox;
            j++;
            cout << endl;
        }
        while(aux);
    }
    Cliente buscaLista(unsigned chave, unsigned &l)
    {
        Nodo *aux = inicio;

        cout << endl;
        while(aux)
        {
            l++;
            cout << "(" << aux->dadosCliente.chave << ")" << ", "; // Mostra o percurso dos nodos
            if(chave == aux->dadosCliente.chave)
            {
                cout << "Quanta(s) vezes leu: " << l << endl;
                return aux->dadosCliente;
            }
            else
                aux = aux->prox;
        }
        cout << "Quanta(s) vezes leu: " << l << endl;
        return Cliente();
    }
};
