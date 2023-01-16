#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include "library.hpp"

using namespace std;

class Buffer {
private:
    // Delimitador ";"
    char delimiter;
    // Vetor para dados
    // Tamanho do buffer
    unsigned bufferSize;
    unsigned bufferMaxSize;
    // Endereço para o próximo campo a ser lido ou incluído no buffer
    unsigned nextIndexField;

public:
    char * dataNetflix;
    Buffer(char delimiter=';', unsigned bufferMaxSize=1024);

    void initBuffer(char delimiter, unsigned bufferMaxSize);
    void clearBuffer();
    unsigned getBufferSize() const;
    void printBuffer() const;
    bool readBuffer(istream &file);
    bool writeBuffer(ostream &file) const;
    bool packBuffer(const char * str, bool isDelimiter);
    bool unPackBuffer(string &str);

    void readGetline(istream &file);
    void writeDirectIndexFile(ofstream &file, char* addressRecord, char* getShowID);
    void writeIndirectIndexFile(ofstream &file);
    bool searchRecordFile(string wantedKey, string nameFile, char option);
    void printDataFile(string fileName);

    // Novas funções (Trabalho 3)

    // "Remove" o registro no arquivo lengthIndicator inserindo um "*"
    void removeRecordLengthIndicatorFile(string showID, Buffer &buff);
    void removeRecordDirectIndexFile(string showID, char* addressRecord);
    // Adiciona um registro no arquivo de indicador de tamanho
    void addRecordLengthIndicatorFile(string showID, Buffer &buff, unsigned &currentRecordSize);
    // Ordena o aarquivo de indicador de tamanho
    void sortRecordLengthIndicatorFile(unsigned &currentRecordSize);
    // Adiciona um registro no arquivo de indice indireto
    void addRecordDirectIndexFile(Buffer &buff, unsigned &currentRecordSize);
};

#endif // !BUFFER_HPP