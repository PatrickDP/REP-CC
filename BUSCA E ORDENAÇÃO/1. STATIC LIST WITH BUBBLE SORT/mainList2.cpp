#include <iostream>
#include <random>
#include <ctime>
#include <string>

#include "client.hpp"
#include "client.cpp"

#include "StaticList.hpp"
#include "StaticList.cpp"

using namespace std;

int main() {
    StaticList l2;

    l2.randomList();

    cout << endl;
    
    l2.printList();
    
    l2.~StaticList();

    l2.printList();
    
    return 0;
}