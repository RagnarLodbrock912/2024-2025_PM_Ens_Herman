#include <iostream>
#include <cmath>
#include <bigint.hpp>

using namespace std;

int main() {
    BigInt a("10");
    BigInt b("-9");
    cout << (a + b) << endl;  
    // Ожидаемый вывод: 1

    BigInt c("-100");
    BigInt d("99");
    cout << (c + d) << endl;  
    // Ожидаемый вывод: -1

    BigInt e("987654321987654321987654321");
    BigInt f("123456789123456789123456789");
    cout << (e + f) << endl;  
    // Ожидаемый вывод: 1111111111111111111111111110

    BigInt g("-987654321987654321987654321");
    BigInt h("-123456789123456789123456789");
    cout << (g + h) << endl;  
    // Ожидаемый вывод: -1111111111111111111111111110

    BigInt i("500000000000000000000000000000");
    BigInt j("500000000000000000000000000000");
    cout << (i + j) << endl;  
    // Ожидаемый вывод: 1000000000000000000000000000000

    BigInt k("-500000000000000000000000000000");
    BigInt l("500000000000000000000000000000");
    cout << (k + l) << endl;  
    // Ожидаемый вывод: 0

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    BigInt sum = a + b;
    cout << "a + b = " << sum << endl;

    a += b;
    cout << "a += b, now a = " << a << endl;

    BigInt mul = a * BigInt("2");
    cout << "a * 2 = " << mul << endl;

    a *= BigInt("2");
    cout << "a *= 2, now a = " << a << endl;

    cout << "a > b? " << (a > b) << endl;
    cout << "a < b? " << (a < b) << endl;
    cout << "a == b? " << (a == b) << endl;

    BigInt input;
    cout << "Enter a BigInt: ";
    cin >> input;
    cout << "You entered: " << input << endl;
    return 0;
}