#pragma once

#include <iostream>
#include "Cliente.hpp"

#define TAM_TOTAL 20

using namespace std;

class Heap
{
public:
    Cliente clientes[TAM_TOTAL];
    int tam;

    Heap()
    {
        tam = 0;
    }
    ~Heap() {}

    void imprimir()
    {
        cout << endl;
        for(int i = 1; i < (tam + 1); i++)
        {
            clientes[i].imprime();
            cout << " i=" << i << ", ";
        }
        cout << endl;
    }
    void inserir(const Cliente& cliente)
    {
        if((tam + 1) >= TAM_TOTAL)
            return;
        tam++;
        clientes[tam] = cliente;
        subir(tam);
    }
    Cliente seleciona()
    {
        Cliente maiorPrior;

        cout << endl << "\t\t\t\t";
        if(tam >= 0)
        {
            maiorPrior = clientes[tam];
            for(int i = tam; i >= 1; i--)
            {
                if(clientes[i - 1].chave == 0)
                    break;
                if(clientes[i - 1].chave > maiorPrior.chave)
                    maiorPrior = clientes[i - 1];
            }
        }
        return maiorPrior;
    }
    void remover()
    {
        clientes[1] = clientes[tam];
        tam--;
        descer(1);
    }

    void subir(int i)
    {
        int j = (i / 2);
        if(j >= 1)
        {
            if(clientes[i].chave > clientes[j].chave)
            {
                swap(clientes[i],clientes[j]);
                subir(j);
            }
        }
    }
    void descer(int i)
    {
        int j = (i * 2);

        if(j <= tam)
        {
            if(clientes[j + 1].chave > clientes[j].chave)
                j++;
            if(clientes[i].chave < clientes[j].chave)
            {
                swap(clientes[i], clientes[j]);
                descer(j);
            }
        }
    }
};
