#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

using namespace std;

template <typename vec>
class Vector
{
private:
    vec* arr;
    size_t len;
    size_t cap;

    int nextPowerOfTwo(int n) {
        if (n <= 0) return 1; 
        return pow(2, ceil(log2(n)));
    }
public:
    Vector() : arr(nullptr), len(0), cap(0) {}

    Vector(int n, vec val = vec()) {
        len = n;
        cap = nextPowerOfTwo(n);
        arr = new vec[cap];

        for (size_t i = 0; i < len; i++) {
            arr[i] = val;
        }
    }

    Vector(const Vector& other) {
        len = other.len;
        cap = other.cap;
        arr = new vec[cap];
        for (size_t i = 0; i < len; i++) {
            arr[i] = other.arr[i];
        }
    }

    size_t size() const {
        return len;
    }

    size_t capacity() const {
        return cap;
    }

    ~Vector() {
        delete[] arr;
    }

    Vector& resize(size_t n) {
        if (n <= cap) {
            len = n;
            return *this;
        }

        vec* newArr = new vec[nextPowerOfTwo(n)];
        size_t minLen = min(len, n);

        for (size_t i = 0; i < minLen; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        len = n;
        cap = nextPowerOfTwo(n);
        return *this;
    }

    Vector& reserve(size_t n) {
        if (n <= cap) return *this;

        vec* newArr = new vec[nextPowerOfTwo(n)];
        size_t minLen = min(len, n);

        for (size_t i = 0; i < minLen; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        len = minLen;
        cap = nextPowerOfTwo(n);
        return *this;
    }

    Vector& shrink_to_fit() {
        if (len == cap) return *this;

        vec* newArr = new vec[len];
        for (size_t i = 0; i < len; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        cap = len;
        return *this;
    }

    Vector& reverse() {
        for (size_t i = 0; i < len / 2; i++) {
            swap(arr[i], arr[len - 1 - i]);
        }
        return *this;
    }

    vec* front() {
        return len > 0 ? &arr[0] : nullptr;
    }

    vec* back() {
        return len > 0 ? &arr[len - 1] : nullptr;
    }

    vec* begin() {
        return len > 0 ? &arr[0] : nullptr;
    }

    vec* end() {
        return len > 0 ? &arr[len] : nullptr;
    }

    bool empty() const {
        return len == 0;
    }

    Vector& push_back(const vec& el) {
        if (len + 1 > cap) this->reserve(nextPowerOfTwo(len + 1));
        arr[len++] = el;
        return *this;
    }

    Vector& insert(size_t index, const vec& el) {
        if (index > len) {
            throw out_of_range("Index out of range");
        }
        if (len + 1 > cap) this->reserve(nextPowerOfTwo(len + 1));
        
        for (size_t i = len; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = el;
        len++;
        return *this;
    }

    Vector& erase(size_t index) {
        if (index >= len) {
            throw out_of_range("Index out of range");
        }
        for (size_t i = index; i < len - 1; i++) {
            arr[i] = arr[i + 1];
        }
        len--;
        return *this;
    }

    vec& operator[](size_t i) {
        if (i >= len) {
            throw out_of_range("Index out of range");
        }
        return arr[i];
    }

    const vec& operator[](size_t i) const {
        if (i >= len) {
            throw out_of_range("Index out of range");
        }
        return arr[i];
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;

        delete[] arr;

        len = other.len;
        cap = other.cap;
        arr = new vec[cap];

        for (size_t i = 0; i < len; i++) {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    friend ostream& operator<<(ostream& out, const Vector& array) {
        for (size_t i = 0; i < array.len; i++) {
            out << array.arr[i] << " ";
        }
        return out;
    }
};

#endif