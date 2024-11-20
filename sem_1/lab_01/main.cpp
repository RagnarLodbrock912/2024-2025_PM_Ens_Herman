#include <iostream>
using namespace std;

int main() {
    cout    << "Data Type  : int\n"
            << "Size       : 4 bytes\n"
            << "Range      : -2*10^9 ; 2*10^9\n";
    int a = 5;
    int b = -3;

    cout << "A = 5, B = -3, A + B =" << a+b << "\n" << endl;

    cout    << "Data Type  : unsigned int\n"
            << "Size       : 4 bytes\n"
            << "Range      : 0 ; 4*10^9\n";

    unsigned int x = 2;
    unsigned int y = 10;

    cout << "X = 2, Y = 10, X * Y =" << x*y << "\n" << endl;

    cout    << "Data Type  : long long\n"
            << "Size       : 8 bytes\n"
            << "Range      : -9*10^18 ; 9*10^18\n";
    
    long long c = 10000000000000000;
    long long d = -10000000000000;

    cout << "C = 100000000000000, D = 10000000000000, C / D =" << c/d << "\n" << endl;

    cout    << "Data Type  : unsigned long long\n"
            << "Size       : 8 bytes\n"
            << "Range      : 0 ; 18*10^18\n";

    unsigned long long s = 1000000000000000000;
    unsigned long long t = 1000000000000000;

    cout << "S = 100000000000000, T = 10000000000000, S - T =" << s-t << "\n" << endl;

    cout    << "Data Type  : char\n"
            << "Size       : 1 byte\n"
            << "Range      : 0 ; 255\n";

    string f = "A";
    string l = "B";

    cout << "F = A, L = B, F + L =" << f+l << "\n" <<endl;

    cout    << "Data Type  : bool\n"
            << "Size       : 1 byte\n"
            << "Range      : true / false\n\n";

    bool flag = (a > b);
    cout << "Boolean result of (a > b): " << flag << "\n" << endl;

    cout    << "Data Type  : double\n"
            << "Size       : 8 bytes\n"
            << "Range      : 1.7E +/- 308 (15 digits)\n";

    double q = 12.555;
    double r = 13.867;

    cout << "Q = 12.555,  R = 13.867, Q + R =" << q+r << endl;

    return 0;
}
