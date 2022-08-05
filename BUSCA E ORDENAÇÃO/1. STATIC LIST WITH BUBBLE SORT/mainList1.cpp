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
    Client c1(70, "c1");
    Client c2(1, "c2");
    Client c3(12, "c3");
    Client c4(8, "c4");
    Client c5(99, "c5");
    Client c6(72, "c6");
    Client c7(5, "c7");
    Client c8(15, "c8");
    Client c9(20, "c9");
    Client c10(91, "c10");
    Client c11(14, "c11");
    Client c12(61, "c12");
    Client c13(66, "c13");
    Client c14(41, "c14");
    Client c15(81, "c15");
    Client c16(88, "c16");
    Client c17(16, "c17");
    Client c18(21, "c18");
    Client c19(34, "c19");
    Client c20(90, "c20");

    /*Client c1(1, "c1");
    Client c2(2, "c2");
    Client c3(3, "c3");
    Client c4(4, "c4");*/

    StaticList l1;

    l1.addList(0, c1);
    l1.addList(1, c2);
    l1.addList(2, c3);
    l1.addList(3, c4);
    l1.addList(4, c5);
    l1.addList(5, c6);
    l1.addList(6, c7);
    l1.addList(7, c8);
    l1.addList(8, c9);
    l1.addList(9, c10);
    l1.addList(10, c11);
    l1.addList(11, c12);
    l1.addList(12, c13);
    l1.addList(13, c14);
    l1.addList(14, c15);
    l1.addList(15, c16);
    l1.addList(16, c17);
    l1.addList(17, c18);
    l1.addList(18, c19);
    l1.addList(19, c20);

    /*l1.addList(0, c4);
    l1.addList(1, c1);
    l1.addList(2, c3);
    l1.addList(3, c2);*/
    
    l1.printList();

    cout << endl;
    
    l1.otmBubbleSort(1);

    cout << endl;
    
    l1.printList();
    
    l1.~StaticList();

    return 0;
}