#include <iostream>
#include "myset.h"

int main(int argc, char *argv[]) {

    myset test1;
    test1.insert(0);
    test1.insert(1);
    test1.insert(2);
    test1.insert(3);
    test1.insert(4);
    test1.insert(5);
    test1.insert(6);
    test1.insert(7);
    test1.insert(8);
    test1.insert(9);
    test1.insert(10);
    myset test2(test1);

    std::cout << "TEST 1" << std::endl;
    for (size_t i = 0; i < test1.size(); i++) {
        std::cout << test1.data[i];
    }

    std::cout << std::endl;

    myset test3 = test2;
    test2.remove(0);
    test2.remove(4);


    std::cout << "TEST 2" << std::endl;
    for (size_t i = 0; i < test2.size(); i++) {
        std::cout << test2.data[i];
    }
    std::cout << std::endl;
    std::cout << "TEST 3" << std::endl;
    test3.insert(55);
    for (size_t i = 0; i < test3.size(); i++) {
        std::cout << test3.data[i];
    }
    std::cout << std::endl;
    return 0;
}
