#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

using namespace std;

int nextPowerOfTwo(int n) {
    if (n <= 0) return 1; 
    return pow(2, ceil(log2(n)));
}

template <typename vec>
class Vector
{
private:
    vec* arr;
    size_t len;
    size_t cap;
public:
    Vector() : arr(nullptr), len(0) {}

    Vector(int n, vec val = vec()) {
        len = n;
        cap = nextPowerOfTwo(n);
        arr = new vec[cap];

        for (int i = 0; i < len; i++) {
            arr[i] = val;
        }
    }

    Vector(const Vector& other) {
        len = other.len;
        cap = other.cap;
        arr = new vec[cap];
        for (int i = 0; i < len; i++) {
            arr[i] = other.arr[i];
        }
    }

    size_t size() {
        return len;
    }

    size_t capacity() {
        return cap;
    }
    
    ~Vector() {
        delete [] arr;
    }

    Vector& resize(size_t n) {
        if (n <= cap) {
            len = n;
            return *this;
        }

        vec* newArr = new vec[nextPowerOfTwo(n)];
        size_t minLen = min(len, n);

        for (int i = 0; i < minLen; i++) {
            newArr[i] = arr[i];
        }

        delete [] arr;

        len = n;
        cap = nextPowerOfTwo(n);
        arr = newArr;
        return *this;
    }

    Vector& reserve(size_t n) {
        if (n <= cap) return *this;

        vec* newArr = new vec[n];
        size_t minLen = min(len, n);

        for (int i = 0; i < minLen; i++) {
            newArr[i] = arr[i];
        }

        delete [] arr;

        len = minLen;
        cap = n;
        arr = newArr;
        return *this;
    }

    Vector& shrink_to_fit() {
        if (len == cap) return *this;
        vec* newArr = new vec[len];

        for (int i = 0; i < len; i++) {
            newArr[i] = arr[i];
        }

        delete [] arr;

        cap = len;
        arr = newArr;
        return *this;
    }


    Vector& reverse() {
        for (int i = 0; i < len / 2; i++) {
            vec tmp = arr[i];
            arr[i] = arr[len - 1 - i];
            arr[len - 1 - i] = tmp;
        }
        return *this;
    }

    vec* front() {
        return &arr[0];
    }

    vec* back() {
        return &arr[len - 1];
    }

    vec* begin() {
        return &arr[0];
    }

    vec* end() {
        return &arr[len];
    }

    bool empty() {
        if (len == 0) return true;
        return false;
    }


    Vector& push_back(vec el) {
        if (len + 1 > cap) this->reserve(len + 1);
        arr[len] = el;
        len++;
        return *this;
    }

    Vector& insert(size_t index, vec el) {
        if (index < 0 || index >= len + 1) {
            throw out_of_range("Index out of range");
        }
        if (len + 1 > cap) this->reserve(len + 1);
        for (int i = len; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = el;
        len++;
        return *this;
    }

    Vector& erase(size_t index) {
        if (index < 0 || index >= len) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < len; i++) {
            arr[i] = arr[i + 1];
        }
        len = len - 1;
        return *this;

    }

    vec& operator[](size_t i) const {
        if (i < 0 || i >= len) {
            throw out_of_range("Index out of range");
        }
        return arr[i];
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            len = other.len;
            arr = new vec[len];
            for (int i = 0; i < len; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Vector& array) {
        for (int i = 0; i < array.len; i++) {
            out << array.arr[i] << " ";
        }
        return out;
    }

    friend istream& operator>>(istream& in, const Vector& array) {
        for (int i = 0; i < array.len; i++) {
            in >> array.arr[i];
        }
        return in;
    }
};

#endif