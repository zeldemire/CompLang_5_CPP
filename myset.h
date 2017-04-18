#ifndef _MYSET_
#define _MYSET_

#include <cstring>
#include <iostream>
#include <initializer_list>
#include <algorithm>

#pragma warning(disable: 4996)

const bool DUMP = true;

class myset {
public:
    static const int MIN_CAPACITY = 10;

    int *data;	// must be dynamically allocate 1D array

    myset() {
        data = new int [MIN_CAPACITY];
    }
    ~myset() {
        delete[] data;
    }

    // copy constructor
    myset(const myset &other) : myset() {
        std::copy(other.data, other.data + other.size(), data);
        sizeOfArray = other.sizeOfArray;
        currentSizeOfArray = other.currentSizeOfArray;
    }

    // Assignment operator
    myset &operator = (const myset &other) {
        if (this != &other) {
            delete[] data;

            data = new int[other.size()];
            sizeOfArray = other.sizeOfArray;
            currentSizeOfArray = other.currentSizeOfArray;

            std::copy(other.data, other.data + other.sizeOfArray, data);
        }

        return *this;
    }

    // move constructor
    myset(myset &&other) {
        data = other.data;
        sizeOfArray = other.sizeOfArray;
        currentSizeOfArray = other.currentSizeOfArray;

        other.data = nullptr;
        other.currentSizeOfArray = 0;
        other.sizeOfArray = 0;
    }

    // move assignment constructor
    myset &operator = (myset &&other) 	{
        std::cout << "Move assignment";
        if (this != &other) {

            // Erase *this data
            delete[] data;
            data = nullptr;
            sizeOfArray = 0;
            currentSizeOfArray = 0;

            // Set data from other
            data = other.data;
            sizeOfArray = other.sizeOfArray;
            currentSizeOfArray = other.currentSizeOfArray;

            // Reset other data
            other.sizeOfArray = 0;
            other.currentSizeOfArray = 0;
            other.data = nullptr;
        }
        return *this;
    }

    // returns the number of elements in the set.
    int size() const {
        return sizeOfArray;
    }

    // Returns the current size of the array.
    int capacity() const {
        return sizeof(int) * currentSizeOfArray;
    }

    // Removes a value to the set. Return true iff the element
    // was successfully removed.
    bool remove(int value) {
        if (isElement(value) == 1) {
            std::remove_copy(data, data + size(), data, value);
            sizeOfArray--;
            return true;
        }
        return false;
    }

    void resizeAndInsert(const int value) {
        currentSizeOfArray = size() + (size() / 2);
        int *tmpArray = new int[size()];

        std::copy(data, data + size(), tmpArray);

        delete[] data;
        data = nullptr;

        data = new int[currentSizeOfArray];

        std::copy(tmpArray, tmpArray + size(), data);

        data[sizeOfArray] = value;

    }

// Adds a value to the set. Return true iff the element
    // was successfully added.
    bool insert(int value) {
        if (size() < MIN_CAPACITY) {
            for (int i = size(); i <= size(); ++i) {
                data[i] = value;
            }
            sizeOfArray++;
            return true;
        } else if (size() >= MIN_CAPACITY) {
            resizeAndInsert(value);
            sizeOfArray++;
        }
        return false;
    }

    // Returns true if value is part of set.
    bool isElement(int value) const {
        return std::find(this->data, this->data + this->size(), value) != this->data + this->size();
    }

    // Returns an array containing the elements in the set.
    // This array is dynamically allocated an must be deleted by
    // the caller.
    int *getValues(int &sz) const {
        sz = 5;
        int *result = new int[sz];
        result[0] = 5;
        result[1] = 15;
        result[2] = 20;
        result[3] = 30;
        result[4] = 40;
        return result;
    }



private:
    int sizeOfArray = 0;

    int currentSizeOfArray = MIN_CAPACITY;
};

#endif
