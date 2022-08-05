#include <iostream>

#include "Cliente.h"

using namespace std;

class Nodo
{
public:
    Nodo* ant;
    Nodo* prox;
    Cliente novo_Cliente;

    Nodo()
    {
        ant = NULL;
        prox = NULL;
    }
    Nodo(const Cliente& cliente)
    {
        ant = NULL;
        novo_Cliente = cliente;
        prox = NULL;
    }
    ~Nodo() {}
};
