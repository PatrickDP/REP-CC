#pragma once

#include <iostream>

#define TOTAL_CLIENTES 20

using namespace std;

class Cliente
{
public:
    unsigned chave;
    string nome;
    Cliente()
    {
        chave = 0;
        nome = "Dummy";
    }
    Cliente(unsigned chave, const string& nome)
    {
        this->chave = chave;
        this->nome = nome;
    }
    void imprime_Cliente() const
    {
        cout << "<" << chave << "," << nome << "> ";
        cout << endl;
    }
    ~Cliente() {}
};

