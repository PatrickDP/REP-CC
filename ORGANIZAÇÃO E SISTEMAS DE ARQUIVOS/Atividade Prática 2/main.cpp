#include <iostream>
#include "library.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    NetflixTitles* netflixTitles = new NetflixTitles[TOTAL_MAX_RECORDS + 1];
    Buffer buff;    
    string getRecord;
    
    // 1) - Gerando um novo arquivo com indicador de tamanho (OK)
    ifstream inFile("netflix_titles.csv", ios::binary);
    ofstream outFile("lengthIndicator_netflix_titles.bin", ios::binary);

    for(unsigned i = 0; i < TOTAL_MAX_RECORDS; i++) {
        buff.clearBuffer();
        buff.readGetline(inFile);
        netflixTitles[i].unPackBuffer(buff);
    }

    for(unsigned i = 0; i < TOTAL_MAX_RECORDS; i++) {
        buff.clearBuffer();
        netflixTitles[i].packBuffer(buff);
        buff.writeBuffer(outFile);
    }

    inFile.close();
    outFile.close();

    // 2) - Gerar 1 arquivo de índices direto mapeando o ID de todos os registros do arquivo. (OK!!!)
    fstream inFile2("lengthIndicator_netflix_titles.bin", ios::in | ios::out | ios::binary);
    ofstream outFile2("directIndex_netflix_titles.bin", ios::binary);

    string getShowID;

    unsigned beginPointer;

    buff.initBuffer(';', 1024);

    // Leva o ponteiro para o inicio do registro (BYTE OFFSET)
    inFile2.seekg(ios::beg);

    for(unsigned i = 0; i < TOTAL_MAX_RECORDS; i++) {
        // Pega apenas o show id
        getShowID = netflixTitles[i].getShowID();

        buff.clearBuffer();
        beginPointer = inFile2.tellg();

        buff.readBuffer(inFile2);
        buff.writeDirectIndexFile(outFile2, to_string(beginPointer), getShowID);
    }

    inFile2.close();
    outFile2.close();

    // 3) - Gerar 1 arquivo de índice indireto para recuperar todos os IDs de um registro, pelo seu título. (OK!!!)
    ifstream inFile3("netflix_titles.csv", ios::binary);
    ofstream outFile3("indirectIndex_netflix_titles.bin", ios::binary);

    string getTitle;

    buff.initBuffer(';', 1024);

    for(unsigned i = 0; i < TOTAL_MAX_RECORDS; i++) {
        // Pegao show id e o title
        getShowID = netflixTitles[i].getShowID();
        getTitle = netflixTitles[i].getTitle();

        buff.clearBuffer(); 
        buff.packBuffer(getShowID.c_str(), true);
        buff.packBuffer(getTitle.c_str(), true);

        getline(inFile3, getRecord);
        

        buff.writeIndirectIndexFile(outFile3);
    }

    inFile3.close();
    outFile3.close();
    
    // 4) - Possibilitar a pesquisa e exibição de um determinado registro pelo seu SHOW_ID ou pelo seu TÍTULO. (100%)
    buff.initBuffer(';', 1024);

    string nameFile = "lengthIndicator_netflix_titles.bin";

    cout << "\t\t\t <<< Options >>>" << endl;
    cout << "( 1 ) for search show_id in file:" << endl;
    cout << "( 2 ) for search title in file:\n\n";

    buff.searchRecordFile("s200", nameFile, '1');
    buff.searchRecordFile("monster high", nameFile, '2');

    // 5) - Informar estatísticas do arquivo lido como, a quantidade de registros, o tamanho médio em...
    buff.initBuffer(';', 1024);

    buff.printDataFile("lengthIndicator_netflix_titles.bin");

    return 0;
}