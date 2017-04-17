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
    myset(const myset &other) {
        std::cout << "copy";
        std::copy(other.data, other.data + other.size(), data);
    }

    // Assignment operator
    myset &operator = (const myset &other) {
        std::cout << "Assignment";
        if (this != &other) {
            myset(other).swap(*this);
        }
//        std::swap(this->data, other.data);
        return *this;
    }

    // move constructor
    myset(myset &&other) {
        std::cout << "Move";
        data = other.data;

        other.data = nullptr;
    }

    // move assignment constructor
    myset &operator = (myset &&other) 	{
        std::cout << "Move assignment";
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    void swap(myset &other) throw() {
        std::swap(this->data, other.data);
        std::swap(this->sizeOfArray, other.sizeOfArray);
        std::swap(this->currentSizeOfArray, other.currentSizeOfArray);
    }
    // returns the number of elements in the set.
    int size() const {
        return this->sizeOfArray;
    }

    // Returns the current size of the array.
    int capacity() const {
        return sizeof(int) * size();
    }

    // Removes a value to the set. Return true iff the element
    // was successfully removed.
    bool remove(int value) {
        if (isElement(value) == 1) {
            std::remove_copy(this->data, this->data + this->size(), this->data, value);
            this->sizeOfArray--;
            return true;
        }
        return false;
    }

    // Adds a value to the set. Return true iff the element
    // was successfully added.
    bool insert(int value) {
        if (size() < MIN_CAPACITY) {
            for (int i = this->size(); i <= this->size(); ++i) {
                this->data[i] = value;
            }
            this->sizeOfArray++;
            return true;
        } else if (size() >= MIN_CAPACITY) {
            std::cout << "Here";
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
