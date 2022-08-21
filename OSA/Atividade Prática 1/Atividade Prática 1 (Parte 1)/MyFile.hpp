// #pragma once

#ifndef MYFILE_H
#define MYFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Client.hpp"

#define TOTAL_MAX_CLIENTS 1000

using namespace std;

class MyFile: public Client {
private:
    // QUANT. DE REGISTROS (CLIENTES) E INSTANCIA N REGISTROS (CLIENTES)  
    unsigned total_clients;
    Client clients[TOTAL_MAX_CLIENTS];
public:
    
    MyFile();
    ~MyFile();

    // ABRE, LER E IMPRIME DADOS DO ARQUIVO
    void open_file(fstream &file, const string &file_name);
    void read_file(fstream &file);
    void generate_file(string file_name);
    void print_clients();
};

#endif