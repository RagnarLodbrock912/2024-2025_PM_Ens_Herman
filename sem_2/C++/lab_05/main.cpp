#include <iostream>
#include "Vector.hpp"

using namespace std;

int main() {
    Vector<int> vec1(5, 10);
    cout << "Initial vector (size 5, value 10): " << vec1 << endl;

    vec1.push_back(20);
    cout << "After push_back(20): " << vec1 << endl;

    vec1.insert(2, 15);
    cout << "After insert(2, 15): " << vec1 << endl;

    vec1.erase(3);
    cout << "After erase(3): " << vec1 << endl;

    vec1.resize(8);
    cout << "After resize(8): " << vec1 << endl;

    vec1.resize(3);
    cout << "After resize(3): " << vec1 << endl;

    cout << "Is vector empty? " << (vec1.empty() ? "Yes" : "No") << endl;

    vec1.reverse();
    cout << "After reverse(): " << vec1 << endl;


    cout << "First element: " << *vec1.front() << endl;
    cout << "Last element: " << *vec1.back() << endl;

    try {
        cout << "Element at index 1: " << vec1[1] << endl;
        cout << "Element at index 5 (invalid): " << vec1[5] << endl; 
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    Vector<int> vec2 = vec1;
    cout << "Copy of vec1 (vec2): " << vec2 << endl;

    vec2[2] = 8;
    cout << "After assignment, vec1: " << vec1 << endl;
    cout << "After assignment, vec2: " << vec2 << endl;

    return 0;
}
