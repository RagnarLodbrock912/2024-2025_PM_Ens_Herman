#include <iostream>
#include <cmath>

using namespace std;

class Tetrahedron {
private:
    int edge;
public:
    Tetrahedron(int a) {
        edge = a;
    }
    float area()  {
        return sqrt(3) * pow(edge, 2);
    }
    float volume() {
        return pow(edge, 3) / (6 * sqrt(2));
    }
};

int main() {
    Tetrahedron a(10);
    Tetrahedron b(5);

    cout << a.area() << " " << a.volume() << endl;
    cout << b.area() << " " << b.volume() << endl;
    return 0;
}