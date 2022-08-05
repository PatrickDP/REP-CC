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
// EXPLICAR
void StaticList::mergeSortList(Client clients[], Client auxiliarList[], unsigned left_limit, unsigned right_limit, string isRecursive) {
    memoryAcess_mergeSort += 1;
    
    cout << isRecursive << ":   "; eachStepList(clients, auxiliarList);
    
    if(left_limit == 0 && right_limit == sizeList) {
        storeValueArrayMergeSort(memoryAcess_mergeSort, arr_mergeSort);
    }

    memoryAcess_mergeSort += 1;
    if(left_limit < right_limit - 1) {
        unsigned mid_element = (left_limit + right_limit) / 2;
        
        // cout << "left_limit = " << left_limit << " - mid_element = " << mid_element << " - right_limit = " << right_limit << endl;
        
        storeValueArrayMergeSort(memoryAcess_mergeSort, arr_mergeSort);

        memoryAcess_mergeSort += 1;
        mergeSortList(auxiliarList, clients, left_limit, mid_element, "Left recursion");
        
        memoryAcess_mergeSort += 1;
        mergeSortList(auxiliarList, clients, mid_element, right_limit, "Right recursion");
        
        memoryAcess_mergeSort += 1;
        merge(clients, auxiliarList, left_limit, mid_element, right_limit);
    } else {
        cout << "\t\t\t>> ERROR: False condition in " << isRecursive << ". Unstacking now... <<" << endl;
    }

}
// EXPLICAR
void StaticList::merge(Client auxiliarList[], Client clients[], unsigned left_limit, unsigned mid_element, unsigned right_limit) {
    memoryAcess_merge += 1;

    unsigned left_limit_aux = left_limit;
    unsigned mid_element_aux = mid_element;
    
    storeValueArrayMerge(memoryAcess_merge, arr_merge);

    // cout << "left_limit = " << left_limit << " - mid_element = " << mid_element << " - right_limit = " << right_limit << endl;

    for(unsigned i = left_limit; i < right_limit; i++) {
        memoryAcess_merge += 6;
        if(left_limit_aux < mid_element && ((mid_element_aux >= right_limit) || (clients[left_limit_aux].key < clients[mid_element_aux].key))) {
            auxiliarList[i] = clients[left_limit_aux];
            left_limit_aux++;
            memoryAcess_merge += 2;
        }
        else {
            auxiliarList[i] = clients[mid_element_aux];
            mid_element_aux++;
            memoryAcess_merge += 2;
        }
    }
    cout << "Call Merge:\t\t"; eachStepList(auxiliarList, clients);
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
// EXPLICAR
void StaticList::eachStepList( Client clients[], Client auxiliarList[]) { // OK
    static unsigned counter = 1;
    cout << "\t\t" << counter << ".\t"; printTwoLists(clients, auxiliarList);
    counter++;
}
// EXPLICAR
void StaticList::printTwoLists(Client clients[], Client auxiliarList[]) { // OK
    cout << "1° parameter:\t";
    for(unsigned i = 0; i < sizeList; i++) {
        clients[i].printClient();
    }

    cout << "\t-\t 2° parameter:\t "; 
    for(unsigned i = 0; i < sizeList; i++) {
        auxiliarList[i].printClient();
    }
    cout << endl;
}
// EXPLICAR
void StaticList::storeValueArrayMergeSort(unsigned num_memoryAcess, unsigned arr[]) {
    static unsigned index = 0;
    
    if(index < sizeList) {
        arr[index] = num_memoryAcess;
        index++;
    } else { index = 0; }
}
void StaticList::storeValueArrayMerge(unsigned num_memoryAcess, unsigned arr[]) {
    static unsigned index = 0;
    
    if(index < sizeList) {
        arr[index] = num_memoryAcess;
        index++;
    } else { index = 0; }
}
// EXPLICAR
void StaticList::printMemoryAcessList() {

    cout << endl <<"- Array of memory acesses in mergeSort function:\t\t";
    for(unsigned i = 0; i < sizeList; i++) {
        total_memoryAcess_mergeSort += arr_mergeSort[i];
        cout << arr_mergeSort[i] << " ";
    }
    cout << endl;

    cout <<"- Array of memory acesses in merge function:\t\t\t";
    for(unsigned i = 0; i < sizeList; i++) {
        total_memoryAcess_merge += arr_merge[i];
        cout << arr_merge[i] << " ";
    }
    cout << endl;
    
    cout << "- Memory acesses on the list during mergeSort function:\t" << total_memoryAcess_mergeSort << endl;
    cout << "- Memory acesses on the list during merge function:\t\t" << total_memoryAcess_merge << endl;

    cout << endl <<"> Array of total memory acesses:\t\t\t\t\t\t";
    for(unsigned i = 0; i < sizeList; i++) {
        arr_totalMemoryAcess[i] = arr_mergeSort[i] + arr_merge[i];
        cout << arr_totalMemoryAcess[i] << " ";
    }
    cout << endl;

    total_memoryAcess = total_memoryAcess_mergeSort + total_memoryAcess_merge;

    cout << "> Total of memoryAcess in mergeSort algorithm:\t\t\t" << total_memoryAcess << endl;

    cout << endl << "- Acumulator Array of memory acesses value:\t\t\t\t";
    for(unsigned i = 0; i < sizeList; i++) {
        arr_acumulatorMemoryAcess[i] = acumulator_memoryAcess + arr_totalMemoryAcess[i];
        acumulator_memoryAcess = arr_acumulatorMemoryAcess[i];
        cout << arr_acumulatorMemoryAcess[i] << " ";
    }
    cout << endl;
}