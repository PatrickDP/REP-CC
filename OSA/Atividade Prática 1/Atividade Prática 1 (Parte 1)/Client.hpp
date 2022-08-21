// #pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

class Client {
private:
    string client_name;
public:
    Client();
    ~Client();

    // SETAR, PEGAR,  GERAR UM ARQUIVO E IMPRIMIR OS DADOS DOS CLIENTES (REGISTROS)
     void set_client(string new_clientName);
     string get_client() const;
     void print_client();
};

#endif