// Container implementation version 2 - similar structure

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class ResizableVector {
private:
    T* elements;
    size_t cap;
    size_t len;

public:
    ResizableVector() : elements(nullptr), cap(0), len(0) {}

    ~ResizableVector() {
        if (elements != nullptr) {
            delete[] elements;
            elements = nullptr;
        }
    }

    void append(const T& value) {
        if (len >= cap) {
            size_t new_cap = cap == 0 ? 8 : cap * 2;
            T* new_elements = new T[new_cap];
            for (size_t i = 0; i < len; i++) {
                new_elements[i] = elements[i];
            }
            if (elements != nullptr) {
                delete[] elements;
            }
            elements = new_elements;
            cap = new_cap;
        }
        elements[len++] = value;
    }

    T& get(size_t index) {
        if (index >= len) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    const T& get(size_t index) const {
        if (index >= len) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    size_t count() const {
        return len;
    }

    bool is_empty() const {
        return len == 0;
    }

    void reset() {
        len = 0;
    }

    T* begin() {
        return elements;
    }

    T* end() {
        return elements + len;
    }

    void grow(size_t new_cap) {
        if (new_cap <= cap) {
            return;
        }
        T* new_elements = new T[new_cap];
        for (size_t i = 0; i < len; i++) {
            new_elements[i] = elements[i];
        }
        if (elements != nullptr) {
            delete[] elements;
        }
        elements = new_elements;
        cap = new_cap;
    }
};
