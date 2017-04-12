#include <iostream>
#include "myset.h"

int main(int argc, char *argv[]) {
    int Array[] = {3,6,29,5,11};
    int *overwrite_start = std::remove_if(std::begin(Array), std::end(Array), [](int n){ return n==29; });
    std::fill(overwrite_start, std::end(Array), -1);
//    std::cout << *overwrite_start;
    for (int i = 0; i < 5; ++i) {
        std::cout << Array[i];
    }
}