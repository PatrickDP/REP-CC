#ifndef RECORD_HPP
#define RECORD_HPP

#define TOTAL_MAX_RECORD 101

#include <iostream>
#include <cstring>

using namespace std;

// Classe de registros com campos (NOME, SOBRENOME, TELEFONE E DATA DE NASCIMENTO)
class Record {
public:
    char name_record[30];
    char lastName_record[15];
    char phone_record[16];
    char birthDate_record[11];
    
    // Inicializa as variaveis;
    Record();

    // Imprime os registros
    void print_record();
};

#endif // !RECORD_H
