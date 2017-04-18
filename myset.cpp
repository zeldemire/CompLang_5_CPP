#include <iostream>
#include "myset.h"

int main(int argc, char *argv[]) {

//    int *a = new int[4];
//    a[0] = 4;
//    a[1] = 1;
//    a[2] = 2;
//    a[3] = 3;
//
//    int b[4];
//
//    std::copy(a, a + 4, std::begin(b));
//
//    delete[] a;
//    a = nullptr;
//
//    a = new int[6];
//
//    std::copy(std::begin(b), std::end(b), a);
//    for (int i = 0; i < 5; ++i) {
//        std::cout << a[i] << std::endl;
//    }
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

    test2.remove(0);
    test2.remove(4);
    myset test3 = test2;


    std::cout << test1.capacity() << std::endl;
    std::cout << sizeof(int) << std::endl;

//    for (int i = 0; i < test1.size(); ++i) {
//
//        std::cout << test1.data[i] << std::endl;
//    }
//
//    std::cout << std::endl;
//    std::cout << test1.size() << std::endl;
//    std::cout << std::endl;
//    test1.remove(9);
//
//    for (int i = 0; i < test1.size(); ++i) {
//
//        std::cout << test1.data[i] << std::endl;
//    }
//    std::cout << std::endl;
//    std::cout << test1.size() << std::endl;
//
//
//    test1.insert(100);
//
//    for (int i = 0; i < test1.size(); ++i) {
//
//        std::cout << test1.data[i] << std::endl;
//    }
//    std::cout << std::endl;
//    std::cout << test1.size() << std::endl;

    int a = 0;
}
