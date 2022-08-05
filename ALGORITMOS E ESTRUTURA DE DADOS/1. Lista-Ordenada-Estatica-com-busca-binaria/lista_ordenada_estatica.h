#pragma once

#include <iostream>
#include "cliente.h"

using namespace std;

class Lista_Ordenada_Estatica
{
public:
    unsigned quant_Clientes;
    Cliente clientes[TOTAL_CLIENTES];

    Lista_Ordenada_Estatica()
    {
        quant_Clientes = 0;
        if(quant_Clientes == 0)
        {
            cout << "\tLISTA VAZIA! \n\n";
        }
    }
    void imprime_Clientes() const
    {
        for(unsigned p = 0; p < quant_Clientes; p++)
        {
            cout << "<" << clientes[p].chave << "," << clientes[p].nome << "> ";
        }
        cout << endl;
    }
    void insere_Clientes(const Cliente& cliente)
    {
        int pos_Ini = 0;
        int pos_Final = quant_Clientes-1;
        int meio = 0;

        if(quant_Clientes == TOTAL_CLIENTES)
        {
            cout << "\tLISTA CHEIA! \n\n" << endl;
            return;
        }
        clientes[quant_Clientes] = cliente;
        while(pos_Ini <= pos_Final)
        {
            meio = (pos_Ini + pos_Final) / 2;
            if(clientes[quant_Clientes].chave == clientes[meio].chave)
            {
                return;
            }
            if(clientes[quant_Clientes].chave < clientes[meio].chave)
            {
                pos_Final = meio - 1;
            }
            else
            {
                pos_Ini = meio + 1;
            }
        }
        for(int p = quant_Clientes ; p > meio; p--)
        {
            clientes[p] = clientes[p-1];
        }
        if(cliente.chave < clientes[meio].chave)
        {
            clientes[meio] = cliente;
        }
        else
        {
            clientes[meio+1] = cliente;
        }
        quant_Clientes++;
    }
    Cliente busca_Clientes(unsigned chave_Cliente)
    {
        int pos_Ini = 0;
        int pos_Final = quant_Clientes - 1;
        int meio = 0;

        while(pos_Ini <= pos_Final)
        {
            meio = (pos_Ini + pos_Final) / 2;
            if(chave_Cliente == clientes[meio].chave)
            {
                return clientes[meio];
            }
            if(chave_Cliente < clientes[meio].chave)
            {
                pos_Final = meio - 1;
            }
            else
                pos_Ini = meio + 1;
        }
        return Cliente();
    }
    void junta_Listas(const Lista_Ordenada_Estatica& loe)
    {
        for(unsigned p = 0; p < loe.quant_Clientes; p++)
        {
            insere_Clientes(loe.clientes[p]);
        }
    }
    ~Lista_Ordenada_Estatica() {}
};

