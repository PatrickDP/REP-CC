#include "library.hpp"

// Novas funções (Trabalho 3)

// Remove o registro primeiramente na classe e depois no arquivo
void removeRecord(string showID, unsigned &currentRecordSize, Buffer &buff, NetflixTitles *netflixTitles) {
    bool recordFound = false;
    unsigned getIndex = 0;

    // Procurao showID correspondente da remoç~~ao
    for(unsigned i = 0; i < currentRecordSize; i++) {
        if(netflixTitles[i].findSomething(showID, netflixTitles[i].showID) == true) {
            recordFound = true;
            getIndex = i;

            break;
        }
    }

    // Encontrou! faça um "pack" dos dados na classe BUffer
    if(recordFound == true) {
        netflixTitles[getIndex].showID[0] = '*';

        netflixTitles[getIndex].printData();
        netflixTitles[getIndex].packBuffer(buff);

        // Agora a remoção acontece no arquivo
        buff.removeRecordLengthIndicatorFile(strcat((char *)showID.c_str(), ";"), buff);

    } else
        return;
}

// Adiciona um registro
void addRecord(string showID, string type, string title, string country, string release, unsigned &currentRecordSize, Buffer &buff, NetflixTitles *netflixTitles) {
    // Pega o indice
    int getIndex = 0;
    bool availableSpace = false;

    // Procura um showID com "*"
    for(unsigned i = 0; i < currentRecordSize; i++) {
        // Existe um campo removido (com "*"), não precisar aumentar o tamanho do arquivo
        if(netflixTitles[i].findSomething(to_string(netflixTitles[i].showID[0]), to_string('*')) == true) {
            getIndex = i;
            availableSpace = false;

            break;
        } else {
            getIndex++;
            availableSpace = true;
        }
    }

    // Procura o mesmo showID, se não encontrar
    for(unsigned i = 0; i < currentRecordSize; i++) {
        // Já tem um registro com o mesmo show ID (não adiciona)
        if(netflixTitles[i].findSomething(showID, netflixTitles[i].showID) == true) { 
            cout << endl << "A record with showID \"" << showID << "\" already exists!" << endl;
            return;
        }
    }

    // Tem espaço disponível, insere na última posição e incrementa o tamanho
    if(availableSpace == true) {
        currentRecordSize++;
    }
    
    netflixTitles[getIndex].setDataNetflix(showID, type, title, country, release);

    sortRecord(netflixTitles, currentRecordSize);

    netflixTitles[getIndex].packBuffer(buff);
    netflixTitles[getIndex].printData();

    buff.addRecordLengthIndicatorFile(netflixTitles[getIndex].showID, buff, currentRecordSize);
}

void sortRecord(NetflixTitles *netflixTitles, unsigned &currentRecordSize) { 
    vector<int> arrIdNumber = getIDNumber(netflixTitles, currentRecordSize);

    for (unsigned i = 0; i < arrIdNumber.size(); i++) {
        for(unsigned j = 0; j < arrIdNumber.size() - 1; j++) {
            if(arrIdNumber[j] > arrIdNumber[j+1])
                swap(arrIdNumber[j], arrIdNumber[j + 1]);
        }
    }
}

vector<int> getIDNumber(NetflixTitles *netflixTitles, unsigned &currentRecordSize) {
    vector<int> arrIdNumber;
    int idNumber = 0;

    for(unsigned i = 0; i < currentRecordSize; i++) {
        string str1;
        for(unsigned j = 1; j < netflixTitles[i].showID.size(); j++) {
            str1 += netflixTitles[i].showID[j];
        }

        idNumber = stoi(str1);
        arrIdNumber.push_back(idNumber);
    }

    return arrIdNumber;
}

string getShowID(Buffer &buff) {
    string showID;

    for(unsigned i = 0; i < strlen(buff.dataNetflix); i++) {

        if(buff.dataNetflix[i] != ';')
            showID += buff.dataNetflix[i];
        else
            break;
    }

    return showID;
}