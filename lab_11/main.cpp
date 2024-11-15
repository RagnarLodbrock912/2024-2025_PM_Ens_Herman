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

int firstDigit (int n) {
    while (n > 9) {
        n /= 10;
    }
    return n;
}

bool compare(int a, int b) {
    return firstDigit(a) > firstDigit(b);
}

int main() {
    List arr;
    int n, a;
    bool isIncreace = true, isDecrease = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.insert(i, a);
    }

    list* head = arr.getHead();
    list* tail = arr.getTail();

    list* current = head->next;

    while (current->next != tail) {
        if (current->data < current->next->data)
            isDecrease = false;
        else
            isIncreace = false;
        current = current->next;
    }

    if (isIncreace || isDecrease) {
        current = head->next;

        int i = 0;
        while (current != tail) {
            if (isPrime(current->data)) {
                arr.pop(i);
                i--;
            }   
            else if ((current->data % 10) == 0) {
                arr.insert(i, current->data);
                i++;
            }
            i++;
            current = current->next;
        }
    } else {
        arr.sort(compare);
    }
 
    arr.print();
    return 0;
}