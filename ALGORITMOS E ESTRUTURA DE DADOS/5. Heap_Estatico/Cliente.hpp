#pragma once

#include <iostream>

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
    Cliente(unsigned chave, const string &nome)
    {
        this->chave = chave;
        this->nome = nome;
    }
    ~Cliente() {}

    void imprime() const
    {
        cout << "<" << chave << "," << nome << ">";
    }

};
