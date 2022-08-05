#include "StaticList.hpp"

StaticList::StaticList() { sizeList = 0; }
StaticList::~StaticList() { 
    Client client;

    for(int i = sizeList; i >= 0; i--) {
        clients[i] = client;
    }

    sizeList = 0;
}

void StaticList::printList() {
    if(sizeList == 0) { 
        cout << endl << "ERROR: Empty List." << endl;
        return;
    }

    for(unsigned i = 0; i < sizeList; i++) {
        clients[i].printClient();
    }

    cout << endl;
}
void StaticList::addList(unsigned position, const Client & client) {
    if(position > sizeList) {
        cout << "Error: Invalid position." << endl;
        return;
    }
    if(TOTAL_MAX == sizeList) {
        cout << "Error: Full List." << endl;
        return;
    }

    for(int i = sizeList; i > position; i--) {
        clients[i] = clients[i - 1];
    }

    clients[position] = client;
    sizeList++;
}
int StaticList::searchList(unsigned key) {
    int index = -1;
    unsigned position = 0;

    while(position < sizeList) {
        if(clients[position].key == key) {
            index = position;
            position = sizeList;
        }

        position++;
    }

    return index;
}
void StaticList::deleteList(unsigned key) {
    int position = 0;

    position = searchList(key);

    if(position >= 0) {
        sizeList--;
        
        for(unsigned i = position; i < sizeList; i++) {
            clients[i] = clients[i + 1];
        }
    }
}
void StaticList::otmBubbleSort(unsigned option) {
    // Verifica se a passada ocorreu.
    bool isChange = true; 
    // Armazena onde foi a última passada.
    unsigned lastModif = sizeList;
    //Guarda o indice "j".
    unsigned aux = sizeList - 1;  
    // Conta quantas vezes ocorreu a interação do while + for.
    unsigned stepCounter = 0;
    // Contador de acesso a memória na lista.
    unsigned memoryAcessCounter = 0;

    // - option = 1 Para visualizar cada interação executada pelo método bubble sort;
    // - option = 2 Para visualizar a quantidade de acesso a memória realizados na lista; 

    while(isChange) {
        isChange = false;
        
        if(option == 1) {
            // OPCAO 1: CADA INTERAÇÃO DO BUBBLE SORT
            cout << stepCounter + 1 << "." << "\t aux = " << aux << "   \t-\tlastModif = " << lastModif << "   \t-\t"; 
            printList();
        }
        
        for(unsigned j = 0; j < lastModif - 1; j++) {
            
            memoryAcessCounter += 2;
            
            if(clients[j].key > clients[j + 1].key) {
                isChange = true;
                aux = j;
                swap(clients[j], clients[j + 1]);
                
                memoryAcessCounter += 3;
            }
            
            stepCounter++;
            
            if(option == 1) {
                // OPCAO 1: CADA INTERAÇÃO DO BUBBLE SORT
                cout << stepCounter + 1 << "." << "\t aux = " << aux << "   \t-\tlastModif = " << lastModif << "   \t-\t"; 
                printList();
            }
        }

        lastModif = aux + 1;
    }

    // OPCAO 2: NUMERO DE ACESSOS DA MEMÓRIA DA ESTRUTURA DE DADOS
    if(option == 2) {
        cout << "Number of memory accesses performed in the list: " << memoryAcessCounter++ << endl;
        // cout << memoryAcessCounter << " ";
    } 
}
void StaticList::randomList() {
    unsigned randomKey = 0;

    // srand(time(NULL));
    for(unsigned i = 0; i < TOTAL_MAX; i++) {
       
        randomKey = rand() % TOTAL_MAX;   
       
        while(isRandomKey(randomKey)) {
            randomKey = rand() % TOTAL_MAX;
        }   
        
        clients[i].key = randomKey; 
        clients[i].name = "rc" + to_string(randomKey);
        
        sizeList++;
        
        otmBubbleSort(2);
    }
}
bool StaticList::isRandomKey(unsigned randomKey) {
    for(unsigned i = 0; i < sizeList; i++) {
        if(clients[i].key == randomKey) {
            return true;
        }
    }
    
    return false;
}