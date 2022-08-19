#include "myFile.hpp"

myFile::myFile() {
    total_clients = 0;
}

void myFile::open_file(fstream &file, const string &file_name) {
    // ABRE O ARQUIVO
    file.open(file_name);
    
    // O ARQUIVO NÃO ABRIU (TEM NOME DIFERENTE)
    if (!file.is_open()) {
        cerr << "Error opening file" << file_name << "! CLOSING..." << endl;;
        exit(1);
    }
}

void myFile::read_file(fstream &file) {
    //VAR. DE AUX QUE ARMAZENA UMA STRING NO REGISTRO
    string aux_string;
    
        // O ARQUIVO CHEGOU NA ÚLTIMA LINHA?
        while(file) {
        // AUXILAR RECEBE A STRING DE UMA LINHA DO ARQUIVO PELO MÉT. getline()
        getline(file, aux_string);
        
        // ENQUANTO O CONTADOR FOR MENOR QUE O NÚMERO DE CLIENTES, ARMAZENE ELES
        if(total_clients < TOTAL_MAX_CLIENTS) {
            clients[total_clients++].set_client(aux_string); 
        }

    }
}

void myFile::print_clients() {
    cout << "Read datas..." << endl;

    for(unsigned i = 0; i < total_clients; i++) {
        cout << setfill('0') << setw(4) << i + 1 << ". "; clients[i].print_client(); cout << endl;
    }
}