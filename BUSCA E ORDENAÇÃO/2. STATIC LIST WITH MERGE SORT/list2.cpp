#include <iostream>
#include "client.hpp"
#include "client.cpp"
#include "StaticList.hpp"
#include "StaticList.cpp"

using namespace std;

int main() {
    StaticList l2;

    l2.randomList();
    l2.printList(); cout << endl;

    StaticList auxiliarList = l2;

    l2.mergeSortList(l2.clients, auxiliarList.clients, 0, l2.sizeList, "No recursion");
    cout << endl << "====> Merge sort list: "; l2.printList();
    l2.printMemoryAcessList();

    return 0;
}