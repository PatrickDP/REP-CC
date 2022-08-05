#pragma once

#include <iostream>
#include <cmath>
#include "client.hpp"

using namespace std;

#define TOTAL_MAX 100

class StaticList {
public:
    unsigned sizeList = 0;
    Client clients[TOTAL_MAX + 1];
    
    unsigned memoryAcess_mergeSort = 0;
    unsigned memoryAcess_merge = 0;

    unsigned arr_mergeSort[TOTAL_MAX + 1] = {};
    unsigned arr_merge[TOTAL_MAX + 1] = {};

    unsigned total_memoryAcess_mergeSort = 0;
    unsigned total_memoryAcess_merge = 0;

    unsigned arr_totalMemoryAcess[TOTAL_MAX + 1] = {};

    unsigned total_memoryAcess = 0;

    unsigned acumulator_memoryAcess = 0;

    unsigned arr_acumulatorMemoryAcess[TOTAL_MAX + 1] = {};

    StaticList();
    ~StaticList();

    void printList();
    void addList(unsigned position, const Client & client);
    int searchList(unsigned key);
    void deleteList(unsigned key);
    
    void mergeSortList(Client clients[], Client auxiliarList[], unsigned left_limit, unsigned right_limit, string isRecursive);
    void merge(Client auxiliarList[],Client clients[], unsigned left_limit, unsigned mid_element, unsigned right_limit);
    
    void randomList();
    bool isRandomKey(unsigned randomKey);

    void eachStepList(Client clients[], Client auxiliarList[]);
    void printTwoLists(Client clients[], Client auxiliarList[]);

    void storeValueArrayMergeSort(unsigned num_memoryAcess, unsigned arr[]);
    void storeValueArrayMerge(unsigned num_memoryAcess, unsigned arr[]);

    void printMemoryAcessList();

};