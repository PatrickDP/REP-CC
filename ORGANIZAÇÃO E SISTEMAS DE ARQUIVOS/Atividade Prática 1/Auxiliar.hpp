#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

#include "Record.hpp"

// Classe para utilizar as operações de arquivos
class Auxiliar {
public: 
    // FUNÇÕES AUXILIARES
    // calcula o tamanho do registro
    unsigned get_recordLength(Record &record);
    // Pega linha do arquivo
    fstream& getLine_file(fstream& file, unsigned num_line);
    // Seta os dados no registro
    void setFieldsFile_record(vector<string> arr_fields, Record &record);

    // 0 - PADRÃO
    // Abre, ler e gera o arquivo na forma padrão
    void open_file(fstream &file, string file_name);
    void read_file(fstream &file, Record &record);
    void generate_file(fstream& delimiterFields_file, Record &record);

    // 1 - TAMANHO FIXO
    // Ler e escreve campos de registros
    void read_fixedLengthField_file(fstream &file, Record &record, unsigned index);
    void generate_fixedLengthField_file(fstream &fixLengthField_file, Record &record);

    // Ler e escreve registros
    void read_fixedrecordLength_file(fstream &file, Record &record, unsigned index);
    void generate_fixedrecordLength_file(fstream &fixrecordLength_file, Record &record);

    // 2 - POR TAGS
    // Ler e escreve campos de registros em tags
    void read_tagField_file(fstream &file, Record &record);
    void generate_tagField_file(fstream &tagField_file, Record &record);

    // 3 - INDICADOR DE TAMANHO
    // Ler e escreve campos de registro
    void read_lengthIndicatorField_file(fstream &file, Record &record, unsigned index);
    void generate_lengthIndicatorField_file(fstream &lengthIndicatorField_file, Record &record);

    // Ler e escreve registros
    void read_lengthIndicatorRecord_file(fstream &file, Record &record, unsigned index);
    void generate_lengthIndicatorRecord_file(fstream &lengthIndicatorRecord_file, Record &record);

    // Imprime o registro
    void print_record(Record *record);
};

#endif // !AUXILIAR_HPP
