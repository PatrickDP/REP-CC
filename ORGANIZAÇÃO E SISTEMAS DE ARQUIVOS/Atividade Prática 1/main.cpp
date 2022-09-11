#include <iostream>
#include <fstream> 

#include "Record.hpp"
#include "Auxiliar.hpp"

using namespace std;

int main() {
    // Objetos para arquivos
    fstream file;
    fstream file1_1;
    fstream file1_2;
    fstream file2;
    fstream file3_1;
    fstream file3_2;

    // Cria uma instância de objeto da classe Auxiliar
    Auxiliar auxiliar;

    /// 0 - PADRÃO - ABRE E LER O ARQUIVO
    auxiliar.open_file(file, "Dados.txt");

    // Cria um array de 101 objetos de Record
    Record* record = new Record[TOTAL_MAX_RECORD];

    // Dentro do for, faz-se a chamada da função read_file e passa como parametro o arquivo e um objeto em i de record
    for(unsigned i = 0; i < TOTAL_MAX_RECORD; i++)
        auxiliar.read_file(file, record[i]);

    // ESCREVE
    fstream out_file("0.StandardFile.txt", ios::out);
    fstream out_file1_1("1.1.fixedLengthFile.txt", ios::out);
    fstream out_file1_2("1.2.fixedLengthFile.txt", ios::out);
    fstream out_file2("2.tagFile.txt", ios::out);
    fstream out_file3_1("3_1.lengthIndicator_file.txt", ios::out);
    fstream out_file3_2("3_2.lengthIndicador_file.txt", ios::out);

    for(unsigned i = 1; i < TOTAL_MAX_RECORD; i++) {
        // Padrão
        auxiliar.generate_file(out_file, record[i]);
        // Campos de tamanho fixo
        auxiliar.generate_fixedLengthField_file(out_file1_1, record[i]);
        // Registros de tamanho fixo
        auxiliar.generate_fixedrecordLength_file(out_file1_2, record[i]);
        // Campos por tag
        auxiliar.generate_tagField_file(out_file2, record[i]);
        // Campos com indicador de tamanho
        auxiliar.generate_lengthIndicatorField_file(out_file3_1, record[i]);
        // Registros com indicador de tamanho
        auxiliar.generate_lengthIndicatorRecord_file(out_file3_2, record[i]);
    }

    cout << endl << "0 - STANDARD" << endl;
    auxiliar.print_record(record);

    // Fecha os arquivos
   out_file.close();
   out_file1_1.close();
   out_file1_2.close();
   out_file2.close();
   out_file3_1.close();
   out_file3_2.close();
   file.close();

    // Deleta  o objeto
    delete record;      

    // 1 - TAMANHO FIXO - ABRE, LER E IMPRIME OS ARQUIVOS
    auxiliar.open_file(file1_1, "1.1.fixedLengthFile.txt");
    auxiliar.open_file(file1_2, "1.2.fixedLengthFile.txt");

    Record* record1_1 = new Record[TOTAL_MAX_RECORD];
    Record* record1_2 = new Record[TOTAL_MAX_RECORD];

    for(unsigned i = 0; i < TOTAL_MAX_RECORD - 1; i++) {
        auxiliar.read_fixedLengthField_file(file1_1, record1_1[i], i);
        auxiliar.read_fixedrecordLength_file(file1_2, record1_2[i], i);
    }

    cout << endl << "1 - FIX LENGTH FIELDS AND RECORDS" << endl;
    auxiliar.print_record(record1_1);
    auxiliar.print_record(record1_2);

    file1_1.close();
    file1_2.close();

    delete record1_1;
    delete record1_2;

    // 2 - POR TAGS - ABRE, LER E IMPRIME OS ARQUIVOS
    auxiliar.open_file(file2, "2.tagFile.txt");

    Record* record2 = new Record[TOTAL_MAX_RECORD];

    for(unsigned i = 0; i < TOTAL_MAX_RECORD - 1; i++)
        auxiliar.read_tagField_file(file2, record2[i]);

    cout << endl << "2 - TAGS" << endl;
    auxiliar.print_record(record2);

    file2.close();

    delete record2;

    // 3 - POR INDICADOR DE TAMANHO - ABRE, LER E IMPRIME OS ARQUIVOS
    auxiliar.open_file(file3_1, "3_1.lengthIndicator_file.txt");
    auxiliar.open_file(file3_2, "3_2.lengthIndicador_file.txt");

    Record* record3_1 = new Record[TOTAL_MAX_RECORD];
    Record* record3_2 = new Record[TOTAL_MAX_RECORD];

    for(unsigned i = 0; i < TOTAL_MAX_RECORD - 1; i++) {
        auxiliar.read_lengthIndicatorField_file(file3_1, record3_1[i], i);
        auxiliar.read_lengthIndicatorRecord_file(file3_2, record3_2[i], i);
    }

    cout << endl << "3 - LENGTH INDICATOR" << endl;
    auxiliar.print_record(record3_1);
    auxiliar.print_record(record3_2);

    file3_1.close();
    file3_2.close();

    delete record3_1;
    delete record3_2;

    return 0;
}