#include <iostream>
#include <algorithm>
#include <iterator>
#include "myset.h"

int main(int argc, char *argv[]) {
    myset test1;
    myset test2;
    test2 = test1;
    test1.insert(2);

    std::cout << test1.data[0];
//    myset1.insert(21);
//    std::cout << myset1.isElement(2) << std::endl;
//    std::cout << myset1.capacity() << std::endl;
//    std::cout << myset1.size() << std::endl;
//    myset1.remove(21);
//    std::cout << myset1.size() << std::endl;
//
//    for (int i = 0; i < myset1.size(); ++i) {
//        std::cout << myset1.data[i] << std::endl;
//    }
    int a = 0;
}
