#pragma once

#include <iostream>

using namespace std;

class Client {
private:
    string client_name;
public:
    Client();

    // SETA, PEGA, E IMPRIME OS DADOS DO CLIENTE
     void set_client(string new_clientName);
     string get_client() const;
     void print_client();
};