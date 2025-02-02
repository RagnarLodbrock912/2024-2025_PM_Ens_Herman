#include <iostream>
#include <cmath>
#include <string>
#include <regex>

using namespace std;

string cut (string num) {
    size_t firstNonZero = num.find_first_not_of('0');
    
    if (firstNonZero == string::npos)
        return "0";

    return num.substr(firstNonZero);
}


class BigInt {
private:
    string number;
public:
    BigInt() {
        number = "0";
    }

    BigInt(string s) {
        if (!regex_match(s, regex("[0-9]+"))) {
            throw invalid_argument("Error");
        }

        number = cut(s);

        if (number.empty()) {
            number = "0";
        }
    }


    BigInt& operator=(const BigInt& other) {
        if (this == &other) return *this;
        number = other.number;
        return *this;
    }

    BigInt operator+(const BigInt& other) const {
        int len = max(number.length(), other.number.length());
        string num, answ = "";
        int first, second, prev = 0;
        for (int i = 1; i < len + 1; i++) {
            int a = number.length();
            first = (number[number.length() - i] - 48) > 0 ? (number[number.length() - i] - 48) : 0;
            second = (other.number[other.number.length() - i] - 48) > 0 ? (other.number[other.number.length() - i] - 48) : 0;
            num = to_string(first + second + prev);
            prev = 0;
            if (num.length() == 2) {
                prev = (int)(num[0] - 48);
                num = num[1];
            }
            answ = num + answ;
        }
        if (prev != 0) answ = to_string(prev) + answ;
        return BigInt(cut(answ));
    }

    BigInt& operator+=(const BigInt& other) {
        *this = *this + other;
        return *this;
    }

    BigInt operator*(const BigInt& other) const {
        string num, answ;
        BigInt res("0");
        int first, second, prev = 0;
        for (int i = 1; i < number.length()  + 1; i++) {
            answ = "";
            first = number[number.length() - i] - 48;
            for (int j = 1; j < other.number.length() + 1; j++) {
                second = other.number[other.number.length() - j] - 48;
                num = to_string(first * second + prev);
                prev = 0;
                if (num.length() == 2) {
                    prev = (int)(num[0] - 48);
                    num = num[1];
                }
                answ = num + answ;
            }
            if (prev != 0) answ = to_string(prev) + answ;
            prev = 0;
            for (int k = 1; k < i; k++) {
                answ += "0";
            }
            res += BigInt(cut(answ));
        }
        return res;
    }

    BigInt& operator*=(const BigInt& other) {
        *this = *this * other;
        return *this;
    }

    bool operator==(const BigInt& other) const {
        return number == other.number;
    }

    bool operator!=(const BigInt& other) const {
        return number != other.number;
    }

    bool operator>(const BigInt& other) const {
        if (number.length() == other.number.length()) {
            for (int i = 0; i < number.length(); i++) {
                if (number[i] != other.number[i]) {
                    return number[i] > other.number[i];
                }
            }
            return false;
        } else {
            return number.length() > other.number.length();
        }
    }

    bool operator<(const BigInt& other) const {
        if (*this == other || *this > other) {
            return false;
        } else {
            return true;
        }
    }


    friend ostream& operator<<(ostream& out, const BigInt& num) {
        out << num.number;
        return out;
    }


friend istream& operator>>(istream& in, BigInt& num) {
    string input;
    in >> input;

    if (!regex_match(input, regex("[0-9]+"))) {
        throw invalid_argument("Error");
    }

    num.number = input;

    num.number = cut(num.number);

    if (num.number.empty()) {
        num.number = "0";
    }

    return in;
}
};

int main() {
    BigInt a("12345678901234567890");
    BigInt b("98765432109876543210");

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