#include <iostream>
using namespace std;

int countMultOfNumb (int n) {
    int res = 1;
    int length = to_string(n).length();
    for (int i = 0; i < length; i ++) {
        int a = n % 10;
        res = res * a;
        n = (n - a) / 10;
    }
    return res;
}

int main() {
    cout << "To stop enter queue, enter 0" << endl;
    int i, j;
    int max = -2147483648;
    int m = 0;
    int S = 0;
    while(cin >> i) {
        if (i < 0 && i % 7 == 0) {
            S = S + i;
            j = i > max ? m : j;
            max = max < i ? i : max;  
        }
        if (i == 0) {
            cout << "Sum is equal " << S << endl;
            cout << "Max value is " << max << endl;
            cout << "Index of max value is " << j << endl;
            break;
        }
        m++;
    }

    int n;
    cout << "Enter n ";
    cin >> n;
    cout << countMultOfNumb(n);
    return 0;
}
