#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "client.hpp"

#define TOTAL_MAX_CLIENTS 1000

using namespace std;

class myFile: public Client{
private:
    // QUANT. DE REGISTROS (CLIENTES) E INSTANCIA N REGISTROS (CLIENTES)  
    unsigned total_clients;
    Client clients[TOTAL_MAX_CLIENTS];
public:
    
    myFile();

    // ABRE, LER E IMPRIME DADOS DO ARQUIVO
    void open_file(fstream &file, const string &file_name);
    void read_file(fstream &file);
    void print_clients();
};