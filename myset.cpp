#include <iostream>
#include "myset.h"

int main(int argc, char *argv[]) {

    int *a = new int[4];
    a[0] = 4;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;

    int b[4];

    std::copy(a, a + 4, std::begin(b));

    delete[] a;
    a = nullptr;

    a = new int[6];

    std::copy(std::begin(b), std::end(b), a);
    for (int i = 0; i < 5; ++i) {
        std::cout << a[i] << std::endl;
    }
//    myset test1;
//    test1.insert(6);
//    myset test2;
//    myset test3(test1);
//    test2 = test1;
//    myset test3(test1);


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
}
