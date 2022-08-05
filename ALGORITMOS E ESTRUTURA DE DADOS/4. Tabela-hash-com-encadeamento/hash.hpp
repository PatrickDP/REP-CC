#pragma once

#include <iostream>
#include "listaEnc.hpp"

#define M 5

using namespace std;

class Hash
{
public:
    ListaEnc tabela[M];

    Hash() {}
    ~Hash(){}

    void insereHash(const Cliente& cliente, unsigned &l)
    {
        unsigned mod = (cliente.chave % M);
        tabela[mod].insereLista(cliente,l);
    }
    void imprimeHash(unsigned &e)
    {
        for(unsigned i = 0; i < M; i++)
        {
            tabela[i].imprimeLista(i,e);
            cout << endl;
        }
    }
    void buscaHash(unsigned chave, unsigned &l, unsigned &e)
    {
        unsigned mod = (chave % M);
        tabela[mod].buscaLista(chave,l).imprime(e);
        cout << endl;
    }
};
