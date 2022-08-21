#include <iostream>
#include <fstream>

#include "Client.hpp"
#include "MyFile.hpp"

using namespace std;

int main() {
    // ARQUIVO E NOME DO ARQUIVO
    fstream file;
    string file_name("Arquivo_Nomes.txt");

    // INSTACIA A CLASSE MyFile e os clientes
    Client client[TOTAL_MAX_CLIENTS];
    MyFile my_file;

    my_file.open_file(file, file_name);
    my_file.read_file(file);
    my_file.generate_file("new_file.txt");
    my_file.print_clients();

    file.close();
    return 0;
}