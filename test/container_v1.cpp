// Container implementation version 1

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t length;

public:
    DynamicArray() : data(nullptr), capacity(0), length(0) {}

    ~DynamicArray() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
    }

    void push_back(const T& value) {
        if (length >= capacity) {
            size_t new_capacity = capacity == 0 ? 8 : capacity * 2;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < length; i++) {
                new_data[i] = data[i];
            }
            if (data != nullptr) {
                delete[] data;
            }
            data = new_data;
            capacity = new_capacity;
        }
        data[length++] = value;
    }

    T& at(size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    size_t size() const {
        return length;
    }

    bool empty() const {
        return length == 0;
    }

    void clear() {
        length = 0;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + length;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= capacity) {
            return;
        }
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < length; i++) {
            new_data[i] = data[i];
        }
        if (data != nullptr) {
            delete[] data;
        }
        data = new_data;
        capacity = new_capacity;
    }
};
