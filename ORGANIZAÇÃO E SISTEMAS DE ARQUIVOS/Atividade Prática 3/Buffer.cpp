#include "library.hpp"

// Inicializa o buffer
Buffer::Buffer(char delimiter, unsigned bufferMaxSize) {
    initBuffer(delimiter, bufferMaxSize);
}

// Inicializa o buffer definindo o delimitador e o tamanho maximo
void Buffer::initBuffer(char delimiter, unsigned bufferMaxSize) {
    // O tamanho deve ser maior que 0
    assert(bufferMaxSize > 0);
    this->bufferMaxSize = bufferMaxSize;

    // O delimitador não pode ser vazio
    assert(delimiter != 0);
    this->delimiter = delimiter;

    // Aloca o vetor de dados e inicializa os demais atríbutos
    dataNetflix = new char[bufferMaxSize];
    dataNetflix[0] = 0;
    bufferSize = 0;
    nextIndexField = 0;
}

// Limpa o buffer
void Buffer::clearBuffer() {
    nextIndexField = 0;
    bufferSize = 0;
}

// Retorna o tamanho atual do buffer
unsigned Buffer::getBufferSize() const {
    return bufferSize;
}

// Exibe na saída padrão os dados do buffer (tamanho máximo e atual)
void Buffer::printBuffer() const {
    cout << endl << "\t <<< PRINT BUFFER >>>\n\n";

    if(bufferSize > 0) {
        char * aux = new char[bufferSize + 1];

        strncpy(aux, dataNetflix, bufferSize);
        aux[bufferSize] = '\0';
        
        cout << "Data: " << aux << endl;
        
        delete []aux;
    } else
        cout << "Data: <EMPTY>\n";

    cout << "Current  buffer data size: " << bufferSize << endl;
    cout << "Max buffer size: " << bufferMaxSize << endl;
}

// Lê os dados de um arquivo binário "in" já aberto e no formato correto ("tamanho do registro"+"registros separados por delimitador")
bool Buffer::readBuffer(istream &file) {
    // Limpa o buffer
    clearBuffer(); 

    fflush(stdin);

    // ler o tamanho do registro atual (que será o tamanho do buffer de dados)
    file.read((char *) &bufferSize, sizeof(bufferSize));

    if(file.fail())
        // Não leu o arquivo corretamente
        return false;
        
    if(bufferSize > bufferMaxSize)
        // Buffer overflow
        return false;

    // Ler o registro inteiro do arquivo de dados
    file.read(dataNetflix, bufferSize);

    return file.good();
}

// Escreve os dados em um arquivo binário
bool Buffer::writeBuffer(ostream &file) const {
    file.write((char *) &bufferSize, sizeof(bufferSize));
    file.write(dataNetflix, bufferSize);
    
    return file.good();
}

// Modifica o próximo campo do buffer
bool Buffer::packBuffer(const char * str, bool isDelimiter) {
    // Recupera o tamanho da string a ser adicionada ao buffer
    unsigned strSize = strlen(str);
    unsigned first = nextIndexField;


    // Deve-se somar 1 devido ao delimitador
    if(isDelimiter == true)
        nextIndexField += strSize + 1;
    else 
        nextIndexField += strSize - 1;

    if(nextIndexField > bufferMaxSize)
        // A adição do novo campo ultrapassa o tamanho maximo do buffer
        return false;

    memcpy(&dataNetflix[first], str, strSize);

    // Não deve colocar o delimitador caso seja o último campo
    if(isDelimiter == true)
        dataNetflix[first + strSize] = delimiter;

    bufferSize = nextIndexField;

    return true;
}

// Lê o proximo campo do buffer de forma circular
bool Buffer::unPackBuffer(string &str) {
    int postField = -1;

    for(unsigned i = nextIndexField; i < bufferSize; i++) {
        if(dataNetflix[i] != delimiter)
            str += dataNetflix[i];
        if(dataNetflix[i] == delimiter) {
            postField = i - nextIndexField;
            break;
        }
    }

    if(postField == -1)
        // Delimitador não encontrado (buffer vazio ou mal formado)
        return false;

    nextIndexField += postField + 1;

    if(nextIndexField > bufferMaxSize)
        return false;
    
    return true;
}

// Ler um registro do arquivo
void Buffer::readGetline(istream &file) {
    string getRecord;

    clearBuffer();

    getline(file, getRecord);

    strcpy(dataNetflix, (char *) getRecord.c_str());

    bufferSize = strlen(dataNetflix);
}

// Gera um arquivo de indice direto mapeando o ID
// Alteração 4 - (EM ANDAMENTO)
void Buffer::writeDirectIndexFile(ofstream &file, char* addressRecord, char* getShowID) {
    file.write(getShowID, sizeof(char*));
    file.write(addressRecord, sizeof(char*));
}

// Alteração 5 - (EM ANDAMENTO)
// Gera um arquivo de indice indireto (showID + title)
void Buffer::writeIndirectIndexFile(ofstream &file) {
    file.write(dataNetflix, bufferSize);
}

bool Buffer::searchRecordFile(string wantedKey, string nameFile, char option) {
    ifstream researchedFile(nameFile, ios::binary);
    ifstream recordFile2("indirectIndex_netflix_titles.bin", ios::binary);
    
    string getFields;
    string getField;
    vector<string> arrFields;
    vector<string> arrShowID;
    vector<string> arrTitle;
    string recordWord;

    bool recordFound = false;

    cout << endl << "In: " << wantedKey << endl;

    while(!recordFile2.eof()) {
        getline(recordFile2, getFields, ';');
        arrFields.push_back(getFields);
    }

    for(unsigned i = 0; i < arrFields.size(); i += 2)
        arrShowID.push_back(arrFields[i]);

    for(unsigned i = 1; i < arrFields.size(); i += 2)
        arrTitle.push_back(arrFields[i]);

    unsigned i = 0;

    while(!researchedFile.eof()) {
        recordWord = "";

        if(option == '1')
            getField = arrShowID[i];
        if(option == '2')
            getField = arrTitle[i];
        if (option != '1' && option != '2')
            break;

        readBuffer(researchedFile);

        for(unsigned i = 0; i < wantedKey.size(); i++) 
            for(unsigned j = 0; j < getField.size(); j++)
                if(toupper(getField[j]) == toupper(wantedKey[i])) {
                    recordWord += wantedKey[i];
                    i++;
                }


        if(strcmpi(wantedKey.c_str(), recordWord.c_str()) == 0) {
            cout << "Record found!" << endl;
            printBuffer();

            recordFound = true;
        }

        if(i <= TOTAL_MAX_RECORDS)
            i++;
    }

    if(!recordFound) {
        cout << "ERROR" << endl;
        return false;
    } else
        return true;
}

void Buffer::printDataFile(string fileName) {
    ifstream file(fileName, ios::binary);
    
    unsigned countRecordsFile = 0;
    
    vector<unsigned> arrSizeRegister;
    unsigned somatory = 0;
    double medianSizeBuffer = 0;
    
    vector<string> arrRecord;

    unsigned pointer;
    vector<unsigned> arrPointer;

    file.seekg(ios::beg);

    while(!file.eof()) {
        pointer = file.tellg();
        readBuffer(file);

        countRecordsFile++;
        
        arrSizeRegister.push_back(bufferSize);
        arrRecord.push_back(dataNetflix);
        arrPointer.push_back(pointer);
    }

    for(unsigned i = 0; i < TOTAL_MAX_RECORDS; i++)
        somatory += arrSizeRegister[i];
    medianSizeBuffer = somatory / countRecordsFile;

    for(unsigned i = 0; i < TOTAL_MAX_RECORDS - 1; i++)
        for(unsigned j = 0; j < TOTAL_MAX_RECORDS - i - 1; j++) {
            if(arrSizeRegister[j] > arrSizeRegister[j +1]) {
                swap(arrSizeRegister[j], arrSizeRegister[j + 1]);
                swap(arrRecord[j], arrRecord[j + 1]);
                swap(arrPointer[j], arrPointer[j + 1]);
            }
        }

    cout << "\t\t\t<<< Statistic Data>>>";
    cout << endl << "\t\t- Number of records in the file: " << countRecordsFile - 1 << ";" << endl;
    cout << "\t\t- Average size in bytes of each record: " << medianSizeBuffer << ";" << endl;
    cout << "\t\t- Smallest record found: " << arrRecord[0] << endl;
    cout << "\t\t\t- Size: " << arrSizeRegister[0] << ";" << endl;
    cout << "\t\t\t- Byte position: " << arrPointer[0] << ";" << endl;
    cout << "\t\t- Largest record found:: " << arrRecord[TOTAL_MAX_RECORDS - 1] << endl;
    cout << "\t\t\t- Size: " << arrSizeRegister[TOTAL_MAX_RECORDS - 1] << ";" << endl;
    cout << "\t\t\t- Byte position: " << arrPointer[TOTAL_MAX_RECORDS - 1] << ";" << endl;
}

// Novas funções (Trabalho 3)

void Buffer::removeRecordLengthIndicatorFile(string showID, Buffer &buff) {
    ifstream file("lengthIndicator_netflix_titles.bin", ios::in | ios::binary);
    ofstream tempFile("lengthIndicator_netflix_titles2.bin",  ios::out | ios::binary);

    // Aponta para para a primeira posição do registro no arquivo (LUGAR DO INDICADOR DE TAMANHO)
    char* addressRecord = 0;
    // Mesma coisa do anterior, apontando para um registro específico com base do showID
    string showIdResult;

    buff.printBuffer();

    file.seekg(ios::beg);
    
    // Realiza a "remoção" do registro inserindo um "*"
    while(!file.eof()) {
        // Encontra o show id correspondente
        string getShowID;

        // Pega a posição do registro no arquivo
        addressRecord = (char*) to_string(file.tellg()).c_str();

        buff.readBuffer(file);

        // Se ainda não foi encontrado o showID (valido para o início)
        if(strcmp((char *) getShowID.c_str(), (char *) showID.c_str()) != 0) {

            // Procura o showID correspondente em cada registro do arquivo pelo vetor dataNetflix da classe Buffer
            for(unsigned i = 0; i < showID.size(); i++) {
                if(buff.dataNetflix[i] == showID[i]) {
                    getShowID += showID[i];
                } else
                    break;
            }

        // Encontrou o registro! Modifica o vetor dataNetflix, para que depois ocorra a escrita no arquivo de indicaddor de tamanho
        } if (getShowID == showID) {
            dataNetflix[0] = '*';
    
            buff.writeBuffer(tempFile);
    
            removeRecordDirectIndexFile(showID, addressRecord);
            
            continue;
        }

        buff.writeBuffer(tempFile);
    }

    file.close();
    tempFile.close();

    rename("lengthIndicator_netflix_titles.bin", "tempFile.bin");
    rename("lengthIndicator_netflix_titles2.bin", "lengthIndicator_netflix_titles.bin");
    remove("tempFile.bin");
}

void Buffer::removeRecordDirectIndexFile(string showID, char* addressRecord) {
    ifstream file2("directIndex_netflix_titles.bin", ios::in | ios::binary);
    ofstream tempFile2("directIndex_netflix_titles2.bin",  ios::out | ios::binary);

    cout << endl<< "showID: " << showID << " - adressRecord: " << addressRecord << "\n\n";

    // Faz um seekg para a posiçaõ do inicio e no final
    file2.seekg(ios::end);
    file2.seekg(ios::beg);

    // Array de dados do arquivo de indice direto
    vector<string> arrData;

    while(!file2.eof()) {
        // O tamanho do registro no arquivo
        unsigned sizeBuff = file2.tellg();

        // Cria-se um buffer temporário para receber os dados
        char *buff = new char[sizeBuff];

        // Letiura
        file2.read(buff, sizeof(char*));

        // Os dados serão armazenados no array dessa forma: Primeiro o showID e depois a posição coresspondente no arquivo
        arrData.push_back(buff);
    }

    for(unsigned i = 0; i < arrData.size() - 1; i += 2) {
        // Encontrou o array correspondente

        if(arrData[i+1] == addressRecord) {
            arrData[i][0] = '*';

            // Uma nova leitura é feita
            writeDirectIndexFile(tempFile2, (char*) arrData[i+1].c_str(), (char*) arrData[i].c_str());

            // Pula para o próximo loop
            continue;
        }

         writeDirectIndexFile(tempFile2, (char*) arrData[i+1].c_str(), (char*) arrData[i].c_str());
    }

    file2.close();
    tempFile2.close();

    rename("directIndex_netflix_titles.bin", "tempFile2.bin");
    rename("directIndex_netflix_titles2.bin", "directIndex_netflix_titles.bin");
    remove("tempFile2.bin");
}

void Buffer::addRecordLengthIndicatorFile(string showID, Buffer &buff, unsigned &currentRecordSize) {
    ifstream file("lengthIndicator_netflix_titles.bin", ios::in | ios::binary);
    ofstream tempFile("lengthIndicator_netflix_titles2.bin",  ios::out | ios::binary);

    Buffer tempBuff;
    vector<string> arrShowID;
    bool controlInsertion = true;
    
    for(unsigned i = 0; i < currentRecordSize; i++) {
        tempBuff.readBuffer(file);
        arrShowID.push_back(getShowID(tempBuff));

        // Registro com "*" na primeira posição
        if(arrShowID[i][0] == '*' && i == 0) {
            buff.writeBuffer(tempFile);
            controlInsertion = false;
            continue;
        }
        
        // Caso de registros no meio;
        if(arrShowID[i][0] == '*' && controlInsertion == true) {
            buff.writeBuffer(tempFile);
            controlInsertion = false;
            continue;
        }

        // Espaço reservado no final do arquivo
        if(i == currentRecordSize - 1 && controlInsertion == true) {
            buff.writeBuffer(tempFile);
            controlInsertion = false;
            break;
        }

        tempBuff.writeBuffer(tempFile);
    }

    file.close();
    tempFile.close();

    rename("lengthIndicator_netflix_titles.bin", "tempFile.bin");
    rename("lengthIndicator_netflix_titles2.bin", "lengthIndicator_netflix_titles.bin");
    remove("tempFile.bin");

    sortRecordLengthIndicatorFile(currentRecordSize);
    addRecordDirectIndexFile(buff, currentRecordSize);
}

void Buffer::sortRecordLengthIndicatorFile(unsigned &currentRecordSize) {
    ifstream file("lengthIndicator_netflix_titles.bin", ios::in | ios::binary);
    ofstream tempFile("lengthIndicator_netflix_titles2.bin",  ios::out | ios::binary);

    Buffer* buff = new Buffer[currentRecordSize];
    vector<string> arrShowID;
    vector<int> arrNumberID;
    int idNumber = 0;
    char *temp;

    // Pega o showID
    for(unsigned i = 0; i < currentRecordSize; i++) {
        buff[i].readBuffer(file);
        arrShowID.push_back(getShowID(buff[i]));
    }

    // Pega apenas o número do showID sem o "s"
    for(unsigned i = 0; i < currentRecordSize; i++) {
        string str;

        for(unsigned j = 1; j < arrShowID[i].size(); j++) {
            str += arrShowID[i][j];
        }

        idNumber = stoi(str);

        arrNumberID.push_back(idNumber);
    }

    // Utiliza o buble sort para ordenar o arrNumberID e também o vetor de objetos da classe buffer;
    for (unsigned i = 0; i < arrNumberID.size(); i++) {
        for(unsigned j = 0; j < arrNumberID.size() - 1; j++) {
            if(arrNumberID[j] > arrNumberID[j+1]) {
                swap(arrNumberID[j], arrNumberID[j + 1]);
                swap(buff[j], buff[j + 1]);
            }
        }
    }

    // Escreve  o arquivo já ordenado
    for(unsigned i = 0; i < currentRecordSize; i++) {
        buff[i].writeBuffer(tempFile);
    }

    file.close();
    tempFile.close();

    delete buff;
    
    rename("lengthIndicator_netflix_titles.bin", "tempFile.bin");
    rename("lengthIndicator_netflix_titles2.bin", "lengthIndicator_netflix_titles.bin");
    remove("tempFile.bin");
}

void Buffer::addRecordDirectIndexFile(Buffer &buff, unsigned &currentRecordSize) {
    ifstream file("lengthIndicator_netflix_titles.bin", ios::in | ios::binary);

    ifstream file2("directIndex_netflix_titles.bin", ios::in | ios::binary);
    ofstream tempFile2("directIndex_netflix_titles2.bin",  ios::out | ios::binary);

    vector<string> arrShowID;
    char* addressRecord;

    file.seekg(ios::beg);

    for(unsigned i = 0; i < currentRecordSize; i++) {
        addressRecord = (char*) to_string(file.tellg()).c_str();

        readBuffer(file);

        arrShowID.push_back(getShowID(buff));

        buff.writeDirectIndexFile(tempFile2, addressRecord, (char *) arrShowID[i].c_str());
    }

    file2.close();
    tempFile2.close();

    rename("directIndex_netflix_titles.bin", "tempFile2.bin");
    rename("directIndex_netflix_titles2.bin", "directIndex_netflix_titles.bin");
    remove("tempFile2.bin");
}