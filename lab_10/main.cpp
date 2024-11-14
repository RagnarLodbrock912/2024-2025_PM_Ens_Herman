#include <iostream>
#include <list.hpp>
#include <cmath>

using namespace std;

bool isPrime (int n) {
    if (n < 2) {
        return false;  
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

bool threeOddNum (int n) {
    int i = 0;
    for (; i < 3 && n > 0; i++) {
        if ((n % 10) % 2 != 1)
            return false;
        n /= 10;
    }
    if (n > 0 || i != 3) 
        return false;
    return true;
    
}

int firstDigit (int n) {
    while (n > 9) {
        n /= 10;
    }
    return n;
}

bool compare(int a, int b) {
    return firstDigit(a) < firstDigit(b);
}

bool hasDigit8 (int n) {
    while (n > 0) {
        if (n % 10 == 8)
            return true;
        n /= 10;
    }
    return false;
}

int main() {
    int n, a;
    bool flag = false;
    List arr;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if(!flag) {
            if(isPrime(a) && threeOddNum(a))
                flag = true;
        }
        arr.insert(i, a);
    }

    if (flag) {
        arr.sort(compare);
    } else {
        list* current = arr.getHead();
        int i = 0;
        while (current != nullptr) {
            if (hasDigit8(current->data)) {
                arr.pop(i);
                i--;
            } else {
                arr.insert(i, current->data);
                i++;
            }
            current = current->next;
            i++;
        }
    }

    arr.print();

    return 0;
}