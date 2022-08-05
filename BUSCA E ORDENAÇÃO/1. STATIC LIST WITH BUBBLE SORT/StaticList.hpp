#pragma once

#include <iostream>

#include "client.hpp"

using namespace std;

#define TOTAL_MAX 100

class StaticList {
public:
    unsigned sizeList = 0;
    Client clients[TOTAL_MAX];

    StaticList();
    ~StaticList();

    void printList();
    void addList(unsigned position, const Client & client);
    int searchList(unsigned key);
    void deleteList(unsigned key);
    void otmBubbleSort(unsigned option);
    void randomList();
    bool isRandomKey(unsigned randomKey);
};