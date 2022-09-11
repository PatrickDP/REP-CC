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
void StaticList::insertionSortList() {
    int i = 0;
    int j = 0;
    unsigned valueKey = 0;
    unsigned numMemoryAcessList;
    
    for(i = 1; i < sizeList; i++) {
        numMemoryAcessList = 0;
        j = i - 1;
        valueKey = clients[i].key;
        numMemoryAcessList++;

        eachStepList(i);
        
        while((j >= 0) && (valueKey < clients[j].key)) {
            clients[j + 1] = clients[j];

            eachStepList(i);
            
            numMemoryAcessList += 3;
            j--;
        }
        clients[j + 1].key = valueKey;
        numMemoryAcessList++;
        
        countMemoryAcessesList(numMemoryAcessList, i);
    }

    eachStepList(i);
    countMemoryAcessesList(numMemoryAcessList, i);
    
    cout << endl << "Insertion sorted list: "; printList();
}
void StaticList::eachStepList(int i) {
    static unsigned counter = 1;

    if(i == sizeList) {
        cout << counter << ". "; printList();

        counter = 0;
        return;
    }

    cout << counter << ". "; printList();

    counter++;
}
void StaticList::randomList() {
    unsigned randomKey = 0;

    for(unsigned i = 0; i < TOTAL_MAX; i++) {
       
        randomKey = rand() % TOTAL_MAX;   
       
        while(isRandomKey(randomKey)) {
            randomKey = rand() % TOTAL_MAX;
        }   
        
        clients[i].key = randomKey; 
        clients[i].name = "rc" + to_string(randomKey);
        
        sizeList++;
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
void StaticList::countMemoryAcessesList(unsigned num_MemoryAcessList, int i) {
    static unsigned totalMemoryAcesses = 0;
    static unsigned arrayMemoryAcessList[TOTAL_MAX * 100];

    static unsigned arrayMemoryAcessAccumulator[TOTAL_MAX * 100];
    static unsigned memoryAcessAcumulator = 0;

    if(i == sizeList) {
        printMemoryAcessesList(arrayMemoryAcessList, totalMemoryAcesses, arrayMemoryAcessAccumulator);
        return;
    }

    totalMemoryAcesses += num_MemoryAcessList;
    arrayMemoryAcessList[i - 1] = num_MemoryAcessList;

    memoryAcessAcumulator += num_MemoryAcessList;
    arrayMemoryAcessAccumulator[i - 1] += memoryAcessAcumulator;
}
void StaticList::printMemoryAcessesList(unsigned arrayMemoryAcessList[], unsigned totalMemoryAcesses, unsigned arrayMemoryAcessAccumulator[]) {
    cout << endl << "Memory acesses on the list during insertion sort: " << totalMemoryAcesses << endl;

    cout <<"Array of memory acesses value: ";
    for(unsigned i = 0; i < sizeList; i++) {
    cout << arrayMemoryAcessList[i] << " ";
    }
    cout << endl;

    cout <<"Acumulator Array of memory acesses value: ";
    for(unsigned i = 0; i < sizeList; i++) {
    cout << arrayMemoryAcessAccumulator[i] << " ";
    }
}