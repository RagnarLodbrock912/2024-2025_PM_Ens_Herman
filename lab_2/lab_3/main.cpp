#include <iostream>
using namespace std;

string binary(int n) {

    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    
    return binary;
}

int main() {
        int x, i;
        cout << "Enter x and i ";
        cin >> x >> i;
        if (binary(x).length() > i){
            cout <<  binary(x)[i];
        } else {
            cout << "i is bigger than amount of x`s bits";
        }
        
        return 0;
}
