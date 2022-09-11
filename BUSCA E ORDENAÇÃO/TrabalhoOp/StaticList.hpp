#pragma once

#include <iostream>

#include "client.hpp"

using namespace std;

#define TOTAL_MAX 100

class StaticList {
public:
    unsigned sizeList = 0;
    Client clients[TOTAL_MAX];
    unsigned arrayMemoryAcess[TOTAL_MAX * 100];

    StaticList();
    ~StaticList();

    void printList();
    void addList(unsigned position, const Client & client);
    int searchList(unsigned key);
    void deleteList(unsigned key);
    void insertionSortList();
    void eachStepList(int i);
    void randomList();
    bool isRandomKey(unsigned randomKey);
    void countMemoryAcessesList(unsigned numMemoryAcessList, int i);
    void printMemoryAcessesList(unsigned arrayMemoryAcessList[], unsigned totalMemoryAcesses, unsigned arrayMemoryAcessAccumulator[]);
};