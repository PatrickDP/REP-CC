#include <iostream>
#include <fstream>

#include "myFile.hpp"
#include "myFile.cpp"

#include "client.hpp"
#include "client.cpp"

using namespace std;

int main() {
    // ARQUIVO E NOME DO ARQUIVO
    fstream file;
    string file_name("Arquivo_Nomes.txt");

    // INSTACIA A CLASSE myFile
    myFile my_file;
    Client client[TOTAL_MAX_CLIENTS];

    my_file.open_file(file, file_name);
    my_file.read_file(file);
    my_file.print_clients();
    return 0;
}