#include <iostream>
using namespace std;

string month(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month number";
    }
}
int main() {

    int a, b, c;
    cout << "Enter a, b, c separated with space ";
    cin >> a >> b >> c;
    if (a < b && b > c) {
        cout << b + a - c;
    } else if (b % c == 0) {
        cout << b / c -b;
    } else {
        cout << a * b - c;
    }

    int n;
    cout << "\nEnter number of month ";
    cin >> n;
    cout << month(n);


    int x;
    cout << "\nEnter x ";
    cin >> x;
    if (x == -1 || x == 1) {
        cout << ((x == -1) ? "Negative number" : "Positive number");
    } else {
        cout << "x must be equal to -1 or 1";
    }
    return 0;
}
