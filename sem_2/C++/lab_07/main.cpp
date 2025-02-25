#include <iostream>
#include <vector.hpp>
#include <cstdint>

using namespace std;

class VectorBool {
private:
    Vector<uint64_t> bits;
    size_t len;

    void set_bit(size_t bit_index) {
        bits[bit_index / 64] |= (1ULL << (bit_index % 64));
    }

    void clear_bit(size_t bit_index) {
        bits[bit_index / 64] &= ~(1ULL << (bit_index % 64));
    }

    bool get_bit(size_t bit_index) const {
        return (bits[bit_index / 64] >> (bit_index % 64)) & 1;
    }
public:
    VectorBool() : len(0) {}

    bool operator[](size_t index) const {
        if (index >= len) throw out_of_range("Index out of range");
        return get_bit(index);
    }

    void set(size_t index, bool value) {
        if (index >= len) throw out_of_range("Index out of range");
        if (value) {
            set_bit(index);
        } else {
            clear_bit(index);
        }
    }

    void push_back(bool value) {
        if (len % 64 == 0) {
            bits.push_back(0);
        }
        if (value) {
            set_bit(len);
        }
        len++;
    }

    void insert(size_t index, bool value) {
        if (index >= len) throw out_of_range("Index out of range");
        push_back(false);
        for (int i = len - 1; i > index; i--) {
            bool tmp = (*this)[i - 1];
            set(i, tmp);
        }
        set(index, value);  

    }

    void erase(size_t index) {
        if (index >= len) throw out_of_range("Index out of range");
        for (int i = index; i < len - 1; i++) {
            bool tmp = (*this)[i + 1];
            set(i, tmp);
        }
        len--;

    }

    size_t size() const {
        return len;
    }
};

int main() {
    VectorBool v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);

    cout << "Size: " << v.size() << endl;

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.set(2, false);

    cout << "After changing index 2 to false: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.insert(2, true);

    cout << "After inserting true at index 2: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    v.erase(1);

    cout << "After erasing index 1: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
