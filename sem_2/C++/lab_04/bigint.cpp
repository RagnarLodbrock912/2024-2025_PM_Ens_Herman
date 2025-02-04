#include<bigint.hpp> 

string cut (string num) {
    size_t firstNonZero = num.find_first_not_of('0');
    
    if (firstNonZero == string::npos)
        return "0";

    return num.substr(firstNonZero);
}

bool compare (string s1, string s2) {
    if (s1.length() == s2.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                return s1[i] > s2[i];
            }
        }
        return false;
    } else {
        return s1.length() > s2.length();
    }
}

BigInt::BigInt() {
    number = "0";
    sign = 1;
}

BigInt::BigInt(string s) {
    if (!regex_match(s, regex("-?[0-9]+"))) {
        throw invalid_argument("Error");
    }
    
    sign = (s[0] == '-') ? -1 : 1;
    number = cut((s[0] == '-') ? s.substr(1) : s);
    
    if (number.empty()) {
        number = "0";
        sign = 1;
    }
}


BigInt& BigInt::operator=(const BigInt& other) {
    if (this == &other) return *this;
    number = other.number;
    sign = other.sign;
    return *this;
}

BigInt BigInt::operator+(const BigInt& other) const {
    BigInt res;
    int len = max(number.length(), other.number.length());
    string num, answ = "", num1 = number, num2 = other.number;
    int first, second, prev = 0, sign1 = sign, sign2 = other.sign;
    if (sign == -1 && other.sign == -1) {
        res.sign = -1;
        sign1 = 1;
        sign2 = 1;
    }
    if (sign == -1 && other.sign == 1 && compare(number, other.number)) {
        res.sign = -1;
        sign1 *= -1;
        sign2 *= -1;
    }
    for (int i = 1; i < len + 1; i++) {
        int a = num1.length();
        first = (num1.length()  >=  i) ? (num1[num1.length() - i] - 48) : 0;
        second = (num2.length() >= i)  ? (num2[num2.length() - i] - 48) : 0;
        first = (first == '/') ? -1 : first;
        second = (second == '/') ? -1 : second;
        num = to_string(first * sign1 + second * sign2 + prev);
        prev = 0;
        if (num[0] == '-') {
            if (sign1 == 1) {
                if (num1.length() >= i + 1) {
                    num1[num1.length() - i - 1] = num1[num1.length() - i - 1] - 1;
                }
            } else {
                if (num2.length() >= i + 1) {
                    num2[num2.length() - i - 1] = num2[num2.length() - i - 1] - 1;
                } 
            }
            num = to_string(10 + stoi(num));
        } else if (num.length() == 2) {
            prev = 1;
            num = num[1];
        }
        answ = num + answ;
    }
    if (prev != 0) answ = to_string(prev) + answ;
    res.number = cut(answ); 
    return res;
}

BigInt& BigInt::operator+=(const BigInt& other) {
    *this = *this + other;
    return *this;
}

BigInt BigInt::operator*(const BigInt& other) const {
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
    res.sign = sign * other.sign;
    return res;
}

BigInt& BigInt::operator*=(const BigInt& other) {
    *this = *this * other;
    return *this;
}

bool BigInt::operator==(const BigInt& other) const {
    return (number == other.number) && (sign == other.sign);
}

bool BigInt::operator!=(const BigInt& other) const {
    return (number != other.number) || (sign != other.sign);
}

bool BigInt::operator>(const BigInt& other) const {
    if (sign != other.sign) {
        return (sign == -1) ? false : true;
    } else {
        if (sign == -1) {
            if (number.length() == other.number.length()) {
                for (int i = 0; i < number.length(); i++) {
                    if (number[i] != other.number[i]) {
                        return number[i] < other.number[i];
                    }
                }
                return false;
            } else {
                return number.length() < other.number.length();
            }
        } else {
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
    }
}

bool BigInt::operator<(const BigInt& other) const {
    if (*this == other || *this > other) {
        return false;
    } else {
        return true;
    }
}


ostream& operator<<(ostream& out, const BigInt& num) {
    if (num.sign == -1) {
        out << "-";
    }
    out << num.number;
    return out;
}

istream& operator>>(istream& in, BigInt& num) {
    string input;
    in >> input;

    if (!regex_match(input, regex("-?[0-9]+"))) {
        throw invalid_argument("Error");
    }

    num.sign = (input[0] == '-') ? -1 : 1;
            num.number = cut((input[0] == '-') ? input.substr(1) : input);
            
            if (num.number.empty()) {
                num.number = "0";
                num.sign = 1;
            }

        return in;
    }