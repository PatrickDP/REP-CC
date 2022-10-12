#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include "library.hpp"

using namespace std;

class Buffer{
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
    void writeDirectIndexFile(ofstream &file, string beginPointer, string getShowID);
    void writeIndirectIndexFile(ofstream &file);
    bool searchRecordFile(string wantedKey, string nameFile, char option);
    void printDataFile(string fileName);
};

#endif // !BUFFER_HPP