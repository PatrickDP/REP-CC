#include <iostream>
#include "cliente.hpp"

using namespace std;

class Nodo
{
public:
    Nodo* prox;
    Cliente dadosCliente;

    Nodo()
    {
        prox = NULL;
    }
    Nodo(const Cliente &novoCliente)
    {
        dadosCliente = novoCliente;
        prox = NULL;
    }
    ~Nodo() {}
};
