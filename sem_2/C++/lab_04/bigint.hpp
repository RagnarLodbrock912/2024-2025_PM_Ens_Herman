#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <regex>
#include <iostream>

using namespace std;

class BigInt {
private:
    string number;
    int sign;
public:
    BigInt();
    BigInt(string s);

    BigInt& operator=(const BigInt& other);
    BigInt operator+(const BigInt& other) const;
    BigInt& operator+=(const BigInt& other);
    BigInt operator*(const BigInt& other) const;
    BigInt& operator*=(const BigInt& other);

    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<(const BigInt& other) const;

    friend ostream& operator<<(ostream& out, const BigInt& num);
    friend istream& operator>>(istream& in, BigInt& num);
};

#endif

