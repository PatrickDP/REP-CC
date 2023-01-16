#include <iostream>
#include "library.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Alteração 1 - Aumentar para +100 o tamanho total de registros no arquivo para adicionar novos registros
    NetflixTitles* netflixTitles = new NetflixTitles[TOTAL_MAX_RECORDS + 100]; 
    Buffer buff;    
    string getRecord;
    
    // Gerando um novo arquivo com indicador de tamanho
    ifstream inFile("netflix_titles.csv", ios::binary);
    ofstream outFile("lengthIndicator_netflix_titles.bin", ios::binary);

    while(!inFile.eof()) {
        buff.clearBuffer();
        buff.readGetline(inFile);

        // Alteração 2 - Ignorar o registro cabeçalho, quando o contador foir igual a zero, uma nova leitura é feita
        if(currentRecordSize == 0)
            buff.readGetline(inFile);

        netflixTitles[currentRecordSize].unPackBuffer(buff);
    
        currentRecordSize++;
    }

    for(unsigned i = 0; i < currentRecordSize; i++) {
        buff.clearBuffer();
        netflixTitles[i].packBuffer(buff);
        buff.writeBuffer(outFile);
    }

    inFile.close();
    outFile.close();

    // Gera 1 arquivo de índices direto mapeando o ID de todos os registros do arquivo.
    fstream inFile2("lengthIndicator_netflix_titles.bin", ios::in | ios::out | ios::binary);
    ofstream outFile2("directIndex_netflix_titles.bin", ios::out | ios::binary);

    // Alteração 3 - Sendo a organização dos campos do registros com tamanho fixo, faz sentido utilizar char* ao invés de string
    char* getShowID;
    char* addressRecord;

    buff.initBuffer(';', 1024);

    // Leva o ponteiro para o inicio do registro (BYTE OFFSET)
    inFile2.seekg(ios::beg);

    for(unsigned i = 0; i < currentRecordSize; i++) {
        // buff.clearBuffer();

        getShowID = (char*) netflixTitles[i].getShowID().c_str();
        addressRecord = (char*) to_string(inFile2.tellp()).c_str();

        buff.readBuffer(inFile2);
        buff.writeDirectIndexFile(outFile2, addressRecord, getShowID);
    }

    inFile2.close();
    outFile2.close();

    // Parte 1 - Remove um registro através da chave (showID) (OK)
    cout << "______________________________________ Remove Record ______________________________________" << endl;

    buff.initBuffer(';', 1024);

    removeRecord("s1", currentRecordSize, buff, netflixTitles);
    removeRecord("s5", currentRecordSize, buff, netflixTitles);
    removeRecord("s7787", currentRecordSize, buff, netflixTitles);

    // Parte 2 - Adiciona um novo registro através da chave (showID)
    cout << "______________________________________ Add Record ______________________________________" << endl;

    addRecord("s1", "Movie", "Bloodborne - The Movie", "Japan", "2030", currentRecordSize, buff, netflixTitles);
    addRecord("s2", "Movie", "LionKing", "USA", "1994", currentRecordSize, buff, netflixTitles);
    addRecord("s7787", "Movie", "Bloodborne 2 - The Movie", "Japan, South Korea", "2045", currentRecordSize, buff, netflixTitles);
    addRecord("s8000", "Serie", "Fun With Dark Souls", "Japan", "2024", currentRecordSize, buff, netflixTitles);
    addRecord("s7880", "Movie", "LionKing", "USA", "1994", currentRecordSize, buff, netflixTitles);

    // for(unsigned i = 0; i < currentRecordSize; i++)
        // netflixTitles[i].printData();

    return 0;
}